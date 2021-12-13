#include "Client.h"
#include "Data.h"
#include "UserManager.h"

UserManager *UserManager::userManager_ = nullptr;

Data *UserManager::createUser(QString firstName, QString secondName, QString email, QString password) {
    Client *client = new Client(firstName, secondName, email, password);
    this->addResource(client);
    return client;
}
