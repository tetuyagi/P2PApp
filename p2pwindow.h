#ifndef P2PWINDOW_H
#define P2PWINDOW_H

#include <QMainWindow>

namespace Ui {
class P2PWindow;
}

class P2PWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit P2PWindow(QWidget *parent = 0);
    ~P2PWindow();

private:
    Ui::P2PWindow *ui;
};

#endif // P2PWINDOW_H
