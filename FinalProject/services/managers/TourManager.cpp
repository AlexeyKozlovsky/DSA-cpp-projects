#include "TourManager.h"
#include "Route.h"
#include "Place.h"
#include "Hotel.h"

TourManager* TourManager::tourManager_ = nullptr;

Data *TourManager::createTour(QString name, QString description, Route *route, double extraPrice) {
    return nullptr;
}

Data *
TourManager::createTour(QString name, QString description, std::vector<Place *> cities, std::vector<Hotel *> hotels,
                        int extraPrice) {
    return nullptr;
}

Data *TourManager::getByName(QString name) {
    return nullptr;
}

void TourManager::deleteByName(QString name) {

}

void TourManager::parseFromJson(QString jsonPath) {

}
