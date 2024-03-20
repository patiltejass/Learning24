/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(400, 300);
        label_2 = new QLabel(Login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 60, 63, 20));
        label = new QLabel(Login);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 10, 91, 41));
        label_3 = new QLabel(Login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 120, 71, 20));
        pushButton = new QPushButton(Login);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 180, 83, 29));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        textEdit_2 = new QTextEdit(Login);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(160, 120, 161, 31));
        textEdit_2->setStyleSheet(QString::fromUtf8("border : 1px solid black;"));
        textEdit = new QTextEdit(Login);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(160, 60, 161, 31));
        textEdit->setStyleSheet(QString::fromUtf8("border : 1px solid black;"));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "Email :", nullptr));
        label->setText(QCoreApplication::translate("Login", "Login Form", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "Password :", nullptr));
        pushButton->setText(QCoreApplication::translate("Login", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
