#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <QObject>

class TimeManager
{
public:
    QString formatTime(qint64 ms);
};

#endif // TIMEMANAGER_H
