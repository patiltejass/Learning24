#ifndef GENERATEPDF_H
#define GENERATEPDF_H

#include <QDialog>
#include<map>
using namespace std;
// #include"ClassDec.h"

namespace Ui {
class Generatepdf;
}

class Generatepdf : public QDialog
{
    Q_OBJECT

public:
    explicit Generatepdf(map<QString,vector<pair<QString,pair<QString,pair<QString,QString>>>>> &logs1
                         ,QWidget *parent = nullptr);
    ~Generatepdf();

private slots:
    void on_pushButton_clicked();
    void updatecombo(const QString &text);

private:
    Ui::Generatepdf *ui;
    // Declarations *declare;
    map<QString,vector<pair<QString,pair<QString,pair<QString,QString>>>>> logs2;
    QString dvcname;

};

#endif // GENERATEPDF_H
