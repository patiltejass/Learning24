/********************************************************************************
** Form generated from reading UI file 'addoperatorwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDOPERATORWINDOW_H
#define UI_ADDOPERATORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddOperatorWindow
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *add_button;

    void setupUi(QDialog *AddOperatorWindow)
    {
        if (AddOperatorWindow->objectName().isEmpty())
            AddOperatorWindow->setObjectName("AddOperatorWindow");
        AddOperatorWindow->resize(752, 488);
        layoutWidget = new QWidget(AddOperatorWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(70, 30, 611, 331));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        add_button = new QPushButton(layoutWidget);
        add_button->setObjectName("add_button");
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        add_button->setFont(font2);

        verticalLayout->addWidget(add_button);


        retranslateUi(AddOperatorWindow);

        QMetaObject::connectSlotsByName(AddOperatorWindow);
    } // setupUi

    void retranslateUi(QDialog *AddOperatorWindow)
    {
        AddOperatorWindow->setWindowTitle(QCoreApplication::translate("AddOperatorWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddOperatorWindow", "Add New Operator", nullptr));
        label_2->setText(QCoreApplication::translate("AddOperatorWindow", "Operator Name : ", nullptr));
        add_button->setText(QCoreApplication::translate("AddOperatorWindow", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddOperatorWindow: public Ui_AddOperatorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDOPERATORWINDOW_H
