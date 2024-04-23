#ifndef DASHBOARDCLASS_H
#define DASHBOARDCLASS_H

#include <QMainWindow>
#include "serviceprovider.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class DashBoardClass;
}
QT_END_NAMESPACE

class DashBoardClass : public QMainWindow
{
    Q_OBJECT

public:
    DashBoardClass(QWidget *parent = nullptr);
    ~DashBoardClass();

private:
    Ui::DashBoardClass *ui;
    serviceProvider *serviceProviderobj;
};
#endif // DASHBOARDCLASS_H
