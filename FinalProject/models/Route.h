#ifndef FINALPROJECT_ROUTE_H
#define FINALPROJECT_ROUTE_H

#include <QString>
#include <vector>
#include <utility>

#include "Data.h"
#include "Hotel.h"
#include "Place.h"
#include "RouteManager.h"


class Route: public Data{
    friend RouteManager;
private:
    QString name;
    QString description;

    std::vector<std::pair<Place*, Hotel*>> routePoints;

    Route(QString name, QString description, std::vector<Place*> places);
    Route(QString name, QString description, std::vector<Hotel*> hotels);
    Route(QString name, QString description, std::vector<std::pair<Place*, Hotel*>> routePoints);
    Route(QString name, QString description, std::vector<Place*> places, std::vector<Hotel> hotels);

public:
    inline QString getName() const {return this->name;};
    inline QString getDescription() const {return this->description;};
    inline std::vector<std::pair<Place*, Hotel*>> getRoutePoints() const {return this->routePoints;};
};


#endif //FINALPROJECT_ROUTE_H
