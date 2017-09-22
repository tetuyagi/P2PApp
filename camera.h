#ifndef CAMERA_H
#define CAMERA_H

#include <Qcamera>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>

class Camera : public QCameraViewfinder
{
    Q_OBJECT
public:
    explicit Camera(QWidget *parent = Q_NULLPTR);

public slots:
    int capture();

private:
    QCamera *camera;
    QCameraImageCapture *imageCapture;

private slots:
    void onImageCaptured(int id, QImage image);
    void onCameraStatusChanged(QCamera::Status status);

signals:
    void imageCaptured(int id, QImage image);

};

#endif // CAMERA_H
