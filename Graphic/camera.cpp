#include "camera.h"

#include <QDebug>

Camera::Camera(QWidget *parent):QCameraViewfinder(parent)
{
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    foreach(const QCameraInfo &cameraInfo, cameras){
        qDebug() << "cameraInfo.deviceName :" << cameraInfo.deviceName();
    }

    if(cameras.length() > 0){
        camera = new QCamera(cameras[0]);
        camera->setViewfinder(this);
        this->show();

        imageCapture = new QCameraImageCapture(camera);
        imageCapture->setCaptureDestination(QCameraImageCapture::CaptureDestination::CaptureToBuffer);
        imageCapture->setBufferFormat(QVideoFrame::Format_RGB24);

        camera->start();

        connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(onImageCaptured(int, QImage)));

        connect(camera, SIGNAL(statusChanged(QCamera::Status)), this, SLOT(onCameraStatusChanged(QCamera::Status)));
    }

}

void Camera::onImageCaptured(int id, QImage image){
    qDebug() << "image captured";
    emit imageCaptured(id, image);

}

int Camera::capture(){
    if(!imageCapture->isReadyForCapture()){
        qDebug("not ready for capture");
        return -1;
    }

    int id = imageCapture->capture();

    if(imageCapture->error() != QCameraImageCapture::NoError){
        qDebug("error : %d", imageCapture->error());
        return -1;
    }

    return id;
}

void Camera::onCameraStatusChanged(QCamera::Status status){
    qDebug() << "camera status changed : " << status;

}
