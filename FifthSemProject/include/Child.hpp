//
// Created by alexeykozlovsky on 25.10.2021.
//
#include "Test.hpp"

#ifndef FIFTHSEMPROJECT_CHILD_HPP
#define FIFTHSEMPROJECT_CHILD_HPP
class Child : public Test {
public:
    Child();
    Child(Child &);
    ~Child();
};

#endif //FIFTHSEMPROJECT_CHILD_HPP
