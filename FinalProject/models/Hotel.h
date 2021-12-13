#ifndef FINALPROJECT_HOTEL_H
#define FINALPROJECT_HOTEL_H

#include <map>
#include <vector>
#include "Room.h"
#include "Address.h"

#include "HotelManager.h"


class Hotel: public Data {
    friend HotelManager;
private:
    QString name;
    QString description;

    Address *address;

    std::vector<Room> rooms;

    Hotel(QString name, QString description, Address *address, int roomsCount);
    Hotel(QString name, QString description, Address *address, std::vector<Room> rooms);

public:
    inline QString getName() const {return this->name;};
    inline QString getDescription() const {return this->description;};
    inline Address *getAddress() const {return this->address;};
    inline int getRoomsCount() const {return this->rooms.size();};

    inline void setName(QString name) {this->name = name;};
    inline void setDescription(QString description) {this->description = description;};


    inline bool operator ==(const Hotel &hotel) const {
        if (this->name == hotel.name && this->address == hotel.address)
            return true;
        return false;
    }
};


#endif //FINALPROJECT_HOTEL_H
