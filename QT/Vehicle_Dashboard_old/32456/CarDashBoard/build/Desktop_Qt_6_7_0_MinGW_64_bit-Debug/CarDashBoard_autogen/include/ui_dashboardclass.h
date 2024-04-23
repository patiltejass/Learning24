/********************************************************************************
** Form generated from reading UI file 'dashboardclass.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARDCLASS_H
#define UI_DASHBOARDCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DashBoardClass
{
public:
    QWidget *centralwidget;
    QPushButton *User_Settings_Button;
    QPushButton *Reset_Button;
    QPushButton *Start_Button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DashBoardClass)
    {
        if (DashBoardClass->objectName().isEmpty())
            DashBoardClass->setObjectName("DashBoardClass");
        DashBoardClass->resize(1220, 546);
        DashBoardClass->setStyleSheet(QString::fromUtf8("background-color: black;"));
        centralwidget = new QWidget(DashBoardClass);
        centralwidget->setObjectName("centralwidget");
        User_Settings_Button = new QPushButton(centralwidget);
        User_Settings_Button->setObjectName("User_Settings_Button");
        User_Settings_Button->setGeometry(QRect(70, 310, 381, 111));
        QFont font;
        font.setPointSize(29);
        font.setBold(true);
        User_Settings_Button->setFont(font);
        User_Settings_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(107, 114, 142);"));
        Reset_Button = new QPushButton(centralwidget);
        Reset_Button->setObjectName("Reset_Button");
        Reset_Button->setGeometry(QRect(760, 310, 381, 111));
        Reset_Button->setFont(font);
        Reset_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(107, 114, 142);"));
        Start_Button = new QPushButton(centralwidget);
        Start_Button->setObjectName("Start_Button");
        Start_Button->setGeometry(QRect(410, 60, 381, 111));
        Start_Button->setFont(font);
        Start_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(107, 114, 142);"));
        DashBoardClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DashBoardClass);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1220, 22));
        DashBoardClass->setMenuBar(menubar);
        statusbar = new QStatusBar(DashBoardClass);
        statusbar->setObjectName("statusbar");
        DashBoardClass->setStatusBar(statusbar);

        retranslateUi(DashBoardClass);

        QMetaObject::connectSlotsByName(DashBoardClass);
    } // setupUi

    void retranslateUi(QMainWindow *DashBoardClass)
    {
        DashBoardClass->setWindowTitle(QCoreApplication::translate("DashBoardClass", "DashBoardClass", nullptr));
        User_Settings_Button->setText(QCoreApplication::translate("DashBoardClass", "USER SETTINGS", nullptr));
        Reset_Button->setText(QCoreApplication::translate("DashBoardClass", "RESET", nullptr));
        Start_Button->setText(QCoreApplication::translate("DashBoardClass", "START", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DashBoardClass: public Ui_DashBoardClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARDCLASS_H
