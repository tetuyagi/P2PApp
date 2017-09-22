#ifndef AUDIO_H
#define AUDIO_H

#include <QAudioDeviceInfo>
#include <QAudioFormat>
#include <QAudioBuffer>
#include <QAudioInput>
#include <QAudioOutput>
#include <QAudioRecorder>
#include <QAudioEncoderSettings>
#include <QAudioDecoder>
#include <QFile>
#include <QUrl>
#include <QBuffer>
#include <QMediaPlayer>
#include <QDateTime>
#include <QtEndian>


class Audio : public QObject
{
    Q_OBJECT
public:
    explicit Audio(QObject* parent = Q_NULLPTR);
    ~Audio();

    static QByteArray encode(QByteArray data);
    static QByteArray decode(QByteArray data);

public slots:
    void play();
    void save();
    void stopPlay();
    void stopSave();

    void update();
    QByteArray getInputData();
    void setOutputData(QByteArray byteArray);

    QByteArray resetInputBuffer();
    void resetOutputBuffer(QByteArray byteArray);


    //void record();

private:
    QAudioInput *audioInput;
    QAudioOutput *audioOutput;
    //QAudioRecorder *audioRecorder;
    //QAudioDecoder *audioDecoder;
    //QMediaPlayer *mediaPlayer;
    //AudioInfo *audioInfo;

    void showDeviceInfo(QAudioDeviceInfo info);
    void showDeviceList();
    QString path;
    QFile file;
    int time;

    //QByteArray ba;
    QBuffer inputBuffer;
    QBuffer outputBuffer;
    const int interval;

    bool switchFlg;

private slots:
    void inputStateChangedHandler(QAudio::State state);
    void outputStateChangedHandler(QAudio::State state);

    void onDecoded();

signals:
    //void decoded();

};

#endif // AUDIO_H
