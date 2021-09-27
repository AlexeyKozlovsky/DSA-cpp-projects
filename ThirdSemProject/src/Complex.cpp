#include "../include/Complex.h"
#include <cmath>

double Complex::getMod() {
    return std::sqrt(this->im * this->im + this->re * this->re);
}

double Complex::getArg() {
    if (this->im == 0) return 0;
    return std::atan(this->im / this->re);
}

Complex Complex::conjugate() {
    return {this->re, -this->im};
}

