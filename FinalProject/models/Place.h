#ifndef FINALPROJECT_PLACE_H
#define FINALPROJECT_PLACE_H

#include <utility>
#include <QString>

#include "Data.h"
#include "PlaceTypes.h"
#include "PlaceManager.h"


class Place: public Data {
    friend PlaceManager;
protected:
    std::pair<double, double> location;
    QString name;
    QString description;
    PlaceTypes placeType;

    Place *parentPlace;

    Place(QString name, QString description, std::pair<double, double> location, Place *parentPlace = nullptr);
    Place(QString name, QString description, std::pair<double, double> location, PlaceTypes placeType,
          Place *parentPlace = nullptr);

public:
    inline QString getName() const {return this->name;};
    inline QString getDescription() const {return this->description;};
    inline PlaceTypes getPlaceType() const {return this->placeType;};
    inline std::pair<double, double> getLocation() const {return this->location;};

    inline void setParentPlace(Place *parentPlace) {this->parentPlace = parentPlace;};
    inline Place *getParentPlace(Place *parentPlace) {return this->parentPlace;};

    inline bool operator ==(const Place &place) const {
        if (this->location == place.location && this->placeType == place.placeType)
            return true;
        return false;
    };
};


#endif //FINALPROJECT_PLACE_H
