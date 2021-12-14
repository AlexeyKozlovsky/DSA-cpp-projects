#include <QDebug>
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QIODevice>

#include "Data.h"
#include "Client.h"
#include "PlaceTypes.h"
#include "Place.h"
#include "UserManager.h"
#include "PlaceManager.h"

UserManager *UserManager::userManager_ = nullptr;

Data *UserManager::createUser(QString firstName, QString secondName, QString email, QString password) {
    Client *client = new Client(firstName, secondName, email, password);
    this->addResource(client);
    return client;
}

void UserManager::parseFromJson(QString jsonPath) {
    PlaceManager *placeManager = PlaceManager::GetInstance();

    QFile file(jsonPath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData.toUtf8());
    QJsonObject object = document.object();

    QJsonArray usersArray = object.value("users").toArray();

    foreach (const QJsonValue &v, usersArray) {
        QString firstName = v.toObject().value("firstName").toString();
        QString secondName = v.toObject().value("secondName").toString();
        QString patronymic = v.toObject().value("patronymic").toString();
        QString phone = v.toObject().value("phone").toString();
        QString email = v.toObject().value("email").toString();
        QString password = v.toObject().value("password").toString();

        QJsonObject addressObject = v.toObject().value("address").toObject();
        QJsonObject cityObject = addressObject.value("city").toObject();
        QString cityName = cityObject.value("name").toString();

        Place *city = (Place *) placeManager->getPlaceByName(cityName, PlaceTypes::City);
        Place *country;
        if (!city) {
            QString cityDescription = cityObject.value("description").toString();
            QJsonArray cityLocationArray = cityObject.value("location").toArray();

            std::pair<double, double> cityLocation {
                cityLocationArray[0].toDouble(),
                cityLocationArray[1].toDouble()
            };

            city = (Place *) placeManager->createPlace(cityName, cityDescription, cityLocation,
                                                      PlaceTypes::City);
        }

        country = city->getParentPlace();
        if (!country) {
            QJsonObject countryObject = addressObject.value("country").toObject();
            QString countryName = countryObject.value("name").toString();
            QString countryDescription = countryObject.value("description").toString();

            QJsonArray countryLocationArray = countryObject.value("location").toArray();
            std::pair<double, double> countryLocation {
                countryLocationArray[0].toDouble(),
                countryLocationArray[1].toDouble()
            };

            country = (Place *) placeManager->createPlace(countryName, countryDescription, countryLocation,
                                                          PlaceTypes::Country);
        }

        QString streetName = addressObject.value("streetName").toString();
        QString house = addressObject.value("house").toString();
        Address *address = new Address(city, streetName, house);

        User *user = (User *) this->createUser(firstName, secondName, email, password);
        user->patronymic = patronymic;
        user->address = address;
        user->phone = phone;
    }
}

Data *UserManager::getByName(QString name) {
    return nullptr;
}

void UserManager::deleteByName(QString name) {

}

UserManager::UserManager() {

}

