#include "RoomTypes.h"
#include "Room.h"
#include "Hotel.h"


Hotel::Hotel(QString name, QString description, Address *address, int roomsCount) {
    this->name = name;
    this->description = description;
    this->address = address;

    for (int i = 0; i < roomsCount; i++) {
        Room room(RoomTypes::DOUBLE, 200);
        this->rooms.push_back(room);
    }
}

Hotel::Hotel(QString name, QString description, Address *address, std::vector<Room> rooms) {

}
