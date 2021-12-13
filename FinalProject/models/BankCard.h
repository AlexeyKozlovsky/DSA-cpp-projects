#ifndef FINALPROJECT_BANKCARD_H
#define FINALPROJECT_BANKCARD_H

#include <QString>


class BankCard {
private:
    QString bankName;
    int cardNum;
    int cardPass;
    int cardPin;

    double money;

public:
    BankCard(QString bankName, int cardNum, int cardPass, int cardPin);
    void addMoney(double money);
    bool getMoney(double money);
    bool changePin(int oldPin, int newPin);
};


#endif //FINALPROJECT_BANKCARD_H
