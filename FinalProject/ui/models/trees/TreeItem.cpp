#include <typeinfo>

#include <QDebug>

#include "User.h"
#include "Place.h"
#include "Hotel.h"
#include "Route.h"
#include "Tour.h"
#include "TreeItem.h"


TreeItem::TreeItem(Data *data, TreeItem *parent) {
    this->itemData = data;
    this->parentItem = parent;
    this->parentItem->appendChild(this);
}

TreeItem::~TreeItem() {
    qDeleteAll(this->childItems);
}

void TreeItem::appendChild(TreeItem *child) {
    this->childItems.append(child);
}

TreeItem *TreeItem::child(int row) {
    if (row < 0 || row >= this->childItems.size()) return nullptr;
    return this->childItems[row];
}

int TreeItem::childCount() const {
    return this->childItems.count();
}

// TODO: Дописать корректный метод для того, чтобы посчитать количество колонок
int TreeItem::columnCount() const {
    if (!this) return 1;
    if (this->itemData == nullptr) return 1;
    if (dynamic_cast<Tour*>(this->itemData)) qDebug() << "TOUR";
    else if (dynamic_cast<User*>(this->itemData)) qDebug() << "USER";
    else if (dynamic_cast<Route*>(this->itemData)) return 2;
    else if (dynamic_cast<Place*>(this->itemData)) qDebug() << "PLACE";
    else if (dynamic_cast<Hotel*>(this->itemData)) qDebug() << "HOTEL";
//
//    if (typeid(this->itemData) == typeid(Tour)) {
//        qDebug() << "TILT";
//        return 4;
//    }
//    else if (typeid(this->itemData) == typeid(User))
//        return 3;
//    else if (typeid(this->itemData) == typeid(Route))
//        return 2;
//    else if (typeid(this->itemData) == typeid(Place))
//        return 3;
//    else if (typeid(this->itemData) == typeid(Hotel))
//        return 3;
//    qDebug() << "Tilt: " + QString(typeid(this->itemData).name());
    return 1;
}

QVariant TreeItem::data(int column) const {
    if (typeid(this->itemData) == typeid(Tour)) {
        Tour *tour = (Tour *)this->itemData;
        switch (column) {
            case 0: return tour->getName();
            case 1: return tour->getDescription();
            case 2: return tour->getStartDate();
            case 3: return tour->getPrice();
        }
    } else if (typeid(this->itemData) == typeid(User)) {
        User *user = (User *)this->itemData;
        switch (column) {
            case 0: return user->getFullName();
            case 1: return user->getEmail();
            case 2: return user->getPhone();
        }
    } else if (dynamic_cast<Route*>(this->itemData)) {
        Route *route = (Route *)this->itemData;
        switch (column) {
            case 0: return route->getName();
            case 1: return route->getDescription();
        }
    } else if (dynamic_cast<Place*>(this->itemData)) {
        Place *place = (Place *)this->itemData;
        switch (column) {
            case 0: return place->getName();
            case 1: return place->getDescription();
            case 2: return place->getPlaceType();
        }
    } else if (typeid(this->itemData) == typeid(Hotel)) {
        Hotel *hotel = (Hotel *)this->itemData;
        switch (column) {
            case 0: return hotel->getName();
            case 1: return hotel->getDescription();
            case 2: return QString::number(hotel->getRoomsCount());
        }
    }

    return QVariant();
}

int TreeItem::row() const {
    if (this->parentItem)
        return parentItem->childItems.indexOf(const_cast<TreeItem*>(this));
    return 0;
}

TreeItem *TreeItem::parent() {
    return this->parentItem;
}

TreeItem::TreeItem() {
    this->itemData = nullptr;
}

