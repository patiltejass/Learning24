#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include<QFileDialog>
#include<QImage>
#include<QMessageBox>
#include <algorithm> // Add this line for std::find




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    declare= new Declarations;
    // timer = new QTimer(this);
    connect(ui->assignedto_combobox, &QComboBox::currentTextChanged, this, &MainWindow::updateloc);
    connect(ui->device_name_combobox, &QComboBox::currentTextChanged, this, &MainWindow::updateserial);
    dbconnection.setlogmap();
    userdata = dbconnection.setusermap();
    devicedata=dbconnection.setdevicemap();
    logdata=dbconnection.setlogmap();
    dbconnection.setdevicemap();

    // connect(&dbconnection, &Database::sendlogdetails,this, &MainWindow::setting_logmap);
    // connect(&dbconnection, &Database::senduserdetails,this, &MainWindow::setting_usermap);
    // connect(&dbconnection, &Database::senddevicedetails,this, &MainWindow::setting_devicemap);
    setting_usermap();
    setting_devicemap();
    /*
    declare->setuserdetails("Tejas","Pune");
    declare->setuserdetails("Pratik","Hyderabad");
    declare->setuserdetails("Amar","Pune");
    declare->setuserdetails("Amar","Hyderabad");*/
    // declare->setdevicedetails("Raspberry pi","R123");
    // declare->setdevicedetails("Raspberry pi","R234");
    // declare->setdevicedetails("Raspberry pi","R345");
    // declare->setdevicedetails("Display","D321");
    // declare->setdevicedetails("Display","D432");
    // declare->setdevicedetails("Display","D543");
    // declare->setlogs("Raspberry","R456","Tejas","Pune","45");
    QPixmap pixmap("D:\\Users\\Downloads\\add-image-1-128.png");
    ui->photolabel->setPixmap(pixmap);
    ui->photolabel->setScaledContents(true);
    devicedetails1=declare->getdevicedetails();
    userdetails1=declare->getuserdetails();
    // connect(timer, &QTimer::timeout, this, &MainWindow::changeBackgroundColor);
    // timer->start(1000);
    showdrop();

}

void MainWindow::setting_logmap(){
    for(auto it:logdata){
        declare->setlogs(it.first,it.second.first,it.second.second.first,it.second.second.second.first,it.second.second.second.second);
         // vector<pair<QString,pair<QString,pair<QString,pair<QString,QString>>>>>logdata;
    }
}
void MainWindow::setting_usermap(){
    for(auto it:userdata){
        qDebug()<<"slot"<<it.first<<" "<<it.second<<"\n";
        declare->setuserdetails(it.first,it.second);
    }
}
void MainWindow::setting_devicemap(){
    for(auto it:devicedata){
        declare->setdevicedetails(it.first,it.second);
    }
}

// void MainWindow::changeBackgroundColor(){
//     static QStringList colors = {"red", "blue", "green", "white", "black"};

//     // Get the next color from the list
//     currentColorIndex = (currentColorIndex + 1) % colors.size();
//     QString colorName = colors[currentColorIndex];

//     // Apply the background color using stylesheets
//     QString styleSheet = QString("background-color: %1;").arg(colorName);
//     setStyleSheet(styleSheet);
// }

void MainWindow::showdrop() {
    ui->device_name_combobox->clear();
    ui->device_name_combobox->addItem("Select an option");
    for (auto it : devicedetails1) {
        ui->device_name_combobox->addItem(it.first);
    }

    ui->assignedto_combobox->clear();
    ui->assignedto_combobox->addItem("Select an option");
    for (auto it : userdetails1) {
        ui->assignedto_combobox->addItem(it.first);
    }
}

void MainWindow::updateserial(const QString &text) {
    ui->Serial_No_combobox->clear();
    ui->Serial_No_combobox->addItem("Select an Option");
    auto found = devicedetails1.find(text);
    if (found != devicedetails1.end()) {
        for (auto it : found->second) {
            ui->Serial_No_combobox->addItem(it);
        }
    }
}

void MainWindow::updateloc(const QString &text) {
    ui->location_combobox->clear();
    ui->location_combobox->addItem("Select an Option");
    auto found = userdetails1.find(text);
    if (found != userdetails1.end()) {
        for (auto it : found->second) {
            ui->location_combobox->addItem(it);
        }
    }
}
void MainWindow::on_select_img_button_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select An Image", QDir::homePath(), "Image Files (*.png *.jpg)");

    if (!fileName.isEmpty()) {
        QFileInfo fileInfo(fileName);
        selectedImageFilename = fileName;
        ui->select_img_button->setText(selectedImageFilename);
        QImage image(fileName);
        if(!image.isNull()){
            ui->photolabel->setPixmap(QPixmap::fromImage(image));
            ui->photolabel->setScaledContents(true);
        }
    }

}
void MainWindow::on_save_button_clicked(){
    QString device_name = ui->device_name_combobox->currentText();
    QString serial_num= ui->Serial_No_combobox->currentText();
    QString username = ui->assignedto_combobox->currentText();
    QString location = ui->location_combobox->currentText();
    QString filename = selectedImageFilename;
    // declare->copymap();
    logs1=declare->getlogs();
    auto it = logs1.find(device_name);
    if(it==logs1.end()){
        declare->setlogs(device_name,serial_num,username,location,filename);
        // logs1[device_name].push_back(make_pair(serial_num,make_pair(username,make_pair(location,filename))));
    }
    else if(it!=logs1.end()){
        declare->setlogs(device_name,serial_num,username,location,filename);

        // logs1[device_name].push_back(make_pair(serial_num,make_pair(username,make_pair(location,filename))));
    }
    auto it1 = std::find(devicedetails1[device_name].begin(), devicedetails1[device_name].end(), serial_num);
    if (it1 != devicedetails1[device_name].end()) {
        devicedetails1[device_name].erase(it1);
    }
    // devicedetails1[device_name].pop_back(serial_num);
    logs1=declare->getlogs();
    dbconnection.insertData(device_name,serial_num,filename,username,location);
    QMessageBox::information(nullptr,"Success","Device Assigned Successfully");
}
void MainWindow::on_generate_button_clicked()
{
    Generatepdf *generate= new Generatepdf(logs1);
    generate->show();
}

void MainWindow::on_update_user_button_clicked()
{
    Updatedetails *update = new Updatedetails(userdetails1,devicedetails1);
    emit sendDB(dbconnection);
    connect(this,MainWindow::sendDB,update,Updatedetails::accessDB);
    update->show();
}
MainWindow::~MainWindow()
{
    delete declare;
    delete ui;
    // delete timer;

}



