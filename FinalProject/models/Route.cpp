#include "Route.h"

Route::Route(QString name, QString description, std::vector<Hotel *> hotels) {

}

Route::Route(QString name, QString description, std::vector<Place *> places) {

}

Route::Route(QString name, QString description, std::vector<std::pair<Place *, Hotel *>> routePoints) {
    this->name = name;
    this->description = description;
    this->routePoints = routePoints;
}
