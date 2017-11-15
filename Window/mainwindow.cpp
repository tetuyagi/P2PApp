#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>



//MainWindow
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *makeRoomButton = ui->makeRoomButton;
    QPushButton *selectRoomButton = ui->selectRoomButton;
    QPushButton *connectServerButton = ui->connectServerButton;
    QPushButton *registUserButton = ui->registUserButton;
    nameInput = ui->nameInput;

    connect(makeRoomButton, SIGNAL(clicked(bool)), this, SLOT(onMakeRoomButtonClicked(bool)));
    connect(selectRoomButton, SIGNAL(clicked(bool)), this, SLOT(onSelectRoomButtonClicked(bool)));
    connect(connectServerButton, SIGNAL(clicked(bool)), this, SLOT(onConnectServerButtonClicked(bool)));
    connect(registUserButton, SIGNAL(clicked(bool)), this, SLOT(onRegistUserButtonClicked(bool)));



}

MainWindow::~MainWindow()
{
    qDebug() << "start destroy";

    delete roomWindow;
    delete roomSelectWindow;
    delete nameInput;
    delete ui;

    qDebug() << "destroy mainwindow";
}

void MainWindow::onMakeRoomButtonClicked(bool checked){
    Q_UNUSED(checked);
    qDebug() << "make room";

    this->setVisible(false);

    if(roomWindow != Q_NULLPTR){
        delete roomWindow;
    }
    roomWindow = new RoomWindow(this);
    roomWindow->show();
    roomWindow->setRoomName(userName);

    connect(roomWindow, SIGNAL(closed()), this, SLOT(show()));
}

void MainWindow::onSelectRoomButtonClicked(bool checked){
    Q_UNUSED(checked);
    qDebug() << "select room";

    this->setVisible(false);
    if(roomSelectWindow != Q_NULLPTR){
        delete roomSelectWindow;
    }
    roomSelectWindow = new RoomSelectWindow(this);
    roomSelectWindow->show();

    connect(roomSelectWindow, SIGNAL(closed()), this, SLOT(show()));
}

void MainWindow::onConnectServerButtonClicked(bool checked){
    Q_UNUSED(checked);
}

void MainWindow::onRegistUserButtonClicked(bool checked){
    Q_UNUSED(checked);
    registUser();
}

void MainWindow::registUser(){
    userName = nameInput->text();

}
