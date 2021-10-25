#include <iostream>

#ifndef FIFTHSEMPROJECT_AGGREGATET_HPP
#define FIFTHSEMPROJECT_AGGREGATET_HPP

template <typename T>
class AggregateT {
public:
    AggregateT() {
        std::cout << "AggregateT constructor" << std::endl;
    };
    ~AggregateT() {
        std::cout << "AggregateT destructor" << std::endl;
    }
};

#endif //FIFTHSEMPROJECT_AGGREGATET_HPP
