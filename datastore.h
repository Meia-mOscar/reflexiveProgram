#ifndef DATASTORE_H
#define DATASTORE_H

#include <QList>
#include <QVariant>

struct DataStore{
    QList <QVariant> nameList;
    QList <QVariant> dateList;
    QList <QVariant> recommendList;
};

#endif // DATASTORE_H
