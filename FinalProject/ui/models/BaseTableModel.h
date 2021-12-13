#ifndef FINALPROJECT_BASETABLEMODEL_H
#define FINALPROJECT_BASETABLEMODEL_H

#include <QObject>
#include <QString>
#include <QAbstractTableModel>
#include <QMap>
#include <QList>

#include "Data.h"


class BaseTableModel: public QAbstractTableModel {
    Q_OBJECT
protected:
    QList<QMap<QString, QString>> resources;
    QList<Data *> resourcePointers;

public:
    BaseTableModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &index) const override;
};


#endif //FINALPROJECT_BASETABLEMODEL_H
