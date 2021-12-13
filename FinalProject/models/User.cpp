#include "User.h"
#include "Address.h"

User::User(QString email, QString password) {
    this->address = nullptr;
}

User::User(QString firstName, QString secondName, QString email, QString password) {
    this->address = nullptr;

}

User::User(QString fistName, QString secondName, QString email, QString password, QString phone, QString address) {
    this->address = nullptr;
}

User::User(QString firstName, QString secondName, QString email, QString password, QString phone, Address *address) {
    this->address = address;
}