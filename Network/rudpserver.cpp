#include "rudpserver.h"

#include <QDebug>
#include <math.h>


class PartialData{
public:
    uchar id;
    int count;
    int maxCount;
    int dataLength;
    char *data;
    static const int HEADER_SIZE = 9;

    PartialData(QByteArray byteArray){
         char* d = byteArray.data();
         id = (uchar)d[0];
         count = Utility::bytesToData<int>(d, 1);
         maxCount = Utility::bytesToData<int>(d, 5);
         dataLength = byteArray.length() - HEADER_SIZE;

         data = new char[dataLength];
         for(int i=0; i<dataLength; ++i){
             data[i] = d[i + HEADER_SIZE];
         }
    }

    PartialData(char* data, int dataLength, int index, uchar id, int count, int maxCount){
        this->id = id;
        this->count = count;
        this->maxCount = maxCount;
        this->dataLength = dataLength;

        this->data = new char[dataLength];
        for(int i=0; i<dataLength; ++i){
            this->data[i] = data[index + i];
        }

        //qDebug("count : %d", count);
    }

    ~PartialData(){
        delete data;
    }


    QByteArray getAllData(){
        char d[dataLength + HEADER_SIZE];
        d[0] = id;
        Utility::dataToBytes<int>(count, d, 1);
        Utility::dataToBytes<int>(maxCount, d, 5);


        for(int i=0; i<dataLength; ++i){
            d[i+HEADER_SIZE] = data[i];
        }

        //int i = Utility::bytesToData<int>(d, 1);
        //qDebug("count = %d", i);
        return QByteArray(d, dataLength + HEADER_SIZE);
    }

};


//ReceivedData Class
RudpServer::ReceivedData::ReceivedData(uchar id, int maxCount){
    partialDatas = new QByteArray[maxCount];
    done = new bool[maxCount];
    int remainTime = 2000;
    deadline.setDeadline(remainTime);
    for(int i=0; i<maxCount; ++i){
        done[i] = false;
    }

    this->id = id;
    this->maxCount = maxCount;
}

RudpServer::ReceivedData::~ReceivedData(){
    delete partialDatas;
    delete done;
}

void RudpServer::ReceivedData::setPartialData(int count, QByteArray partialData){
    done[count] = true;
    partialDatas[count] = partialData;

    int c = 0;
    for(int i=0; i<maxCount; ++i){
        c += done[i]?1:0;
    }


    //qDebug() << "done count =" << c;
}

bool RudpServer::ReceivedData::isComplete(){
    for(int i=0; i<maxCount; ++i){
        if(!done[i]){
            return false;
        }
    }

    return true;
}

bool RudpServer::ReceivedData::isTimeout(){
    return !deadline.hasExpired();
}

QByteArray RudpServer::ReceivedData::getData(){
    int length = 0;
    for(int i=0; i<maxCount; ++i){
        length += partialDatas[i].length();
    }

    char data[length];

    int index = 0;
    for(int i=0; i<maxCount; ++i){
        int len = partialDatas[i].length();
        char* d = partialDatas[i].data();
        for(int j=0; j<len; ++j){
            data[index + j] = d[j];
        }

        index += len;
    }

    return QByteArray(data, length);
}


//RudpServer class
RudpServer::RudpServer(qint16 port, QHostAddress address, QObject *parent)
    :QObject(parent)
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(address, port);

    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagram()));

    id = 0;
}

RudpServer::~RudpServer(){
    delete udpSocket;
    for(int i=0; i<addressBuffers.keys().length(); ++i){
        Address address = addressBuffers.keys()[i];
        QMap<uchar, ReceivedData*> *map = addressBuffers.value(address);
        for(int j=0; j<map->keys().length(); ++j){
            uchar id = map->keys()[j];
            ReceivedData *data = map->value(id);
            delete data;
        }

        delete map;
    }
}

void RudpServer::update(){
    deleteTimeoutData();
}

void RudpServer::deleteTimeoutData(){
    QList<uchar> takeList;

    for(int i=0; i<addressBuffers.keys().length(); ++i){
        Address address = addressBuffers.keys()[i];
        QMap<uchar, ReceivedData*> *buffers = addressBuffers.value(address);

        for(int j=0; j<buffers->keys().length(); ++j){
            uchar key = buffers->keys()[j];
            ReceivedData *buf = buffers->value(key);
            if(buf->isTimeout()){
                takeList.push_back(key);
            }
        }

        for(int j=0; j<takeList.length(); ++j){
            ReceivedData *data = buffers->take(takeList[j]);
            delete data;
            qDebug("delete data");

        }

    }
}

void RudpServer::readPendingDatagram(){
    while(udpSocket->hasPendingDatagrams()){
        QNetworkDatagram datagram = udpSocket->receiveDatagram();
        processTheDatagram(datagram);
    }
}

void RudpServer::processTheDatagram(QNetworkDatagram datagram){
    QHostAddress host = datagram.senderAddress();
    qint16 port = datagram.senderPort();
    Address address(port, host);

    QByteArray byteArray = datagram.data();

    //parse data
    PartialData partialData(byteArray);

    int maxCount = partialData.maxCount;
    int count = partialData.count;
    uchar thisId = partialData.id;

    //make or select buffer for each address
    QMap<uchar, ReceivedData*> *buffers;

    if(addressBuffers.contains(address)){
        buffers = addressBuffers.value(address);
    }else{
        buffers = new QMap<uchar, ReceivedData*>();
        addressBuffers.insert(address, buffers);
    }

    //select or make buffer
    ReceivedData *buffer;
    if(buffers->contains(thisId)){
        //buffer 選択
        buffer = buffers->value(thisId);
    }else{
        //buffer 追加
        buffer = new ReceivedData(thisId, maxCount);
        buffers->insert(thisId, buffer);

        //qDebug("new buffers.size = %d", buffers.size());
    }

    //buffer更新
    buffer->setPartialData(count, QByteArray(partialData.data, partialData.dataLength));

    //check data is complete
    if(buffer->isComplete()){
        qDebug("received data from %s : %d", host.toString().toStdString().c_str(), port);

        emit receivedData(address, buffer->getData());

        buffers->take(thisId);
        //qDebug("end buffers.size = %d", buffers.size());
    }

}


void RudpServer::sendDatagram(QByteArray data, qint16 port, QHostAddress address){
   //分割

    int length = data.length();
    int maxCount = (length + UDP_MAX_BUFFER_SIZE-1)/UDP_MAX_BUFFER_SIZE;
    int pos = 0;

    //qDebug() << "length, count =" << length << "," << maxCount;

    char *bytes = data.data();

    for(int i=0; i<maxCount; ++i){
        int dataLen = (pos+UDP_MAX_BUFFER_SIZE < length)?UDP_MAX_BUFFER_SIZE:(length - pos);

        PartialData partialData(bytes, dataLen, pos, id, i, maxCount);

        //qDebug("send data. count = %d", i);
        qint64 res = udpSocket->writeDatagram(partialData.getAllData(), address, port);

        if(res == -1){
            qDebug() << udpSocket->error();
        }

        pos += dataLen;
    }

    //qDebug() << "sum:" << sum;

    id++;
    qDebug() << "send datagram to" << address.toString() << ":" << port;
}





