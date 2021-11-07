#include <iostream>
#include "../include/Str.hpp"


int main() {
    Str s = "asdasdsafdsf";
    Str a = s;
    int test = s.replace('a', 'L');
    s.print();
    std::cout << test;
    a.print();
    return 0;
}