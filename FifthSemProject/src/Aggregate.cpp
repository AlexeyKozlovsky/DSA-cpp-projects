#include "../include/Aggregate.hpp"
#include <iostream>


Aggregate::Aggregate() {
    std::cout << "Aggregate constructor" << std::endl;
}

Aggregate::Aggregate(Aggregate &a) {
    std::cout << "Copying aggregate" << std::endl;
}

Aggregate::~Aggregate() {
    std::cout << "Aggregate destructor" << std::endl;
}