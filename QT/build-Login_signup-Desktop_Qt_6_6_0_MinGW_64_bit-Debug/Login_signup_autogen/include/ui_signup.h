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
    QLabel *label;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QDialog *Signup)
    {
        if (Signup->objectName().isEmpty())
            Signup->setObjectName("Signup");
        Signup->resize(423, 321);
        Signup->setMinimumSize(QSize(50, 51));
        label = new QLabel(Signup);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 10, 91, 41));
        textEdit = new QTextEdit(Signup);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(180, 60, 161, 31));
        textEdit->setStyleSheet(QString::fromUtf8("border : 1px solid black;"));
        textEdit_2 = new QTextEdit(Signup);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(180, 120, 161, 31));
        textEdit_2->setStyleSheet(QString::fromUtf8("border : 1px solid black;"));
        textEdit_3 = new QTextEdit(Signup);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(180, 180, 161, 31));
        textEdit_3->setStyleSheet(QString::fromUtf8("border : 1px solid black;"));
        label_2 = new QLabel(Signup);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 60, 63, 20));
        label_3 = new QLabel(Signup);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 120, 71, 20));
        label_4 = new QLabel(Signup);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 180, 131, 20));
        pushButton = new QPushButton(Signup);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 240, 83, 29));

        retranslateUi(Signup);

        QMetaObject::connectSlotsByName(Signup);
    } // setupUi

    void retranslateUi(QDialog *Signup)
    {
        Signup->setWindowTitle(QCoreApplication::translate("Signup", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Signup", "SignUp Form", nullptr));
        label_2->setText(QCoreApplication::translate("Signup", "Email :", nullptr));
        label_3->setText(QCoreApplication::translate("Signup", "Password :", nullptr));
        label_4->setText(QCoreApplication::translate("Signup", "Confirm Password :", nullptr));
        pushButton->setText(QCoreApplication::translate("Signup", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Signup: public Ui_Signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
