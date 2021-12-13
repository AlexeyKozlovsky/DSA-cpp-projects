#ifndef FINALPROJECT_CLIENT_H
#define FINALPROJECT_CLIENT_H

#include <vector>
#include <map>
#include "TourStatuses.h"
#include "Tour.h"
#include "Place.h"
#include "BankCard.h"
#include "UserManager.h"


class Client: public User {
    friend UserManager;
private:
    std::map<Tour, TourStatuses> tours;
    std::vector<Place> wishlistCities;
    std::vector<Place> wishlistCountries;



    Client(QString email, QString password);
    Client(QString firstName, QString secondName,
            QString email, QString password);
    Client(QString fistName, QString secondName,
            QString email, QString password,
            QString phone, QString address);
    Client(QString firstName, QString secondName,
            QString email, QString password,
            QString phone, Address *address);
public:
    Client(const Client &client): User(client) {};
    bool addMoney(int cardNum, int cardPass);
    void addTourToWishlist(Tour tour);
    void orderTour(Tour tour);
    void buyTour(Tour tour);

    void recommendTour(Tour tour);
};


#endif //FINALPROJECT_CLIENT_H
