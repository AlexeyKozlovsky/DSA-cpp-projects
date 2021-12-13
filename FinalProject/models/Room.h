#ifndef FINALPROJECT_ROOM_H
#define FINALPROJECT_ROOM_H

#include <map>
#include <set>

#include <QDate>

#include "RoomTypes.h"
#include "User.h"

class Room {
private:
    RoomTypes roomType;
    std::map<QDate, std::set<User*>> schedule;
    double price;

public:
    Room(RoomTypes roomType, double price);

    inline std::map<QDate, std::set<User*>> getSchedule() const {
       return this->schedule;
    };

    inline double getPrice() const {
        return this->price;
    }

    void setSchedule(std::map<QDate, std::set<User*>> schedule);

    void order(User *user, QDate ordered_time);
};


#endif //FINALPROJECT_ROOM_H
