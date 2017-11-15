#include "audio.h"
#include <QDebug>


Audio::Audio(QObject* parent):QObject(parent), interval(2000)
{
    path = "/Users/tyagi/Desktop/test.raw";

    switchFlg = false;
    //file.setFileName("/Users/tyagi/Desktop/test.wav");
    //file.open(QIODevice::ReadOnly);


    QAudioFormat format;
    format.setSampleRate(44100);
    format.setChannelCount(2);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    QAudioDeviceInfo outputInfo = QAudioDeviceInfo::defaultOutputDevice();

    if(!outputInfo.isFormatSupported(format)){
        qWarning("this format is not supported");
        return;
    }

    qreal volume = 1.0;

    audioOutput = new QAudioOutput(outputInfo, format, this);
    connect(audioOutput, SIGNAL(stateChanged(QAudio::State)), this, SLOT(outputStateChangedHandler(QAudio::State)));
    audioOutput->setVolume(volume);

    QAudioDeviceInfo inputInfo = QAudioDeviceInfo::defaultInputDevice();
    //showDeviceInfo(inputInfo);
    audioInput = new QAudioInput(inputInfo, format, this);
    audioInput->setVolume(volume);
    connect(audioInput, SIGNAL(stateChanged(QAudio::State)), this, SLOT(inputStateChangedHandler(QAudio::State)));



    //audioRecorder = new QAudioRecorder(this);

    /*
    QAudioEncoderSettings encodeSettings;
    encodeSettings.setCodec("audio/mpeg");
    encodeSettings.setQuality(QMultimedia::HighQuality);
    encodeSettings.setChannelCount(2);
    encodeSettings.setSampleRate(44100);
    */

    //qDebug() << "codec :" <<encodeSettings.codec();

    QString localFile = "/Users/tyagi/Desktop/TestWav.wav";

    /*
    audioRecorder->setAudioSettings(encodeSettings);
    audioRecorder->setOutputLocation(QUrl::fromLocalFile(localFile));

    QString selectedInput = audioRecorder->defaultAudioInput();
    audioRecorder->setAudioInput(selectedInput);

    time = QDateTime.currentMSecsSinceEpoch();
    //audioRecorder->record();
    */

    /*
    audioInfo = new AudioInfo(format, this);


    mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setMedia(QUrl::fromLocalFile(localFile));
    mediaPlayer->setVolume(100);
    //mediaPlayer->play();
*/

    //io.setBuffer(&ba);

    /*
    QString mimeType("audio/wav");
    QStringList codecs;
    codecs.append(QString("audio/wav"));
    codecs.append(QString("audio/ogg"));
    QMultimedia::SupportEstimate supportEstimate = QAudioDecoder::hasSupport(mimeType);
    qDebug() <<"suppot estimate :" << supportEstimate;
    */




    //audioDecoder = new QAudioDecoder(this);
    /*
    audioDecoder->setSourceFilename(localFile);
    audioDecoder->setAudioFormat(format);
    audioDecoder->start();
    connect(audioDecoder, SIGNAL(finished()), this, SLOT(onDecoded()));
*/

    qDebug("audio initialzed");
}

Audio::~Audio(){
    /*
    if(file.isOpen()){
        file.close();
    }
    */
    delete audioInput;
    delete audioOutput;
}

void Audio::outputStateChangedHandler(QAudio::State state){
    return;
    qDebug() << "audio output state changed :" << state;
}

void Audio::inputStateChangedHandler(QAudio::State state){
    return;
    qDebug() << "audio input state changed :" << state;
}

void Audio::stopSave(){
    qDebug() << "stop save";
    qint64 startTime = QDateTime::currentMSecsSinceEpoch();
    audioInput->stop();
    qDebug() << "input stop :" << (QDateTime::currentMSecsSinceEpoch() - startTime);
    inputBuffer.close();
    qDebug() << "data size :" << inputBuffer.data().length();

}

void Audio::stopPlay(){
    qDebug("stop play");
    qint64 startTime = QDateTime::currentMSecsSinceEpoch();
    audioOutput->stop();
    qDebug() << "output stop :" << (QDateTime::currentMSecsSinceEpoch() - startTime);
    outputBuffer.close();

}

void Audio::play(){
    outputBuffer.open(QIODevice::ReadOnly);
    audioOutput->start(&outputBuffer);
}

void Audio::save(){
    inputBuffer.open(QIODevice::WriteOnly);
    audioInput->start(&inputBuffer);
}

void Audio::showDeviceInfo(QAudioDeviceInfo info){
    QStringList codecList = info.supportedCodecs();
    QList<int> channelList = info.supportedChannelCounts();
    QList<int> rateList = info.supportedSampleRates();
    QList<int> sizeList = info.supportedSampleSizes();
    QList<QAudioFormat::SampleType> typeList = info.supportedSampleTypes();
    QList<QAudioFormat::Endian> endianList = info.supportedByteOrders();

    qDebug() << "device name :" << info.deviceName();
    qDebug() << "supported codecs :" << codecList;
    qDebug() << "supported channel :" << channelList;
    qDebug() << "supported rate :" << rateList;
    qDebug() << "supported size :" << sizeList;
    qDebug() << "supported type :" << typeList;
    qDebug() << "supported endian :" << endianList;

}

void Audio::showDeviceList(){
    QList<QAudioDeviceInfo> inputDeviceList = QAudioDeviceInfo::availableDevices(QAudio::AudioOutput);
    QList<QAudioDeviceInfo> outputDeviceList = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);

    foreach(QAudioDeviceInfo info, inputDeviceList){
        qDebug() << "input device name :" << info.deviceName();
    }

    foreach(QAudioDeviceInfo info, outputDeviceList){
        qDebug() << "input device name :" << info.deviceName();
    }
}

QByteArray Audio::decode(QByteArray data){
    data = qUncompress(data);
    return data;
}

QByteArray Audio::encode(QByteArray data){
    int size = data.length();
    data = qCompress(data);
    qDebug() << "compressed size =" << data.length() << " from" << size;
    return data;
}

void Audio::onDecoded(){
    /*
    QAudioBuffer buffer = audioDecoder->read();
    QByteArray ba((char* )buffer.data(), buffer.byteCount());
    QBuffer io(&ba);

    qDebug("play wav");
    //if(audioOutput->state == QAudio::State::)
    audioOutput->start(&io);
    */
}

void Audio::update(){
/*
   if(QDateTime::currentMSecsSinceEpoch() - time < interval){
       return;
   }

   time = QDateTime::currentMSecsSinceEpoch();



    qint64 startTime = QDateTime::currentMSecsSinceEpoch();

    QByteArray ba = getInputData();

    inputBuffer.close();
    inputBuffer.open(QIODevice::WriteOnly);

    //QByteArray ba1;
    //inputBuffer.setBuffer(&ba1);
    //inputBuffer.setData(QByteArray());

    qDebug() << "reset time :" << QDateTime::currentMSecsSinceEpoch() - startTime;
    qDebug() << "input data size :" << ba.length();
*/
}

QByteArray Audio::getInputData(){
    return inputBuffer.data();
}

void Audio::setOutputData(QByteArray byteArray){
    outputBuffer.setData(byteArray);
}

QByteArray Audio::resetInputBuffer(){
    inputBuffer.close();
    QByteArray byteArray = inputBuffer.data();
    inputBuffer.open(QIODevice::WriteOnly);

    return byteArray;
}

void Audio::resetOutputBuffer(QByteArray byteArray){
    outputBuffer.close();
    outputBuffer.setData(byteArray);
    outputBuffer.open(QIODevice::ReadOnly);
}
