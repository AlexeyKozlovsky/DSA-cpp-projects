#include <algorithm>
#include <set>
#include <vector>

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QIODevice>

#include "Place.h"
#include "Hotel.h"
#include "Route.h"
#include "Tour.h"
#include "RouteManager.h"
#include "TourManager.h"

TourManager* TourManager::tourManager_ = nullptr;

Data *TourManager::createTour(QString name, QString description, Route *route, double extraPrice) {
    Tour *tour = new Tour(name, description, route, extraPrice);
    this->addResource(tour);
    return tour;
}

Data *TourManager::createTour(QString name, QString description, std::vector<Place *> cities, std::vector<Hotel *> hotels,
                        int extraPrice) {
    Tour *tour = new Tour(name, description, cities, hotels, extraPrice);
    this->addResource(tour);
    return tour;
}

Data *TourManager::getByName(QString name) {
    std::set<Data *>::iterator tourIter = std::find_if(this->resources.begin(), this->resources.end(),
                                                       [&](const Data *data){
        return ((Tour *)data)->name.toLower() == name.toLower();
    });

    if (tourIter == this->resources.end()) return nullptr;
    return *tourIter;
}

void TourManager::deleteByName(QString name) {

}

void TourManager::parseFromJson(QString jsonPath) {
    RouteManager *routeManager = RouteManager::GetInstance();

    QFile file(jsonPath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData.toUtf8());
    QJsonObject object = document.object();

    QJsonArray toursArray = object.value("tours").toArray();
    foreach (const QJsonValue &v, toursArray) {
        QString name = v.toObject().value("name").toString();
        QString description = v.toObject().value("description").toString();
        QString startDateString = v.toObject().value("startDate").toString();
        QDate date = QDate::fromString(startDateString, "DD-MM-YYYY");

        QString routeName = v.toObject().value("routeName").toString();
        Route *route = (Route *) routeManager->getByName(routeName);
        if (!route) continue;

        Tour *tour = (Tour *) this->createTour(name, description, route, 0);
        tour->startDate = date;
    }

}

TourManager::TourManager() {

}
