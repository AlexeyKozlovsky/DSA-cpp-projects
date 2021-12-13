#include "RouteManager.h"
#include "Route.h"
#include "Data.h"

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

Data *RouteManager::getByName(QString name) {
    return nullptr;
}

void RouteManager::deleteByName(QString name) {

}

void RouteManager::parseFromJson(QString jsonPath) {

}
