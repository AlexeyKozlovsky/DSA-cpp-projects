#ifndef FINALPROJECT_PLACEMANAGER_H
#define FINALPROJECT_PLACEMANAGER_H

#include <utility>
#include <QString>

#include "PlaceTypes.h"
#include "ResourceManager.h"


class PlaceManager: public ResourceManager {
private:
    static PlaceManager *placeManager_;

    PlaceManager() = default;
public:
    static PlaceManager *GetInstance() {
        if (PlaceManager::placeManager_ == nullptr)
            PlaceManager::placeManager_ = new PlaceManager();
        return PlaceManager::placeManager_;
    }

    Data * getByName(QString name) override;
    void deleteByName(QString name) override;


    void parseFromJson(QString jsonPath) override;

    Data *createPlace(QString name, QString description, std::pair<double, double> location, QString placeType);


    std::set<Data *> getPlacesByName(QString name);
    std::set<Data *> getPlacesByType(PlaceTypes placeType);
    std::set<Data *> getPlacesByLocation(double altitude, double longitude, double radius);
    std::set<Data *> getPlacesByLocation(std::pair<double, double> location, double radius);
    std::set<Data *> getPlacesByLocation(Data *centerPlace, double radius);
};


#endif //FINALPROJECT_PLACEMANAGER_H
