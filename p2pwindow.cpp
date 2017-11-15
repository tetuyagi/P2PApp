#include "p2pwindow.h"
#include "ui_p2pwindow.h"

P2PWindow::P2PWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::P2PWindow)
{
    ui->setupUi(this);
}

P2PWindow::~P2PWindow()
{
    delete ui;
}
