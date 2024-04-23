#ifndef METEREDASHBOARD_H
#define METEREDASHBOARD_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class MetereDashboard;
}

class MetereDashboard : public QDialog
{
    Q_OBJECT

public:
    explicit MetereDashboard(QWidget *parent = nullptr);
    ~MetereDashboard();
    void getTotalKm(int x);
    void getEngine(int x);

private:
    int speed;
    QTimer *dialTimer;
    int totalKm;
    QTimer *enginTimer;
    int engineHours;

private:
    Ui::MetereDashboard *ui;
public slots:
    void changeSpeed();
    void changeEngine();
signals:
    void sendEngine(int x);
};

#endif // METEREDASHBOARD_H
