#ifndef FINALPROJECT_ADDRESS_H
#define FINALPROJECT_ADDRESS_H

#include <QString>
#include "Place.h"
//#include "HotelManager.h"


class Address {
//    friend HotelManager;
private:
    Place *city;
    Place *country;
    QString streetName;
    QString house;

public:
    Address(QString cityName);
    Address(Place *country);
    Address(QString cityName, QString streetName, QString house);
    Address(Place *city, QString streetName, QString house);

    QString getStringAddress();

    inline QString getPlaceName() const {
        return this->city->getName();
    };

    // ------------OPERATORS---------------
    inline bool operator ==(const Address &address) const {
        if (this->country == address.country && this->city == address.city && this->streetName == address.streetName &&
            this->house == address.house) return true;
        return false;
    }
};


#endif //FINALPROJECT_ADDRESS_H
