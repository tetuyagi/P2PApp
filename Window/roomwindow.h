#ifndef ROOMWINDOW_H
#define ROOMWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "p2pwindow.h"

namespace Ui {
class RoomWindow;
}

class RoomWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RoomWindow(QWidget *parent = 0);
    ~RoomWindow();

    void setRoomName(QString name);

protected:
    void closeEvent(QCloseEvent *event) override;


private:
    Ui::RoomWindow *ui;
    P2PWindow *p2pWindow;
    QLabel *roomNameLabel;

private slots:
    void onBackButtonClicked(bool checked);
    void onStartButtonClicked(bool checked);


signals:
    void closed();
};

#endif // ROOMWINDOW_H
