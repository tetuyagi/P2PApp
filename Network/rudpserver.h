#ifndef RUDPSERVER_H
#define RUDPSERVER_H


#include <QUdpSocket>
#include <QHostAddress>
#include <QNetworkDatagram>
#include <QMap>
#include <QDeadlineTimer>
#include <QUrl>

#include "utility.h"
#include "addressmap.h"



class RudpServer : public QObject
{
    Q_OBJECT
public:
    explicit RudpServer(qint16 port = 3333, QHostAddress address = QHostAddress::AnyIPv4, QObject *parent = Q_NULLPTR);
    ~RudpServer();

    class ReceivedData{
    public:
        ReceivedData(uchar id, int maxCount);
        ~ReceivedData();
        void setPartialData(int count, QByteArray partialData);
        bool isComplete();
        bool isTimeout();
        QByteArray getData();

        int maxCount;
        uchar id;

    private:
        QByteArray *partialDatas;
        bool *done;
        QDeadlineTimer deadline;

    };


    static const int UDP_MAX_BUFFER_SIZE = 1024;

public slots:
    void sendDatagram(QByteArray data, qint16 port, QHostAddress address);

    void update();

private:
    class UserData{
    public:
        QString userName;
    };

    QUdpSocket *udpSocket;
    AddressMap<QMap<uchar, ReceivedData*>*> addressBuffers;
    uchar id;

    void deleteTimeoutData();

private slots:
    void readPendingDatagram();
    void processTheDatagram(QNetworkDatagram datagram);

signals:
    void receivedData(Address address, QByteArray byteArray);
};


#endif // RUDPSERVER_H
