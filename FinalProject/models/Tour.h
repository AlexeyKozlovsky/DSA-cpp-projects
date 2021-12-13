#ifndef FINALPROJECT_TOUR_H
#define FINALPROJECT_TOUR_H

#include <ctime>
#include <QString>
#include <vector>

#include "Route.h"
#include "Hotel.h"
#include "Room.h"

class Tour: public Data {
private:
    QString name;
    QString description;
    std::time_t startDate;

    std::vector<Hotel> hotels;

    std::map<User, std::vector<Room>> userRooms;

    Route route;
    double price;

public:
    Tour(QString name, QString description, Route *route, double extraPrice);
    Tour(QString name, QString description, std::vector<Place*> cities,
         std::vector<Hotel*> hotels, int extraPrice);

    double getPrice();
    double addDiscount(double percent);
    std::vector<Hotel*> getHotels();
    std::vector<Place*> getCities();
    std::vector<Room*> getRooms(User user);

    void addUser(User user, std::vector<Room> rooms);
    void removeUser(User user);
};


#endif //FINALPROJECT_TOUR_H
