#include <iostream>
#include "../include/Complex.h"


int main() {
    Complex c1(2, 3);
    Complex c2(2, 5);
    Complex result = c1 + c2;
    std::cout << result << std::endl;

    std::cout << result.getArg() << std::endl;
    std::cout << result.conjugate() << std::endl;

    Complex test = 1.;

    Complex v[4]{1., 2., Complex(2, 3)};

    for (auto i : v) std::cout << i << std::endl;

    return 0;
}
