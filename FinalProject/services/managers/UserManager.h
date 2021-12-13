#ifndef FINALPROJECT_USERMANAGER_H
#define FINALPROJECT_USERMANAGER_H

#include <QString>
#include <vector>

#include "ResourceManager.h"
#include "Data.h"


class UserManager: public ResourceManager {
private:
    static UserManager *userManager_;

    UserManager() = default;
public:
    void parseFromJson(QString jsonPath) override;
    Data * getByName(QString name) override;
    void deleteByName(QString name) override;
    static UserManager *GetInstance() {
        if (UserManager::userManager_ == nullptr)
            UserManager::userManager_ = new UserManager();
        return UserManager::userManager_;
    };

    Data *createUser(QString firstName, QString secondName, QString email, QString password);
};


#endif //FINALPROJECT_USERMANAGER_H
