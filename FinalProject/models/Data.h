#ifndef FINALPROJECT_DATA_H
#define FINALPROJECT_DATA_H

#include <QString>

class Data {
public:
    virtual bool parseFromJson(QString jsonPath);

    virtual inline bool operator ==(const Data &data) const {
        return true;
    }

    virtual inline bool operator <(const Data & data) const {
        return false;
    }
};


#endif //FINALPROJECT_DATA_H
