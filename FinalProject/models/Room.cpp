#include <map>
#include <set>

#include <QDate>

#include "Room.h"


Room::Room(RoomTypes roomType, double price) {
    this->roomType = roomType;
    this->price = price;
}

void Room::setSchedule(std::map<QDate, std::set<User*>> schedule) {
    this->schedule = schedule;
}

void Room::order(User *user, QDate ordered_time) {
    QDate now = QDate::currentDate();
    if (now < ordered_time) throw std::exception();

    if (this->schedule.count(ordered_time)) {
        if (this->roomType == RoomTypes::DOUBLE && this->schedule[ordered_time].size() >= 2) throw std::exception();
        this->schedule[ordered_time].insert(user);
    }
}

