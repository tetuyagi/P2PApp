#ifndef ROOMSELECTWINDOW_H
#define ROOMSELECTWINDOW_H

#include <QMainWindow>
#include <QListView>

#include "roomwindow.h"

namespace Ui {
class RoomSelectWindow;
}

class RoomSelectWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RoomSelectWindow(QWidget *parent = 0);
    ~RoomSelectWindow();


protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::RoomSelectWindow *ui;
    QListView *listView;

    RoomWindow *roomWindow;

private slots:
    void onBackButtonClicked(bool checked);
    void onSelectButtonClicked(bool checked);
    void onRefreshButtonClicked(bool checked);



signals:
    void closed();


};

#endif // ROOMSELECTWINDOW_H
