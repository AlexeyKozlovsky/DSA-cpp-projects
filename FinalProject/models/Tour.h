#ifndef FINALPROJECT_TOUR_H
#define FINALPROJECT_TOUR_H

#include <vector>

#include <QString>
#include <QDate>

#include "Route.h"
#include "Hotel.h"
#include "Room.h"
#include "TourManager.h"

class Tour: public Data {
    friend TourManager;
private:
    QString name;
    QString description;
    QDate startDate;

    std::vector<Hotel*> hotels;

    std::map<User, std::vector<Room>> userRooms;

    Route *route;
    double price;

    Tour(QString name, QString description, Route *route, double extraPrice);
    Tour(QString name, QString description, std::vector<Place*> cities,
         std::vector<Hotel*> hotels, int extraPrice);

public:
    inline double getPrice() const {
        return this->price;
    };

    inline std::vector<Hotel*> getHotels() const {
        return this->hotels;
    };
    inline std::vector<Place*> getCities() const {
        return {};
    };

    inline std::vector<Room*> getRooms(User user) const {
        return {};
    };

    double addDiscount(double percent);
    void addUser(User user, std::vector<Room> rooms);
    void removeUser(User user);
};


#endif //FINALPROJECT_TOUR_H
