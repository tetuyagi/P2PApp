#include "roomselectwindow.h"
#include "ui_roomselectwindow.h"

RoomSelectWindow::RoomSelectWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoomSelectWindow)
{
    ui->setupUi(this);

    QPushButton *backButton = ui->backButton;
    QPushButton *selectButton = ui->selectButton;
    QPushButton *refreshButton = ui->refreshButton;


    connect(backButton, SIGNAL(clicked(bool)), this, SLOT(onBackButtonClicked(bool)));
    connect(selectButton, SIGNAL(clicked(bool)), this, SLOT(onSelectButtonClicked(bool)));
    connect(refreshButton, SIGNAL(clicked(bool)), this, SLOT(onRefreshButtonClicked(bool)));

    roomWindow = Q_NULLPTR;
}

RoomSelectWindow::~RoomSelectWindow()
{
    if(roomWindow != Q_NULLPTR){
        delete roomWindow;
    }
    delete ui;
}

void RoomSelectWindow::onBackButtonClicked(bool checked){
    Q_UNUSED(checked);

    qDebug() << "back";
    close();
}

void RoomSelectWindow::onSelectButtonClicked(bool checked){
    Q_UNUSED(checked);

    setVisible(false);

    if(roomWindow != Q_NULLPTR){
        delete roomWindow;
    }
    roomWindow = new RoomWindow(this);
    roomWindow->show();

    connect(roomWindow, SIGNAL(closed()), this, SLOT(show()));
}

void RoomSelectWindow::onRefreshButtonClicked(bool checked){
    Q_UNUSED(checked);
}


void RoomSelectWindow::closeEvent(QCloseEvent *event){
    qDebug() << "close event";
    Q_UNUSED(event);
    emit closed();
 }

