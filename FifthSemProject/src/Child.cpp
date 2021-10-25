#include "../include/Child.hpp"
#include <iostream>


Child::Child() {
    std::cout << "Child constructor" << std::endl;
}

Child::Child(Child &) {
    std::cout << "Child copying" << std::endl;
}

Child::~Child() {
    std::cout << "Child destructor" << std::endl;
}