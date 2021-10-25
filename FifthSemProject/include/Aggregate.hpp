#include "Test.hpp"

#ifndef FIFTHSEMPROJECT_AGGREGATE_HPP
#define FIFTHSEMPROJECT_AGGREGATE_HPP

class Aggregate {
private:
    Test m_objTest;
public:
    Aggregate();
    Aggregate(Aggregate &);
    ~Aggregate();
};

#endif //FIFTHSEMPROJECT_AGGREGATE_HPP
