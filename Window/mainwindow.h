#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>

#include "roomselectwindow.h"
#include "roomwindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();

    /*
protected:
    void closeEvent(QCloseEvent *event);
    */

private:

    Ui::MainWindow *ui;

    QLineEdit *nameInput;
    RoomWindow *roomWindow;
    RoomSelectWindow *roomSelectWindow;

    QString userName;


private slots:
    void onConnectServerButtonClicked(bool checked);
    void onRegistUserButtonClicked(bool checked);
    void onSelectRoomButtonClicked(bool checked);
    void onMakeRoomButtonClicked(bool checked);

    void registUser();


};

#endif // MAINWINDOW_H
