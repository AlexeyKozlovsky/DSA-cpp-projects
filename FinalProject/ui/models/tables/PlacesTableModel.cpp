#include <set>
#include <utility>

#include <QString>
#include <QMap>

#include "PlacesTableModel.h"
#include "PlaceTypes.h"
#include "Data.h"
#include "Place.h"
#include "PlaceManager.h"


PlacesTableModel::PlacesTableModel(QObject *parent) : BaseTableModel(parent) {
    PlaceManager *placeManager = PlaceManager::GetInstance();
    std::set<Data *> places = placeManager->getResources();

    for (Data *data : places) {
        Place *place = (Place *)data;

        std::pair<double, double> location = place->getLocation();
        QMap<QString, QString> currentMap;
        currentMap["name"] = place->getName();
        currentMap["description"] = place->getDescription();
        currentMap["location"] = QString::number(location.first) + ", " + QString::number(location.second);
        currentMap["type"] = (place->getPlaceType() == PlaceTypes::City) ? "City" : "Country";
        this->resources.push_back(currentMap);
        this->resourcePointers.push_back(place);
    }
}

Qt::ItemFlags PlacesTableModel::flags(const QModelIndex &index) const {
    if (index.column() < 2)
        return Qt::ItemFlag::ItemIsEditable | Qt::ItemFlag::ItemIsSelectable | Qt::ItemFlag::ItemIsEnabled;
    return Qt::ItemFlag::ItemIsSelectable | Qt::ItemFlag::ItemIsEnabled;
}

int PlacesTableModel::columnCount(const QModelIndex &index) const {
    return 4;
}

QVariant PlacesTableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
            case 0: return this->resources[index.row()]["name"];
            case 1: return this->resources[index.row()]["description"];
            case 2: return this->resources[index.row()]["location"];
            case 3: return this->resources[index.row()]["type"];
        }
    }
    return QVariant();
}

QVariant PlacesTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
            case 0: return "Название";
            case 1: return "Описание";
            case 2: return "Геолокация";
            case 3: return "Тип";
        }
    }
    return QAbstractItemModel::headerData(section, orientation, role);
}

bool PlacesTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role == Qt::EditRole) {
        Place *place = (Place *) this->resourcePointers[index.row()];
        switch (index.column()) {
            case 0:
                place->setName(value.toString());
                break;
            case 1:
                place->setDescription(value.toString());
                break;
        }
    }
    return QAbstractItemModel::setData(index, value, role);
}



