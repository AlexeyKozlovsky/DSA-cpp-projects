#ifndef FINALPROJECT_HOTELMANAGER_H
#define FINALPROJECT_HOTELMANAGER_H


#include "Address.h"
#include "Room.h"
#include "Data.h"
#include "ResourceManager.h"


class HotelManager: public ResourceManager {
private:
    static HotelManager *hotelManager_;
public:
    static HotelManager *GetInstance() {
        if (HotelManager::hotelManager_ == nullptr)
            HotelManager::hotelManager_ = new HotelManager();
        return HotelManager::hotelManager_;
    }

    Data *createHotel(QString name, QString description, Address *address, int roomsCount);
    Data *createHotel(QString name, QString description, Address *address, std::vector<Room> rooms);

    std::set<Data *> getHotelsByPlace(QString placeName);
    std::set<Data *> getHotelsByPlace(Place *place);

    void parseFromJson(QString jsonPath) override;
    Data* getByName(QString name) override;
    void deleteByName(QString name) override;
};

#endif //FINALPROJECT_HOTELMANAGER_H
