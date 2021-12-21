#include "PlaceProxyModel.h"


PlaceProxyModel::PlaceProxyModel(QObject *parent) : QSortFilterProxyModel(parent) {

}

bool PlaceProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
    return QSortFilterProxyModel::filterAcceptsRow(source_row, source_parent);
}


