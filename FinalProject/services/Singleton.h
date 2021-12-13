#ifndef FINALPROJECT_SINGLETON_H
#define FINALPROJECT_SINGLETON_H

#include <QString>


class Singleton
{
protected:
    Singleton();

    static Singleton* singleton_;


public:
    Singleton(Singleton &other) = delete;
    void operator=(const Singleton &) = delete;
    static Singleton *GetInstance();
};


#endif //FINALPROJECT_SINGLETON_H
