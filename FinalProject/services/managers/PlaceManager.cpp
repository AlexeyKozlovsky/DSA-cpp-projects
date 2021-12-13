#include <utility>
#include <algorithm>
#include <iterator>

#include <QDebug>
#include <QFile>
#include <QString>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include "PlaceManager.h"
#include "PlaceTypes.h"
#include "Place.h"
#include "Data.h"

PlaceManager* PlaceManager::placeManager_ = nullptr;

Data *PlaceManager::createPlace(QString name, QString description, std::pair<double, double> location, PlaceTypes placeType) {
    Place *place = new Place(name, description, location);
    place->placeType = placeType;
    this->addResource(place);
    return place;
}

Data *PlaceManager::createPlace(QString name, QString description, std::pair<double, double> location, QString placeType) {
    Place *place = new Place(name, description, location);
    if (placeType.toLower() == "city")
        place->placeType = PlaceTypes::City;
    else if (placeType.toLower() == "country")
        place->placeType = PlaceTypes::Country;
    else if (placeType.toLower() == "continent")
        place->placeType = PlaceTypes::Continent;

    this->addResource(place);
    return place;
}

Data *PlaceManager::getByName(QString name) {
    return nullptr;
}

void PlaceManager::deleteByName(QString name) {

}


void PlaceManager::parseFromJson(QString jsonPath) {
    QFile file(jsonPath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData.toUtf8());
    QJsonObject object = document.object();

    QJsonValue value = object.value("cities");
    QJsonArray array = value.toArray();

    foreach (const QJsonValue &v, array) {
        QString name = v.toObject().value("name").toString();
        QString description = v.toObject().value("description").toString();

        QJsonArray locationArray = v.toObject().value("location").toArray();
        std::pair<double, double> location = {
                locationArray[0].toDouble(),
                locationArray[1].toDouble()
        };

        Place *currentCity = new Place(name, description, location, PlaceTypes::City);

        QJsonObject countryObj = v.toObject().value("country").toObject();

        if (countryObj.isEmpty()) continue;
        QString countryName = countryObj.value("name").toString();
        QString countryDescription = countryObj.value("description").toString();

        QJsonArray countryLocationArray = countryObj.value("location").toArray();
        std::pair<double, double> countryLocation = {
                countryLocationArray[0].toDouble(),
                countryLocationArray[1].toDouble()
        };

        Place *currentCountry = new Place(countryName, countryDescription,
                                          countryLocation, PlaceTypes::Country);

        currentCity->setParentPlace(currentCountry);
        this->addResource(currentCity);
        this->addResource(currentCountry);
    }
}

Data *PlaceManager::getPlaceByName(QString name) {
    std::set<Data *>::iterator resultIter = std::find_if(this->resources.begin(), this->resources.end(),
                                                         [&](const Data *data) {
        return ((Place *)data)->name.toLower() == name.toLower();
    });
    return *resultIter;
}

Data *PlaceManager::getPlaceByName(QString name, PlaceTypes placeType) {
    std::set<Data *>::iterator resultIter = std::find_if(this->resources.begin(), this->resources.end(),
                                                          [&](const Data *data){
        return ((Place *)data)->name.toLower() == name.toLower() &&
                ((Place *)data)->placeType == placeType;
    });
    if (resultIter == this->resources.end()) return nullptr;
    return *resultIter;
}

std::set<Data *> PlaceManager::getPlacesByName(QString name) {
    std::set<Data *> resultSet;
    std::copy_if(this->resources.begin(), this->resources.end(),
                 std::inserter(resultSet, resultSet.end()),
                 [&](const Data *data) {return ((Place *)data)->name.toLower() == name.toLower();});
    return resultSet;
}

std::set<Data *> PlaceManager::getPlacesByType(PlaceTypes placeType) {
    std::set<Data *> resultSet;
    std::copy_if(this->resources.begin(), this->resources.end(),
                 std::inserter(resultSet, resultSet.end()),
                 [&](const Data *data) {return ((Place *)data)->placeType == placeType;});
    return resultSet;
}

std::set<Data *> PlaceManager::getPlacesByLocation(double altitude, double longitude, double radius) {
    std::set<Data *> resultSet;
    std::copy_if(this->resources.begin(), this->resources.end(),
                 std::inserter(resultSet, resultSet.end()),
                 [&](const Data *data) {
        Place *place = (Place *)data;
        if ((place->location.first <= altitude + radius && place->location.first >= altitude - radius) &&
                (place->location.second <= longitude + radius && place->location.second >= longitude - radius))
            return true;
        return false;
    });
    return resultSet;
}

std::set<Data *> PlaceManager::getPlacesByLocation(std::pair<double, double> location, double radius) {
    return this->getPlacesByLocation(location.first, location.second, radius);
}

std::set<Data *> PlaceManager::getPlacesByLocation(Data *centerPlace, double radius) {
    std::pair<double, double> location = ((Place *)centerPlace)->location;
    if (location.first || location.second)
        return this->getPlacesByLocation(location, radius);
    return {};
}

std::set<Data *> PlaceManager::getLocatedPlaces() {
    std::set<Data *> resultSet;
    std::copy_if(this->resources.begin(), this->resources.end(),
                 std::inserter(resultSet, resultSet.end()),
                 [&](const Data *data) {
        std::pair<double, double> location = ((Place *)data)->location;
        if (location.first || location.second) return true;
        return false;
    });
    return resultSet;
}

std::set<Data *> PlaceManager::getCitiesByCountry(QString countryName) {
    std::set<Data *> resultSet;
    std::copy_if(this->resources.begin(), this->resources.end(),
                 std::inserter(resultSet, resultSet.end()),
                 [&](const Data *data){
        if (!((Place *)data)->parentPlace) return false;
        QString currentName = ((Place *)data)->parentPlace->name;
        if (currentName.toLower() == countryName.toLower()) return true;
        return false;
    });
    return resultSet;
}

std::set<Data *> PlaceManager::getCitiesByCountry(Data *country) {
    return this->getCitiesByCountry(((Place *)country)->name);
}
