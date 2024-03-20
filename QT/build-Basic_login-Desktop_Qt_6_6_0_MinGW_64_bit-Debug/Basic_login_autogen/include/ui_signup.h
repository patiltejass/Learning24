/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Signup
{
public:
    QPushButton *pushButton;
    QTextEdit *textEdit_2;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEdit;
    QTextEdit *textEdit_3;

    void setupUi(QDialog *Signup)
    {
        if (Signup->objectName().isEmpty())
            Signup->setObjectName("Signup");
        Signup->resize(400, 300);
        pushButton = new QPushButton(Signup);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(170, 250, 83, 29));
        textEdit_2 = new QTextEdit(Signup);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(200, 130, 161, 31));
        textEdit_2->setStyleSheet(QString::fromUtf8("border : 1px solid black;"));
        label_4 = new QLabel(Signup);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 190, 131, 20));
        label = new QLabel(Signup);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 20, 91, 41));
        label_2 = new QLabel(Signup);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 70, 63, 20));
        label_3 = new QLabel(Signup);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 130, 71, 20));
        textEdit = new QTextEdit(Signup);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(200, 70, 161, 31));
        textEdit->setStyleSheet(QString::fromUtf8("border : 1px solid black;"));
        textEdit_3 = new QTextEdit(Signup);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(200, 190, 161, 31));
        textEdit_3->setStyleSheet(QString::fromUtf8("border : 1px solid black;"));

        retranslateUi(Signup);

        QMetaObject::connectSlotsByName(Signup);
    } // setupUi

    void retranslateUi(QDialog *Signup)
    {
        Signup->setWindowTitle(QCoreApplication::translate("Signup", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Signup", "Submit", nullptr));
        label_4->setText(QCoreApplication::translate("Signup", "Confirm Password :", nullptr));
        label->setText(QCoreApplication::translate("Signup", "SignUp Form", nullptr));
        label_2->setText(QCoreApplication::translate("Signup", "Email :", nullptr));
        label_3->setText(QCoreApplication::translate("Signup", "Password :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Signup: public Ui_Signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
