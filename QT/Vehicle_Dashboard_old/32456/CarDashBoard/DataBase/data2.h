#ifndef DATA2_H
#define DATA2_H

#include <QVector>
#include <vector>
#include <map>
#include <QString>
#include <QObject>
#include <QDebug>

using namespace std;
static const QString path = "People.db";
class data2 : public QObject
{
    Q_OBJECT
public:
    data2();
    ~data2();

;

#endif // DATA2_H
