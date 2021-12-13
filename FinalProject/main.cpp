#include <set>

#include <QApplication>
#include <QPushButton>
#include <QDebug>

#include "Data.h"
#include "Place.h"
#include "PlaceTypes.h"
#include "PlaceManager.h"


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
    placeManager->parseFromJson("../resources/cities.json");

    std::set<Data *> places = placeManager->getResources();

    Place *place = (Place *) *places.begin();
    qDebug() << place->getName();
    qDebug() << place->getDescription();
    qDebug() << place->getLocation();

    PlaceTypes type = place->getPlaceType();
    if (type == PlaceTypes::City) qDebug() << "City!";
    else if (type == PlaceTypes::Country) qDebug() << "Country";


    std::set<Data *> result = placeManager->getPlacesByName("Босния");

    return QApplication::exec();
}
