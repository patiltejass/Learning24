#include "generatepdf.h"
#include "ui_generatepdf.h"
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPainter>
#include <QPdfWriter>
#include <QFileDialog>
#include<QCursor>
#include <QTextCursor>
#include "QTextDocumentWriter"
#include "QTextDocument"
#include "QDesktopServices"
using namespace std;

Generatepdf::Generatepdf(map<QString,vector<pair<QString,pair<QString,pair<QString,QFileInfo>>>>> &logs,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Generatepdf),
    generatelogs(logs)
{
    ui->setupUi(this);
    connect(ui->Devicename_combo, &QComboBox::currentTextChanged, this, &Generatepdf::updatecombo);
    dvcname = new QString; // Allocate memory for the QString
    for(auto it:generatelogs){
        ui->Devicename_combo->addItem(it.first);
    }

}
void Generatepdf::updatecombo(const QString &text){
    *dvcname=text;
}

Generatepdf::~Generatepdf()
{
    delete ui;
}


void Generatepdf::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save PDF"), "output.pdf", tr("PDF Files (*.pdf)"));
    if (fileName.isEmpty()) {
        return;
    }

    QTextDocument document;
    QTextCursor cursor(&document);
    cursor.insertText("Device Logs for " + *dvcname + "\n");
    auto it = generatelogs.find(*dvcname);
    if (it != generatelogs.end()) {
        auto& logEntries = it->second;
        for (const auto& logEntry : logEntries) {
            // Move this line inside the loop
            cursor.insertText("Serial Number: " + logEntry.first + "\n");
            cursor.insertText("Assigned: " + logEntry.second.first + "\n");
            cursor.insertText("Location: " + logEntry.second.second + "\n");
        }
    }
    QPdfWriter pdfWriter(fileName);
    pdfWriter.setResolution(500);
    QPainter pdff(&pdfWriter);
    document.drawContents(&pdff);
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}

