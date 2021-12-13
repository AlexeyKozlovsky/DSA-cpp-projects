#include <utility>
#include <vector>

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QIODevice>


#include "PlaceTypes.h"
#include "Data.h"
#include "Place.h"
#include "Route.h"
#include "PlaceManager.h"
#include "HotelManager.h"
#include "RouteManager.h"


RouteManager *RouteManager::routeManager_ = nullptr;

Data *RouteManager::createRoute(QString name, QString description, std::vector<Place*> places) {
    Route *route = new Route(name, description, places);
    this->addResource(route);
    return route;
}

Data *RouteManager::createRoute(QString name, QString description, std::vector<Hotel*> hotels) {
    Route *route = new Route(name, description, hotels);
    this->addResource(route);
    return route;
}

Data *RouteManager::createRoute(QString name, QString description, std::vector<std::pair<Place *, Hotel *>> routePoints) {
    Route *route = new Route(name, description, routePoints);
    this->addResource(route);
    return route;
}


Data *RouteManager::getByName(QString name) {
    std::set<Data *>::iterator routeIter = std::find_if(this->resources.begin(), this->resources.end(),
                                                        [&](const Data *data) {
        return ((Route *)data)->name == name;
    });

    if (routeIter == this->resources.end()) return nullptr;
    return *routeIter;
}

void RouteManager::deleteByName(QString name) {

}

void RouteManager::parseFromJson(QString jsonPath) {
    PlaceManager *placeManager = PlaceManager::GetInstance();
    HotelManager *hotelManager = HotelManager::GetInstance();

    QFile file(jsonPath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData.toUtf8());
    QJsonObject object = document.object();

    QJsonArray routesArray = object.value("routes").toArray();

    foreach (const QJsonValue &v, routesArray) {
        Place *place;
        QString name = v.toObject().value("name").toString();
        QString description = v.toObject().value("description").toString();

        QJsonArray placesArray = v.toObject().value("places").toArray();

        std::vector<std::pair<Place*, Hotel*>> placeHotelPairs;
        foreach (const QJsonValue &placeValue, placesArray) {
            QString placeName = placeValue.toObject().value("name").toString();
            place = (Place *) placeManager->getPlaceByName(placeName, PlaceTypes::City);
            if (!place) {
                QString placeDescription = placeValue.toObject().value("description").toString();
                QJsonArray placeLocationArray = placeValue.toObject().value("location").toArray();

                std::pair<double, double> placeLocation = {
                        placeLocationArray[0].toDouble(),
                        placeLocationArray[1].toDouble()
                };

                place = (Place *) placeManager->createPlace(placeName, placeDescription,
                                                            placeLocation, PlaceTypes::City);
            }

            Hotel *hotel = nullptr;
            std::set<Data *> hotels = hotelManager->getHotelsByPlace(placeName);
            if (!hotels.empty()) hotel = (Hotel *) *hotels.begin();

            std::pair<Place*, Hotel*> placeHotelPair = {
                    place, hotel
            };

            placeHotelPairs.push_back(placeHotelPair);
        }

        this->createRoute(name, description, placeHotelPairs);
    }
}
