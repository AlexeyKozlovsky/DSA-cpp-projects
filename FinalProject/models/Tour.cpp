#include "Tour.h"

Tour::Tour(QString name, QString description, Route *route, double extraPrice) {
    this->name = name;
    this->description = description;
    this->route = route;
}

Tour::Tour(QString name, QString description, std::vector<Place *> cities, std::vector<Hotel *> hotels,
           int extraPrice) {
    this->name = name;
    this->description = description;
}

void Tour::addUser(User user, std::vector<Room> rooms) {

}

void Tour::removeUser(User user) {

}

double Tour::addDiscount(double percent) {
    return 0;
}
