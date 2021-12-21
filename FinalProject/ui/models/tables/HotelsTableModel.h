#ifndef FINALPROJECT_HOTELSTABLEMODEL_H
#define FINALPROJECT_HOTELSTABLEMODEL_H

#include <set>
#include <vector>

#include <QList>
#include <QMap>
#include <QObject>
#include <QVariant>
#include <QAbstractItemModel>
#include <QAbstractTableModel>
#include <QModelIndex>

#include "Data.h"
#include "Hotel.h"
#include "HotelManager.h"
#include "BaseTableModel.h"


class HotelsTableModel: public BaseTableModel{
    Q_OBJECT
public:
    HotelsTableModel(QObject *parent = nullptr);

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    int columnCount(const QModelIndex &index) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
//
//    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
//    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
};


#endif //FINALPROJECT_HOTELSTABLEMODEL_H
