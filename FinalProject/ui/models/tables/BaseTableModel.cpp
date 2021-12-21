#include "BaseTableModel.h"


BaseTableModel::BaseTableModel(QObject *parent) : QAbstractTableModel(parent) {

}


int BaseTableModel::rowCount(const QModelIndex &index) const {
    return this->resources.size();
}


