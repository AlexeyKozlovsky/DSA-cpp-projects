#include "HotelProxyModel.h"
#include <QDebug>

HotelProxyModel::HotelProxyModel(QObject *parent) : QSortFilterProxyModel(parent) {

}

bool HotelProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
    if (this->searchQuery == "") return true;
    QModelIndex index;
    QVariant value;
    switch (this->filterKind) {
        case FilterKind::NAME:
            index = this->sourceModel()->index(source_row, 0, source_parent);
            value = this->sourceModel()->data(index, Qt::DisplayRole);
            return value.toString().toLower() == this->searchQuery.toLower();
        case FilterKind::DESCRIPTION:
            index = this->sourceModel()->index(source_row, 1, source_parent);
            value = this->sourceModel()->data(index);
            return value.toString().toLower() == this->searchQuery.toLower();
        case FilterKind::PLACE:
            index = this->sourceModel()->index(source_row, 2, source_parent);
            value = this->sourceModel()->data(index);
            return value.toString().toLower() == this->searchQuery.toLower();
    }

    return QSortFilterProxyModel::filterAcceptsRow(source_row, source_parent);
}


