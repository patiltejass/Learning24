#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<map>
#include<vector>
#include<QFileDialog>
#include<QImage>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    devicedetails = new map<QString, vector<QString>>;
    userdetails = new map<QString, vector<QString>>;
    logs = new map<QString,vector<pair<QString,pair<QString,pair<QString,QFileInfo>>>>>;
    (*devicedetails)["Display"]={"D123","D234","D345"};
    (*devicedetails)["RaspBerry Pi"]={"R321","R432","R543"};
    (*userdetails)["Tejas"]={"Pune"};
    (*userdetails)["Pratik"]={"Hyderabad"};
    (*userdetails)["Amar"]={"Hyderabad","Pune"};
    QPixmap pixmap("D:\\Users\\Downloads\\add-image-1-128.png");
    ui->photolabel->setPixmap(pixmap);
    ui->photolabel->setScaledContents(true);
    showdrop();
    connect(ui->assignedto_combobox, &QComboBox::currentTextChanged, this, &MainWindow::updateloc);
    connect(ui->device_name_combobox, &QComboBox::currentTextChanged, this, &MainWindow::updateserial);
}
void MainWindow::updateloc(const QString &text) {
    ui->location_combobox->clear();
    ui->location_combobox->addItem("Select an Option");
    auto found = userdetails->find(text);
    if (found != userdetails->end()) { // Check if the key is found
        for (auto it : found->second) { // Access using found->second
            ui->location_combobox->addItem(it);
        }
    }
}

void MainWindow::updateserial(const QString &text) {
    ui->Serial_No_combobox->clear();
    ui->Serial_No_combobox->addItem("Select an option");
    auto found = devicedetails->find(text);
    if (found != devicedetails->end()) {
        for (auto it : found->second) {
            ui->Serial_No_combobox->addItem(it);
        }
    }
}

void MainWindow::showdrop(){
    //ui->device_name_combobox->clear();
    ui->device_name_combobox->addItem("Select an option");
    for(auto it: *devicedetails){
        ui->device_name_combobox->addItem(it.first);
    }
    // ui->assignedto_combobox->clear();
    ui->assignedto_combobox->addItem("Select an option");
    for(auto it:*userdetails){
        ui->assignedto_combobox->addItem(it.first);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_save_button_clicked()
{
    QString device_name = ui->device_name_combobox->currentText();
    QString serial_num= ui->Serial_No_combobox->currentText();
    QString username = ui->assignedto_combobox->currentText();
    QString location = ui->location_combobox->currentText();
    QString filename = fileInfo.selectedImageFilename();
    auto it = logs->find(device_name);
    if(it==logs->end()){
        (*logs)[device_name].push_back(make_pair(serial_num,make_pair(username,make_pair(location,filename))));
    }
    else if(it!=logs->end()){
        (*logs)[device_name].push_back(make_pair(serial_num,make_pair(username,make_pair(location,filename))));
    }
}



void MainWindow::on_select_img_button_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select An Image", QDir::homePath(), "Image Files (*.png *.jpg)");

    if (!fileName.isEmpty()) {
        QFileInfo fileInfo(fileName);
        selectedImageFilename = fileInfo.fileName();
        ui->select_img_button->setText(selectedImageFilename);
        QImage image(fileName);
        if(!image.isNull()){
            ui->photolabel->setPixmap(QPixmap::fromImage(image));
            ui->photolabel->setScaledContents(true);
        }
    }

}

void MainWindow::on_generate_button_clicked()
{
    Generatepdf *generate = new Generatepdf(*logs);
    generate->show();

}

