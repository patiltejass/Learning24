#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

signals:
    void loginInfo(const QString &email, const QString &password);


private:
    Ui::Login *ui;
};

#endif // LOGIN_H
