#ifndef FINALPROJECT_ROOM_H
#define FINALPROJECT_ROOM_H

#include <map>
#include <ctime>

#include "RoomTypes.h"
#include "User.h"

class Room {
private:
    RoomTypes roomType;
    std::map<std::time_t, int> schedule;
    double price;

public:
    Room(RoomTypes roomType, double price);

    void setSchedule(std::map<std::time_t, int> schedule);
    std::map<std::time_t, int> getSchedule();
    int order(User user);
};


#endif //FINALPROJECT_ROOM_H
