#ifndef FINALPROJECT_RESOURCEMANAGER_H
#define FINALPROJECT_RESOURCEMANAGER_H

#include <set>
#include <QString>

#include "Data.h"
#include "Singleton.h"


class ResourceManager{
protected:
    std::set<Data*> resources;

public:
    virtual void parseFromJson(QString jsonPath) = 0;
    void addResource(Data *resource);
    void removeResource(Data *resource);
    std::set<Data*> getResources();

    virtual Data* getByName(QString name) = 0;
    virtual void deleteByName(QString name) = 0;
};


#endif //FINALPROJECT_RESOURCEMANAGER_H
