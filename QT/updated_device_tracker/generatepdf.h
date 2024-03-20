#ifndef GENERATEPDF_H
#define GENERATEPDF_H

#include <QDialog>
#include<map>
#include<vector>
#include<QFileInfo>
using namespace std;

namespace Ui {
class Generatepdf;
}

class Generatepdf : public QDialog
{
    Q_OBJECT

public:
    explicit Generatepdf(map<QString,vector<pair<QString,pair<QString,pair<QString,QFileInfo>>>>> &logs,QWidget *parent = nullptr);
    ~Generatepdf();

private slots:
    void on_pushButton_clicked();
    void updatecombo(const QString &text);

private:
    Ui::Generatepdf *ui;
    map<QString,vector<pair<QString,pair<QString,pair<QString,QFileInfo>>>>> &generatelogs;
    QString *dvcname;
};

#endif // GENERATEPDF_H
