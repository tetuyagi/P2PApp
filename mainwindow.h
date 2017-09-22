#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QLabel>
#include <QTransform>
#include <QBuffer>
#include <QTimer>
#include <QDateTime>
#include <QQueue>
#include <QHostAddress>


#include "camera.h"
#include "rudpserver.h"
#include "audio.h"
#include "utility.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();

private:
    class AppData{
    public:
        enum Type{
            MESSAGE,
            AUDIO,
            IMAGE
        };
        //static const int HEADER_SIZE = 12;//int32 + int64
        static AppData fromData(QByteArray byteArray);

        AppData(QByteArray data, Type type, qint64 timeStamp=-1);
        ~AppData();

        Type type;
        qint64 timeStamp;


        QByteArray toByteArray();
        QByteArray getData();

    private:
        QByteArray data;
        //int m_headerSize;
        int headerSize();

    };

    Ui::MainWindow *ui;
    QGraphicsView *graphicsView;
    QGraphicsScene *graphicsScene;
    QLabel *label1;
    QLabel *label2;

    QList<QByteArray> imageBuffers;

    RudpServer *sessionServer;
    Audio *audio;
    Audio *audio1;
    Audio *audio2;
    QQueue<QByteArray> audioQueue;
    int count;

    void audioUpdate();

    QTimer *timer;

private slots:
    //void send(qint16 port, QHostAddress address);
    void sendSignalEmitter();
    void onImageCaptured(int id, QImage image);
    void showImage(QByteArray data);
    void playSound(QByteArray data);
    void processReceivedData(QByteArray byteArray);

    QByteArray encodeImage(QImage image, const char* format);
    QImage decodeImage(QByteArray byteArray, const char* format);
    void update();

    void onPlay(bool checked);
    void onSave(bool checked);

signals:
    void sendRequest(QByteArray data, qint16 port, QHostAddress address);
};

#endif // MAINWINDOW_H
