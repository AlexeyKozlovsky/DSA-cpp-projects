#ifndef FINALPROJECT_PLACESTABLEMODEL_H
#define FINALPROJECT_PLACESTABLEMODEL_H

#include <QObject>
#include <QString>
#include <QAbstractTableModel>
#include <QList>
#include <QMap>

#include "BaseTableModel.h"

class PlacesTableModel: public BaseTableModel {
    Q_OBJECT
public:
    PlacesTableModel(QObject *parent = nullptr);

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    int columnCount(const QModelIndex &index) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
};


#endif //FINALPROJECT_PLACESTABLEMODEL_H
