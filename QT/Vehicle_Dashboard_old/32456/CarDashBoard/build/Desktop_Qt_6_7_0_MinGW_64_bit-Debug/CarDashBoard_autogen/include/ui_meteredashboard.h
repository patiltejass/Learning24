/********************************************************************************
** Form generated from reading UI file 'meteredashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_METEREDASHBOARD_H
#define UI_METEREDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_MetereDashboard
{
public:
    QLabel *label;
    QLabel *label_2;
    QDial *dial;
    QDial *dial_2;
    QLCDNumber *lcdNumber;
    QLabel *label_3;
    QLabel *label_4;
    QLCDNumber *lcdNumber_2;

    void setupUi(QDialog *MetereDashboard)
    {
        if (MetereDashboard->objectName().isEmpty())
            MetereDashboard->setObjectName("MetereDashboard");
        MetereDashboard->resize(1222, 548);
        label = new QLabel(MetereDashboard);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 80, 421, 411));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/speedometer/Speedometer.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(MetereDashboard);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(700, 80, 421, 411));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/speedometer/Speedometer.png")));
        label_2->setScaledContents(true);
        dial = new QDial(MetereDashboard);
        dial->setObjectName("dial");
        dial->setGeometry(QRect(170, 170, 231, 241));
        dial->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        dial_2 = new QDial(MetereDashboard);
        dial_2->setObjectName("dial_2");
        dial_2->setGeometry(QRect(790, 160, 231, 241));
        lcdNumber = new QLCDNumber(MetereDashboard);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(510, 410, 181, 81));
        label_3 = new QLabel(MetereDashboard);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(530, 360, 131, 51));
        QFont font;
        font.setPointSize(18);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(MetereDashboard);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(530, 40, 131, 51));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lcdNumber_2 = new QLCDNumber(MetereDashboard);
        lcdNumber_2->setObjectName("lcdNumber_2");
        lcdNumber_2->setGeometry(QRect(510, 90, 181, 81));

        retranslateUi(MetereDashboard);

        QMetaObject::connectSlotsByName(MetereDashboard);
    } // setupUi

    void retranslateUi(QDialog *MetereDashboard)
    {
        MetereDashboard->setWindowTitle(QCoreApplication::translate("MetereDashboard", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("MetereDashboard", "Total KM", nullptr));
        label_4->setText(QCoreApplication::translate("MetereDashboard", "Total Engine Hours", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MetereDashboard: public Ui_MetereDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_METEREDASHBOARD_H
