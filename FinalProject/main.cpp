#include <set>

#include <QApplication>
#include <QPushButton>
#include <QDebug>

#include "Data.h"
#include "Place.h"
#include "Hotel.h"
#include "PlaceTypes.h"
#include "PlaceManager.h"
#include "HotelManager.h"
#include "RouteManager.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();

//    UserManager *userManager = (UserManager *) UserManager::GetInstance();
//    auto *user1 = userManager->createUser("Alex", "Keks", "efdsfd@agd.com", "12321sdgfdsf3");
//    auto *user2 = userManager->createUser("Ivan", "Ivanov", "fff@afd.com", "12dgfdsf3");
//    auto *user3 = userManager->createUser("Alex", "Piters", "e123@a22.com", "12sdfdsf3");
//
//
//    std::set<Data *> users = userManager->getResources();


    PlaceManager *placeManager = PlaceManager::GetInstance();
    HotelManager *hotelManager = HotelManager::GetInstance();
    RouteManager *routeManager = RouteManager::GetInstance();
    placeManager->parseFromJson("../resources/cities.json");
    hotelManager->parseFromJson("../resources/hotels.json");
    routeManager->parseFromJson("../resources/routes.json");


//    Place *foundPlace = (Place *)placeManager->getPlaceByName("Бакыханов");
//    qDebug() << foundPlace->getName();
//    qDebug() << foundPlace->getDescription();
//    qDebug() << foundPlace->getLocation();

//    std::set<Data *> radiusedPlaces = placeManager->getPlacesByLocation(10000, 10000, 0.1);
//    std::set<Data *> russianCities = placeManager->getCitiesByCountry("Российская Федерация");

    return QApplication::exec();
}
