#include <set>

#include <QApplication>
#include <QPushButton>
#include <QDebug>

#include "Data.h"
#include "User.h"
#include "Place.h"
#include "Hotel.h"
#include "PlaceTypes.h"
#include "PlaceManager.h"
#include "HotelManager.h"
#include "RouteManager.h"
#include "TourManager.h"
#include "UserManager.h"

#include "HotelsTableModel.h"
#include "PlacesTableModel.h"
#include "UsersTableModel.h"
#include "BaseTableView.h"

#include "TabBarPage.h"
#include "HotelsFilterWidget.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();

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
    TourManager *tourManager = TourManager::GetInstance();
    UserManager *userManager = UserManager::GetInstance();
    placeManager->parseFromJson("../resources/cities.json");
    hotelManager->parseFromJson("../resources/hotels.json");
    routeManager->parseFromJson("../resources/routes.json");
    tourManager->parseFromJson("../resources/tours.json");
    userManager->parseFromJson("../resources/users.json");




//    Place *foundPlace = (Place *)placeManager->getPlaceByName("Бакыханов");
//    qDebug() << foundPlace->getName();
//    qDebug() << foundPlace->getDescription();
//    qDebug() << foundPlace->getLocation();

//    std::set<Data *> radiusedPlaces = placeManager->getPlacesByLocation(10000, 10000, 0.1);
//    std::set<Data *> russianCities = placeManager->getCitiesByCountry("Российская Федерация");



//    BaseTableView hotelsView("Hotels");
//    BaseTableView placesView("Places");
//    BaseTableView usersView("Users");
//
//    HotelsTableModel *hotelsModel = new HotelsTableModel;
//    hotelsView.setModel(hotelsModel);
//
//    PlacesTableModel *placesModel = new PlacesTableModel;
//    placesView.setModel(placesModel);
//
//    UsersTableModel *usersModel = new UsersTableModel;
//    usersView.setModel(usersModel);
//
//    hotelsView.show();
//    placesView.show();
//    usersView.show();

    TabBarPage page;
    page.show();
    return QApplication::exec();
}
