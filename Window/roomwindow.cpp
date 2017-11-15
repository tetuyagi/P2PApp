#include "roomwindow.h"
#include "ui_roomwindow.h"

RoomWindow::RoomWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoomWindow)
{
    ui->setupUi(this);

    QPushButton *backButton = ui->backButton;
    QPushButton *startButton = ui->startButton;
    roomNameLabel = ui->roomNameLabel;

    connect(backButton, SIGNAL(clicked(bool)), this, SLOT(onBackButtonClicked(bool)));
    connect(startButton, SIGNAL(clicked(bool)), this, SLOT(onStartButtonClicked(bool)));

    p2pWindow = Q_NULLPTR;
}

RoomWindow::~RoomWindow()
{
    if(p2pWindow != Q_NULLPTR){
        delete p2pWindow;
    }
    delete ui;
    delete roomNameLabel;
}

void RoomWindow::onBackButtonClicked(bool checked){
    Q_UNUSED(checked);
    close();
}

void RoomWindow::onStartButtonClicked(bool checked){
    Q_UNUSED(checked);

    setVisible(false);
    if(p2pWindow != Q_NULLPTR){
        delete p2pWindow;
    }
    p2pWindow = new P2PWindow(this);
    p2pWindow->show();

    connect(p2pWindow, SIGNAL(closed()), this, SLOT(show()));
}

void RoomWindow::closeEvent(QCloseEvent *event){
    Q_UNUSED(event);

    emit closed();
}

void RoomWindow::setRoomName(QString name){
     roomNameLabel->setText(name);
}
