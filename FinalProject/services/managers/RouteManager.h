#ifndef FINALPROJECT_ROUTEMANAGER_H
#define FINALPROJECT_ROUTEMANAGER_H

#include "ResourceManager.h"
#include "Data.h"
#include "Place.h"
#include "Hotel.h"

class RouteManager: public ResourceManager {
private:
    static RouteManager *routeManager_;
public:
    static RouteManager *GetInstance() {
        if (RouteManager::routeManager_ == nullptr)
            RouteManager::routeManager_ = new RouteManager();
        return RouteManager::routeManager_;
    }
    Data* createRoute(QString name, QString description, std::vector<Place*> places);
    Data* createRoute(QString name, QString description, std::vector<Hotel*> hotels);

    Data * getByName(QString name) override;
    void deleteByName(QString name) override;

    void parseFromJson(QString jsonPath) override;
};


#endif //FINALPROJECT_ROUTEMANAGER_H
