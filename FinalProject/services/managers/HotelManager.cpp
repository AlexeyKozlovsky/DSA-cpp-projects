#include "Hotel.h"
#include "Data.h"
#include "HotelManager.h"
#include "Address.h"
#include "Room.h"


HotelManager *HotelManager::hotelManager_ = nullptr;

Data* HotelManager::getByName(QString name) {
    return nullptr;
}

void HotelManager::deleteByName(QString name) {

}

void HotelManager::parseFromJson(QString jsonPath) {

}

Data *HotelManager::createHotel(QString name, QString description, Address *address, int roomsCount) {
    Hotel *hotel = new Hotel(name, description, address, roomsCount);
    this->addResource(hotel);
    return hotel;
}

Data *HotelManager::createHotel(QString name, QString description, Address *address, std::vector<Room*> rooms) {
    Hotel *hotel = new Hotel(name, description, address, rooms);
    this->addResource(hotel);
    return hotel;
}
