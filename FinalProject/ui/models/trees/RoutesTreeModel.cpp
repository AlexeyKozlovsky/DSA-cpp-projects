#include <QDebug>

#include "Route.h"
#include "User.h"
#include "RouteManager.h"
#include "RoutesTreeModel.h"


RoutesTreeModel::RoutesTreeModel(QObject *parent) : QAbstractItemModel(parent) {
    this->rootItem = new TreeItem;
    RouteManager *routeManager = RouteManager::GetInstance();
    std::set<Data*> resources = routeManager->getResources();

    for (Data *resource : resources) {
        Route *route = (Route *)resource;
        TreeItem *routeTreeItem = new TreeItem(route, this->rootItem);
        std::vector<std::pair<Place*, Hotel*>> routePoints = route->getRoutePoints();
        for (const std::pair<Place*, Hotel*> &routePoint : routePoints) {
            TreeItem *placeTreeItem = new TreeItem(routePoint.first, routeTreeItem);
            //TreeItem *hotelTreeItem = new TreeItem(routePoint.second, routeTreeItem);
        }
    }
}

RoutesTreeModel::~RoutesTreeModel() {
    delete this->rootItem;
}

int RoutesTreeModel::rowCount(const QModelIndex &parent) const {
    TreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid()) parentItem = this->rootItem;
    else parentItem = static_cast<TreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int RoutesTreeModel::columnCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return static_cast<TreeItem *>(parent.internalPointer())->columnCount();
    return this->rootItem->columnCount();
}

Qt::ItemFlags RoutesTreeModel::flags(const QModelIndex &index) const {
    if (!index.isValid()) return Qt::NoItemFlags;
    return QAbstractItemModel::flags(index);
}

QModelIndex RoutesTreeModel::parent(const QModelIndex &child) const {
    if (!child.isValid()) return QModelIndex();

    TreeItem *childItem = static_cast<TreeItem*>(child.internalPointer());
    TreeItem *parentItem = childItem->parent();

    if (parentItem == this->rootItem) return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

QModelIndex RoutesTreeModel::index(int row, int column, const QModelIndex &parent) const {
    if (!hasIndex(row, column, parent)) return QModelIndex();

    TreeItem *parentItem;
    if (!parent.isValid()) parentItem = this->rootItem;
    else parentItem = static_cast<TreeItem*>(parent.internalPointer());

    TreeItem *childItem = parentItem->child(row);
    if (childItem) return createIndex(row, column, childItem);
    return QModelIndex();
}

QVariant RoutesTreeModel::data(const QModelIndex &index, int role) const {
//    qDebug() << "DATA";
    if (!index.isValid() || role != Qt::DisplayRole) return QVariant();

    qDebug() << index;
    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
    //qDebug() << item->data(index.column());
    return item->data(index.column());
}

QVariant RoutesTreeModel::headerData(int section, Qt::Orientation orientation, int role) const {
//    if (orientation != Qt::Horizontal || role != Qt::DisplayRole) return QVariant();
//    switch (section) {
//        case 1: return "Свойство";
//        case 2: return "Значение";
//    }

    return QAbstractItemModel::headerData(section, orientation, role);
}
