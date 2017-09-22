#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string.h>
#include <typeinfo>
#include <iostream>
#include <stdio.h>
using namespace std;

//AppData
MainWindow::AppData::AppData(QByteArray data, Type type, qint64 timeStamp){
    this->type = type;

    this->data = data;
    if(timeStamp == -1){
        this->timeStamp = QDateTime::currentMSecsSinceEpoch();
    }else{
        this->timeStamp = timeStamp;
    }

}

MainWindow::AppData::~AppData(){

}

MainWindow::AppData MainWindow::AppData::fromData(QByteArray byteArray){
    char* data = byteArray.data();
    int len = byteArray.length();

    int pos = 0;
    Type type = (Type)Utility::bytesToData<int>(data);
    pos += 4;

    qint64 timeStamp = Utility::bytesToData<qint64>(data, pos);
    pos += 8;

    char d[len - pos];

    for(int i=0; i<len - pos; ++i){
        d[i] = data[i + pos];
    }

    AppData appData(QByteArray(d, len - pos), type, timeStamp);

    return appData;
}

int MainWindow::AppData::headerSize(){
    return sizeof(type) + sizeof(timeStamp);
}

QByteArray MainWindow::AppData::toByteArray(){
    int len = data.length() + headerSize();
    char d[len];
    int pos = 0;
    Utility::dataToBytes<int>((int)type, d);
    pos += 4;
    Utility::dataToBytes<qint64>(timeStamp, d, pos);
    pos += 8;

    for(int i=0; i<len - pos; ++i){
        d[i + pos] = data[i];
    }

    return QByteArray(d, len);
}

QByteArray MainWindow::AppData::getData(){
    return data;
}




//MainWindow
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *sendButton = ui->sendButton;

    RudpServer *testServer = new RudpServer(4444);
    sessionServer = new RudpServer(3333);

    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendSignalEmitter()));
    connect(this, SIGNAL(sendRequest(QByteArray, qint16, QHostAddress)), sessionServer, SLOT(sendDatagram(QByteArray, qint16,QHostAddress)));

    connect(testServer, SIGNAL(receivedData(QByteArray)), this, SLOT(processReceivedData(QByteArray)));


    Camera *cameraView = ui->myViewfinder;
    QPushButton *captureImageButton = ui->captureImageButton;

    label1 = ui->label1;
    label2 = ui->label2;


    connect(captureImageButton, SIGNAL(clicked()), cameraView, SLOT(capture()));
    connect(cameraView, SIGNAL(imageCaptured(int,QImage)), this, SLOT(onImageCaptured(int,QImage)));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    int interval = 1000/30;
    timer->start(interval);



    QPushButton *playAudioButton = ui->playAudioButton;
    playAudioButton->setCheckable(true);
    //playAudioButton->setChecked(false);
    QPushButton *saveAudioButton = ui->saveAudioButton;
    saveAudioButton->setCheckable(true);
    //saveAudioButton->setChecked(true);

    audio = new Audio(this);
    audio1 = new Audio(this);
    audio2 = new Audio(this);
    connect(playAudioButton, SIGNAL(clicked(bool)), this, SLOT(onPlay(bool)));
    connect(saveAudioButton, SIGNAL(clicked(bool)), this, SLOT(onSave(bool)));

    audio1->save();
    audio2->play();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(){
    audioUpdate();
    //qDebug(TimeStamp);
    //qDebug("msec : %d", QDateTime::currentMSecsSinceEpoch());

    ui->myViewfinder->capture();
    sessionServer->update();
}

void MainWindow::audioUpdate(){
    /*
    if(switchFlg){
        audio1->stopPlay();
        audio1
    }else{

    }
    */
    //int startTime = QDateTime::currentMSecsSinceEpoch();
    //int elapse = 0;

    QByteArray inputData;
    inputData = audio1->resetInputBuffer();
    inputData = Audio::encode(inputData);

    AppData appData(inputData, AppData::AUDIO);
    emit sendRequest(appData.toByteArray(), 4444, QHostAddress(QString("127.0.0.1")));

    if(!audioQueue.isEmpty()){
        QByteArray outputData = audioQueue.dequeue();
        outputData = Audio::decode(outputData);
        audio2->resetOutputBuffer(outputData);
    }
    //audio2->resetOutputBuffer();
    //audio->resetOutputBuffer(outputData);

}

void MainWindow::sendSignalEmitter(){
    emit sendRequest(QByteArray(""), 4444, QHostAddress(QString("127.0.0.1")));
}

void MainWindow::onImageCaptured(int id, QImage image){
    //image = image.convertToFormat(QImage::Format_RGB888);
    QRect rect = label1->rect();

    //qDebug() << "format:" << image.format();
    float scale = 1/8.0;
    QImage img = image.transformed(QTransform::fromScale(scale, scale));
    int size = img.byteCount();
    //qDebug() << "size:" << size;

    QByteArray data1 = encodeImage(img, "PNG");
    //data1 = qCompress(data1);
    //qDebug() << "png size:" << data1.size();

    QPixmap pix = QPixmap::fromImage(img);
    QPixmap pix1 = pix.scaled(rect.width(), rect.height());

    label1->setPixmap(pix1);
/*
    for(int i=0; i<10; ++i){
        qDebug("send data[i] = %x",data1.data()[i]);
    }
    */
    AppData appData(data1, AppData::IMAGE);

    emit sendRequest(appData.toByteArray(), 4444, QHostAddress(QString("127.0.0.1")));

}

void MainWindow::showImage(QByteArray data){
    //qDebug("show image. data.length = %d", data.length());//. id) : %d", data->id);
/*
    for(int i=0; i<10; ++i){
        qDebug("received data[i] = %x",data.data()[i]);
    }
    */

    QImage image = decodeImage(data, "PNG");

    QRect rect = label2->rect();
    QPixmap pix = QPixmap::fromImage(image);

    pix = pix.scaled(rect.width(), rect.height());
    label2->setPixmap(pix);
}

QByteArray MainWindow::encodeImage(QImage image, const char *format){
    QByteArray ba;
    QBuffer buffer(&ba);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, format);

    //qDebug("buffer.buffer().length(), buffer.size() = %d, %d", buffer.buffer().length(), buffer.size());
    return buffer.buffer();

}

QImage MainWindow::decodeImage(QByteArray byteArray, const char *format){
    QImage image;
    image.loadFromData(byteArray, format);
    return image;
}

void MainWindow::onPlay(bool checked){
    //qDebug() << "checked :" << checked;
    if(!checked){
        audio->stopPlay();
    }else{
        audio->play();
    }
}

void MainWindow::onSave(bool checked){
    //qDebug() << "checked :" << checked;
    if(!checked){
        audio->stopSave();
    }else{
        audio->save();
    }
}

void MainWindow::processReceivedData(QByteArray byteArray){
    qDebug() << "data size = " << byteArray.length();
    AppData appData = AppData::fromData(byteArray);
    QByteArray data = appData.getData();

    switch(appData.type){
    case AppData::MESSAGE:

        break;

    case AppData::AUDIO:
        playSound(data);
        break;

    case AppData::IMAGE:
        showImage(data);
        break;


    default:
        qDebug("no such type");
        break;

    }

}

void MainWindow::playSound(QByteArray data){
    audioQueue.enqueue(data);
    //audio2->resetOutputBuffer(data);
}
