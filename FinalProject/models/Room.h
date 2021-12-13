#ifndef FINALPROJECT_ROOM_H
#define FINALPROJECT_ROOM_H

#include <map>
#include <set>
#include <ctime>

#include "RoomTypes.h"
#include "User.h"

class Room {
private:
    RoomTypes roomType;
    std::map<std::time_t, std::set<User*>> schedule;
    double price;

public:
    Room(RoomTypes roomType, double price);

    inline std::map<std::time_t, std::set<User*>> getSchedule() const {
       return this->schedule;
    };

    inline double getPrice() const {
        return this->price;
    }

    void setSchedule(std::map<std::time_t, std::set<User*>> schedule);

    void order(User *user, std::time_t ordered_time);
};


#endif //FINALPROJECT_ROOM_H
