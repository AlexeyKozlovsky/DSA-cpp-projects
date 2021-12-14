#include <set>
#include <vector>

#include "BaseTableModel.h"
#include "UsersTableModel.h"
#include "Data.h"
#include "User.h"
#include "UserManager.h"


UsersTableModel::UsersTableModel(QObject *parent) : BaseTableModel(parent) {
    UserManager *userManager = UserManager::GetInstance();
    std::set<Data *> users = userManager->getResources();

    for (Data *data : users) {
        User *user = (User *)data;
        QMap<QString, QString> currentMap;
        currentMap["firstName"] = user->getFirstName();
        currentMap["secondName"] = user->getSecondName();
        currentMap["patronymic"] = user->getPatronymic();
        currentMap["email"] = user->getEmail();
        currentMap["phone"] = user->getPhone();
        currentMap["address"] = user->getStringAddress();

        this->resources.push_back(currentMap);
        this->resourcePointers.push_back(user);
    }
}


Qt::ItemFlags UsersTableModel::flags(const QModelIndex &index) const {
    if (index.column() < 5)
        return Qt::ItemFlag::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemFlag::ItemIsEditable;
    return QAbstractTableModel::flags(index);
}

int UsersTableModel::columnCount(const QModelIndex &index) const {
    return 6;
}

QVariant UsersTableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
            case 0:
                return this->resources[index.row()]["firstName"];
            case 1:
                return this->resources[index.row()]["secondName"];
            case 2:
                return this->resources[index.row()]["patronymic"];
            case 3:
                return this->resources[index.row()]["email"];
            case 4:
                return this->resources[index.row()]["phone"];
            case 5:
                return this->resources[index.row()]["address"];
        }
    }
    return QVariant();
}

QVariant UsersTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
            case 0:
                return "Имя";
            case 1:
                return "Фамилия";
            case 2:
                return "Отчество";
            case 3:
                return "Email";
            case 4:
                return "Телефон";
            case 5:
                return "Адрес";
        }
    }
    return QAbstractItemModel::headerData(section, orientation, role);
}

bool UsersTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role == Qt::EditRole) {
        User *user = (User *) this->resourcePointers[index.row()];
        switch (index.column()) {
            case 0:
                user->firstName = value.toString();
                this->resources[index.row()]["firstName"] = value.toString();
                break;
            case 1:
                user->secondName = value.toString();
                this->resources[index.row()]["secondName"] = value.toString();
                break;
            case 2:
                user->patronymic = value.toString();
                this->resources[index.row()]["patronymic"] = value.toString();
                break;
            case 3:
                user->email = value.toString();
                this->resources[index.row()]["email"] = value.toString();
                break;
            case 4:
                user->phone = value.toString();
                this->resources[index.row()]["phone"] = value.toString();
                break;
        }
    }
    return QAbstractItemModel::setData(index, value, role);
}

