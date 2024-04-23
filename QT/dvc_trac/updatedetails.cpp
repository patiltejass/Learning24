#include "updatedetails.h"
#include "ui_updatedetails.h"
#include<QMessageBox>
#include"mainwindow.h"

Updatedetails::Updatedetails(map<QString,vector<QString>>&userdetails1,
                             map<QString,vector<QString>>&devicedetails1,
                             QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Updatedetails),
    userdetails2(userdetails1),
    devicedetails2(devicedetails1)
{

    ui->setupUi(this);
    connect(ui->radioButton, &QRadioButton::clicked, this, &Updatedetails::updateWidget);
    connect(ui->radioButton_2, &QRadioButton::clicked, this, &Updatedetails::updateWidget);

}

Updatedetails::~Updatedetails()
{
    delete ui;
}

void Updatedetails::updateWidget()
{
    if(ui->radioButton_2->isChecked()){
        ui->stackedWidget->setCurrentWidget(ui->update_user);
    }
    else if(ui->radioButton->isChecked()){
        ui->stackedWidget->setCurrentWidget(ui->update_dvc);
    }
}

void Updatedetails::on_update_user_button_clicked()
{
    Username= ui->user_name_textedit->toPlainText();
    location=ui->Location_textedit->toPlainText();
    userdetails2[Username].push_back(location);
    db->insertuserData(Username,location);
    QMessageBox::information(nullptr,"Success","User Added Successfully");
}

void Updatedetails::accessDB(Database &dbconnection){
    db = &dbconnection;
}

void Updatedetails::on_pushButton_clicked()
{
    Dvcname= ui->dvc_name_textedit->toPlainText();
    Sr_No=ui->sr_no_textedit->toPlainText();
    userdetails2[Dvcname].push_back(Sr_No);
    db->insertdeviceData(Dvcname,Sr_No);
    QMessageBox::information(nullptr,"Success","Device Added Successfully");
}


void Updatedetails::on_radioButton_clicked()
{

}

