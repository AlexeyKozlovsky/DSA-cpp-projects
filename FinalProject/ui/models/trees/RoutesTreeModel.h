#ifndef FINALPROJECT_ROUTESTREEMODEL_H
#define FINALPROJECT_ROUTESTREEMODEL_H

#include <QAbstractItemModel>

#include "TreeItem.h"


class RoutesTreeModel: public  QAbstractItemModel {
    Q_OBJECT
private:
    TreeItem *rootItem;
public:
    explicit RoutesTreeModel(QObject *parent = nullptr);
    ~RoutesTreeModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;


};


#endif //FINALPROJECT_ROUTESTREEMODEL_H
