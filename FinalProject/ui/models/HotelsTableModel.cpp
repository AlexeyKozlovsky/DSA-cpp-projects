#include <set>

#include <QAbstractTableModel>
#include <QDebug>

#include "Hotel.h"
#include "HotelManager.h"
#include "HotelsTableModel.h"

HotelsTableModel::HotelsTableModel(QObject *parent) : BaseTableModel(parent) {
    HotelManager *hotelManager = HotelManager::GetInstance();
    std::set<Data *> hotelsData = hotelManager->getResources();

    for (const Data *data : hotelsData) {
        Hotel *hotel = (Hotel *)data;
        QMap<QString, QString> currentHotelMap;
        currentHotelMap["name"] = hotel->getName();
        currentHotelMap["description"] = hotel->getDescription();
        currentHotelMap["placeName"] = hotel->getAddress()->getPlaceName();
        currentHotelMap["roomsCount"] = hotel->getRoomsCount();
        this->resources.push_back(currentHotelMap);
        this->resourcePointers.push_back(hotel);
    }
}

Qt::ItemFlags HotelsTableModel::flags(const QModelIndex &index) const {
    if (index.column() < 2)
        return Qt::ItemFlag::ItemIsSelectable | Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsEditable;
    return Qt::ItemFlag::ItemIsSelectable | Qt::ItemFlag::ItemIsEnabled;
}

int HotelsTableModel::columnCount(const QModelIndex &index) const {
    return 4;
}

QVariant HotelsTableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
            case 0:
                return this->resources[index.row()]["name"];
            case 1:
                return this->resources[index.row()]["description"];
            case 2:
                return this->resources[index.row()]["placeName"];
            case 3:
                return this->resources[index.row()]["roomsCount"];
        }
    }

    return QVariant();
}

QVariant HotelsTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
            case 0:
                return QString("Название");
            case 1:
                return QString("Описание");
            case 2:
                return QString("Место");
            case 3:
                return QString("Количество комнат");
        }
    }

    return QVariant();
}

bool HotelsTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role == Qt::EditRole) {
        switch (index.column()) {
            case 0:
                ((Hotel *)this->resourcePointers[index.row()])->setName(value.toString());
                this->resources[index.row()]["name"] = value.toString();
                break;
            case 1:
                ((Hotel *)this->resourcePointers[index.row()])->setDescription(value.toString());
                this->resources[index.row()]["description"] = value.toString();
                break;
        }
    }

    return true;
}
