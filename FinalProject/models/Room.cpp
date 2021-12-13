#include <ctime>
#include <map>
#include <set>

#include "Room.h"


Room::Room(RoomTypes roomType, double price) {
    this->roomType = roomType;
    this->price = price;
}

void Room::setSchedule(std::map<std::time_t, std::set<User*>> schedule) {
    this->schedule = schedule;
}

void Room::order(User *user, std::time_t ordered_time) {
    std::time_t t = std::time(0);
    if (t < ordered_time) throw std::exception();

    if (this->schedule.count(ordered_time)) {
        if (this->roomType == RoomTypes::DOUBLE && this->schedule[ordered_time].size() >= 2) throw std::exception();
        this->schedule[ordered_time].insert(user);
    }
}

