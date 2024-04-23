/********************************************************************************
** Form generated from reading UI file 'usersettings.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSETTINGS_H
#define UI_USERSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserSettings
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *AddOperator_Button;
    QPushButton *Load_Button;
    QPushButton *Update_button;

    void setupUi(QDialog *UserSettings)
    {
        if (UserSettings->objectName().isEmpty())
            UserSettings->setObjectName("UserSettings");
        UserSettings->resize(1008, 538);
        layoutWidget = new QWidget(UserSettings);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(70, 10, 831, 481));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(43);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setPointSize(20);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName("comboBox");
        comboBox->setIconSize(QSize(46, 46));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);

        horizontalLayout_2->addWidget(label_4);

        comboBox_3 = new QComboBox(layoutWidget);
        comboBox_3->setObjectName("comboBox_3");

        horizontalLayout_2->addWidget(comboBox_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);

        comboBox_4 = new QComboBox(layoutWidget);
        comboBox_4->setObjectName("comboBox_4");

        horizontalLayout_3->addWidget(comboBox_4);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 5);
        verticalLayout->setStretch(2, 5);

        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        AddOperator_Button = new QPushButton(layoutWidget);
        AddOperator_Button->setObjectName("AddOperator_Button");
        QFont font2;
        font2.setPointSize(18);
        AddOperator_Button->setFont(font2);
        AddOperator_Button->setIconSize(QSize(69, 63));

        horizontalLayout_4->addWidget(AddOperator_Button);

        Load_Button = new QPushButton(layoutWidget);
        Load_Button->setObjectName("Load_Button");
        Load_Button->setFont(font2);

        horizontalLayout_4->addWidget(Load_Button);

        Update_button = new QPushButton(layoutWidget);
        Update_button->setObjectName("Update_button");
        Update_button->setFont(font2);

        horizontalLayout_4->addWidget(Update_button);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(UserSettings);

        QMetaObject::connectSlotsByName(UserSettings);
    } // setupUi

    void retranslateUi(QDialog *UserSettings)
    {
        UserSettings->setWindowTitle(QCoreApplication::translate("UserSettings", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("UserSettings", "User Settings", nullptr));
        label_2->setText(QCoreApplication::translate("UserSettings", "Operator Name : ", nullptr));
        label_4->setText(QCoreApplication::translate("UserSettings", "Dashboard Colour : ", nullptr));
        label_3->setText(QCoreApplication::translate("UserSettings", "Transmission Type : ", nullptr));
        AddOperator_Button->setText(QCoreApplication::translate("UserSettings", "Add Operator", nullptr));
        Load_Button->setText(QCoreApplication::translate("UserSettings", "Load", nullptr));
        Update_button->setText(QCoreApplication::translate("UserSettings", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserSettings: public Ui_UserSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSETTINGS_H
