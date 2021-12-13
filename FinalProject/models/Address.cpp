#include <QString>

#include "PlaceTypes.h"
#include "Place.h"
#include "PlaceManager.h"
#include "Address.h"


QString Address::getStringAddress() {
    return QString();
}

Address::Address(QString cityName) {
    PlaceManager *placeManager = PlaceManager::GetInstance();
    Place *place = (Place *) placeManager->getPlaceByName(cityName, PlaceTypes::City);
    if (!place) throw std::exception();

    this->city = place;
    this->country = place->getParentPlace();
}

Address::Address(Place *country) {
    this->country = country;
}

Address::Address(QString cityName, QString streetName, QString house) {
    PlaceManager *placeManager = PlaceManager::GetInstance();
    Place *place = (Place *) placeManager->getPlaceByName(cityName, PlaceTypes::City);
    this->city = place;
    this->country = place->getParentPlace();
    this->streetName = streetName;
    this->house = house;
}

Address::Address(Place *city, QString streetName, QString house) {
    this->city = city;
    this->streetName = streetName;
    this->house = house;
}
