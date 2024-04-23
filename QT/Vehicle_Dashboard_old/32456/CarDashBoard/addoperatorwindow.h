#ifndef ADDOPERATORWINDOW_H
#define ADDOPERATORWINDOW_H

#include <QDialog>
#include "serviceprovider.h"

namespace Ui {
class AddOperatorWindow;
}

class AddOperatorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddOperatorWindow(QWidget *parent = nullptr);
    ~AddOperatorWindow();

private slots:
    void on_add_button_clicked();
public slots:
    void changeCol(QString col);
signals:
    void sendOperator(const QString &op);

private:
    Ui::AddOperatorWindow *ui;
    serviceProvider *serviceProvider_Obj;

};

#endif // ADDOPERATORWINDOW_H
