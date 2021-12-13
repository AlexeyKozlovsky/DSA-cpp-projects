#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QIODevice>

#include "PlaceTypes.h"
#include "Hotel.h"
#include "Place.h"
#include "Data.h"
#include "HotelManager.h"
#include "PlaceManager.h"
#include "Address.h"
#include "Room.h"


HotelManager *HotelManager::hotelManager_ = nullptr;

Data* HotelManager::getByName(QString name) {
    return nullptr;
}

void HotelManager::deleteByName(QString name) {

}

void HotelManager::parseFromJson(QString jsonPath) {
    QFile file(jsonPath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData.toUtf8());
    QJsonObject object = document.object();

    QJsonValue value = object.value("hotels");
    QJsonArray array = value.toArray();

    PlaceManager *placeManager =  PlaceManager::GetInstance();

    foreach (const QJsonValue &v, array) {
        QString name = v.toObject().value("name").toString();
        QString description = v.toObject().value("description").toString();

        QJsonValue countryValue = v.toObject().value("address").toObject().value("country");
        QJsonValue cityValue = v.toObject().value("address").toObject().value("city");

        QString cityName = cityValue.toObject().value("name").toString();
        Place *city = (Place *)placeManager->getPlaceByName(cityName, PlaceTypes::City);

        QString streetName = v.toObject().value("address").toObject().value("streetName").toString();
        QString house = v.toObject().value("address").toObject().value("house").toString();

        if (city) {
            if (!city->getParentPlace()) {
                QString countryName = countryValue.toObject().value("name").toString();
                QString countryDescription = countryValue.toObject().value("description").toString();

                QJsonArray countryLocationArray = countryValue.toObject().value("location").toArray();
                std::pair<double, double> countryLocation = {
                        countryLocationArray[0].toDouble(),
                        countryLocationArray[1].toDouble()
                };

                Place *country = (Place *)placeManager->createPlace(countryName, countryDescription, countryLocation,
                                                                    PlaceTypes::Country);
                city->setParentPlace(country);
            }
        } else {
            QString cityName = cityValue.toObject().value("name").toString();
            QString cityDescription = cityValue.toObject().value("description").toString();
            QJsonArray cityLocationArray = cityValue.toObject().value("location").toArray();

            std::pair<double, double> cityLocation = {
                    cityLocationArray[0].toDouble(),
                    cityLocationArray[1].toDouble()
            };

            QString countryName = countryValue.toObject().value("name").toString();
            Place *country = (Place *) placeManager->getPlaceByName(countryName, PlaceTypes::Country);
            if (!country) {
                QString countryDescription = countryValue.toObject().value("description").toString();
                QJsonArray countryLocationArray = countryValue.toObject().value("location").toArray();

                std::pair<double, double> countryLocation {
                    countryLocationArray[0].toDouble(),
                    countryLocationArray[1].toDouble()
                };

                country = (Place *) placeManager->createPlace(countryName, countryDescription,
                                                              countryLocation, PlaceTypes::Country);
            }
            city = (Place *) placeManager->createPlace(cityName, cityDescription, cityLocation, PlaceTypes::City);
            city->setParentPlace(country);
        }

        Address *address = new Address(city, streetName, house);


        int roomsCount = v.toObject().value("roomsCount").toInt();
        this->createHotel(name, description, address, roomsCount);
    }
}

Data *HotelManager::createHotel(QString name, QString description, Address *address, int roomsCount) {
    Hotel *hotel = new Hotel(name, description, address, roomsCount);
    this->addResource(hotel);
    return hotel;
}

Data *HotelManager::createHotel(QString name, QString description, Address *address, std::vector<Room> rooms) {
    Hotel *hotel = new Hotel(name, description, address, rooms);
    this->addResource(hotel);
    return hotel;
}
