#include "usersettings.h"
#include "ui_usersettings.h"

UserSettings::UserSettings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserSettings)
    ,serviceProvider_obj(new serviceProvider)
{
    ui->setupUi(this);
    setCombo();
    connect(this, &UserSettings::sendDataOfUser, serviceProvider_obj, &serviceProvider::sendUserDataToDB);
    connect(this, &UserSettings::updateUser, serviceProvider_obj, &serviceProvider::updateUser);
    //connect(this, &UserSettings::sendColour , adOp_Obj , &AddOperatorWindow::changeCol);
}

UserSettings::~UserSettings()
{
    delete ui;
}

std::vector<QString> UserSettings::askForOp()
{
    return serviceProvider_obj->sendOperatorData();
}

void UserSettings::on_AddOperator_Button_clicked()
{
    adOp_Obj = new AddOperatorWindow;
    adOp_Obj -> show();
}

void UserSettings::on_Load_Button_clicked()
{
    QString ope = ui->comboBox->currentText();
    QString col = ui->comboBox_3->currentText();
    QString trans = ui->comboBox_4->currentText();

    this->setStyleSheet("background-color:" + col + ";");
    emit sendColour(col);
    emit sendDataOfUser(ope , col , trans);
}

void UserSettings::setCombo()
{
    std::vector<QString> ans = askForOp();

    for(int i = 0 ; i < ans.size() ; i++)
    {
        ui->comboBox->addItem(ans[i]);
    }
    ui->comboBox_3->addItem("Red");
    ui->comboBox_3->addItem("white");
    ui->comboBox_3->addItem("blue");
    ui->comboBox_3->addItem("black");

    ui->comboBox_4->addItem("Echo");
    ui->comboBox_4->addItem("Sports");

}


void UserSettings::on_Update_button_clicked()
{
    QString ope = ui->comboBox->currentText();
    QString col = ui->comboBox_3->currentText();
    QString trans = ui->comboBox_4->currentText();

    emit updateUser(ope , col , trans);

}

