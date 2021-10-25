//
// Created by alexeykozlovsky on 25.10.2021.
//

#include "Test.hpp"
#include <iostream>


Test::Test() {
    std::cout << "Test constructor. Count: " << ++Test::nCount << std::endl;
}

Test::Test(const Test &t) {
    std::cout << "Copying test. Count: " << ++Test::nCount << std::endl;
}

Test::~Test() {
    Test::nCount--;
    std::cout << "Test destructor. Count" << --Test::nCount << std::endl;
}

int Test::nCount = 0;
