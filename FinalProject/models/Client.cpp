#include "User.h"
#include "Client.h"

Client::Client(QString email, QString password) : User(email, password) {

}

Client::Client(QString firstName, QString secondName, QString email, QString password) : User(firstName, secondName,
                                                                                              email, password) {

}

Client::Client(QString fistName, QString secondName, QString email, QString password, QString phone, QString address)
        : User(fistName, secondName, email, password, phone, address) {

}

Client::Client(QString firstName, QString secondName, QString email, QString password, QString phone, Address *address)
        : User(firstName, secondName, email, password, phone, address) {

}
