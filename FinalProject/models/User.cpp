#include "User.h"
#include "Address.h"

User::User(QString email, QString password) {
    this->email = email;
    this->password = password;
    this->address = nullptr;
}

User::User(QString firstName, QString secondName, QString email, QString password) {
    this->firstName = firstName;
    this->secondName = secondName;
    this->email = email;
    this->password = password;
    this->address = nullptr;

}

User::User(QString firstName, QString secondName, QString email, QString password, QString phone, QString address) {
    this->firstName = firstName;
    this->secondName = secondName;
    this->email = email;
    this->password = password;
    this->phone = phone;
    this->address = nullptr;
}

User::User(QString firstName, QString secondName, QString email, QString password, QString phone, Address *address) {
    this->firstName = firstName;
    this->secondName = secondName;
    this->email = email;
    this->password = password;
    this->phone = phone;
    this->address = address;
}