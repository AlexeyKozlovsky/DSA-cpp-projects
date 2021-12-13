#ifndef FINALPROJECT_TOURMANAGER_H
#define FINALPROJECT_TOURMANAGER_H

#include "ResourceManager.h"
#include "Data.h"
#include "Route.h"
#include "Hotel.h"


class TourManager: public ResourceManager {
private:
    static TourManager *tourManager_;
    TourManager();
public:
    TourManager(TourManager &other) = delete;
    void operator=(const TourManager &) = delete;

    static TourManager *GetInstance() {
        if (TourManager::tourManager_ == nullptr)
            TourManager::tourManager_ = new TourManager();
        return TourManager::tourManager_;
    }

    Data *createTour(QString name, QString description, Route *route, double extraPrice);
    Data *createTour(QString name, QString description, std::vector<Place*> cities,
                     std::vector<Hotel*> hotels, int extraPrice);

    Data * getByName(QString name) override;
    void deleteByName(QString name) override;
    void parseFromJson(QString jsonPath) override;
};


#endif //FINALPROJECT_TOURMANAGER_H
