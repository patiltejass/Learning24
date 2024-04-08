#include "generatepdf.h"
#include "ui_generatepdf.h"
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPainter>
#include <QPdfWriter>
#include <QFileDialog>
#include<QMessageBox>
#include<QCursor>
#include <QTextCursor>
#include "QTextDocumentWriter"
#include "QTextDocument"
#include "QDesktopServices"
using namespace std;

Generatepdf::Generatepdf(map<QString,vector<pair<QString,pair<QString,pair<QString,QString>>>>> &logs1,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Generatepdf),
    logs2(logs1)
{
    ui->setupUi(this);
    // declare = new Declarations;
    connect(ui->Devicename_combo, &QComboBox::currentTextChanged, this, &Generatepdf::updatecombo);
    // dvcname = new QString; // Allocate memory for the QString
    // logs1 = declare->getlogs();
    for(auto it:logs2){
        ui->Devicename_combo->addItem(it.first);
    }
}
void Generatepdf::updatecombo(const QString &text){
    dvcname=text;
}


void Generatepdf::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save PDF"), "output.pdf", tr("PDF Files (*.pdf)"));
    if (fileName.isEmpty()) {
        return;
    }

    QTextDocument document;
    QTextCursor cursor(&document);
    cursor.insertText("Device Logs for " + dvcname + "\n");
    auto it = logs2.find(dvcname);
    if (it != logs2.end()) {
        auto& logEntries = it->second;
        for (const auto& logEntry : logEntries) {
            // Move this line inside the loop
            cursor.insertText("Serial Number: " + logEntry.first + "\n");
            cursor.insertText("Assigned: " + logEntry.second.first + "\n");
            cursor.insertText("Location: " + logEntry.second.second.first + "\n");
            QTextImageFormat img;
            qDebug()<<logEntry.second.second.second;
            img.setName(logEntry.second.second.second);
            cursor.insertImage(img);
            // cursor.insertText("\n");
        }
    }
    QPdfWriter pdfWriter(fileName);
    pdfWriter.setResolution(500);
    QPainter pdff(&pdfWriter);
    document.drawContents(&pdff);
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
    // QMessageBox::information(nullptr,"Success","PDF Generated Successfully Successfully");

}
Generatepdf::~Generatepdf()
{
    // delete declare;
    delete ui;
}
