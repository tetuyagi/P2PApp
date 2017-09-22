/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "camera.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *sendButton;
    Camera *myViewfinder;
    QPushButton *captureImageButton;
    QLabel *label1;
    QLabel *label2;
    QPushButton *saveAudioButton;
    QPushButton *playAudioButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(180, 210, 113, 32));
        myViewfinder = new Camera(centralWidget);
        myViewfinder->setObjectName(QStringLiteral("myViewfinder"));
        myViewfinder->setGeometry(QRect(40, 30, 611, 161));
        captureImageButton = new QPushButton(centralWidget);
        captureImageButton->setObjectName(QStringLiteral("captureImageButton"));
        captureImageButton->setGeometry(QRect(320, 210, 113, 32));
        label1 = new QLabel(centralWidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(19, 245, 151, 101));
        label2 = new QLabel(centralWidget);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(460, 230, 191, 101));
        saveAudioButton = new QPushButton(centralWidget);
        saveAudioButton->setObjectName(QStringLiteral("saveAudioButton"));
        saveAudioButton->setGeometry(QRect(180, 260, 113, 32));
        playAudioButton = new QPushButton(centralWidget);
        playAudioButton->setObjectName(QStringLiteral("playAudioButton"));
        playAudioButton->setGeometry(QRect(320, 260, 113, 32));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        sendButton->setText(QApplication::translate("MainWindow", "send datagram", Q_NULLPTR));
        captureImageButton->setText(QApplication::translate("MainWindow", "capture image", Q_NULLPTR));
        label1->setText(QString());
        label2->setText(QString());
        saveAudioButton->setText(QApplication::translate("MainWindow", "save audio", Q_NULLPTR));
        playAudioButton->setText(QApplication::translate("MainWindow", "play audio", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
