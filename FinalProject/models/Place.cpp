#include "Place.h"


Place::Place(QString name, QString description, std::pair<double, double> location, Place *parentPlace) {
    this->name = name;
    this->description = description;
    this->location = location;

    this->parentPlace;
}

Place::Place(QString name, QString description, std::pair<double, double> location, PlaceTypes placeType, Place *parentPlace) {
    this->name = name;
    this->description = description;
    this->location = location;
    this->placeType = placeType;

    this->parentPlace;
}
