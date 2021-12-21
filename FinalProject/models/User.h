#ifndef FINALPROJECT_USER_H
#define FINALPROJECT_USER_H

#include <QString>
#include "Address.h"
#include "UserManager.h"
#include "UsersTableModel.h"


class User: public Data {
    friend UserManager;
    friend UsersTableModel;
protected:
    QString firstName;
    QString secondName;
    QString patronymic;
    QString phone;
    QString email;
    QString password;

    Address *address;

    User(QString email, QString password);
    User(QString firstName, QString secondName,
         QString email, QString password);
    User(QString fistName, QString secondName,
         QString email, QString password,
         QString phone, QString address);
    User(QString firstName, QString secondName,
         QString email, QString password,
         QString phone, Address *address);
public:
    User(const User &user) {};

    bool updatePassword(QString oldPassword, QString newPassword);
    bool updatePhone(QString newPhone);
    bool updateEmail(QString newEmail);
    bool updateAddress(QString newAddress);
    bool updateAddress(Address newAddress);
    bool updateName(QString fistName, QString secondName, QString patronymic);

    int getAge();

    inline QString getFirstName() const {return this->firstName;};
    inline QString getSecondName() const {return this->secondName;};
    inline QString getPatronymic() const {return this->patronymic;};
    inline QString getEmail() const {return this->email;};
    inline QString getPhone() const {return this->phone;};
    inline QString getStringAddress() const {return this->address->getStringAddress();};
    inline QString getFullName() const {
        return this->secondName + " " + this->firstName + " " + this->patronymic;
    };

    // --------------------OPERATORS--------------------
    inline bool operator ==(const User &user) const {
        if (this->firstName == user.firstName && this->secondName == user.secondName &&
            this->patronymic == user.patronymic && this->address == user.address &&
            this->phone == this->phone && this->email == user.email &&
            this->password == user.password) return true;
        return false;
    }
};


#endif //FINALPROJECT_USER_H
