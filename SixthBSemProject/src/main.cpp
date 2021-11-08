#include <iostream>
#include <list>
#include "../include/BadCharTable.h"
#include "../include/Searcher.h"


int main() {
//    BadCharTable badCharTable;
//    badCharTable.init("karakara");
//    for (int i = 0; i < 256; i++) {
//        if (badCharTable[i] != -1)
//            std::cout << (char)i << '\t' << badCharTable[i] << std::endl;
//    }
    std::list<int> result = Searcher::BMS("okey", "sdfdslfksjgsffokeydfsldfkgsgokeydsfdsokey");
    for (const auto &el: result) std::cout << el << " ";
    std::cout << std::endl;
    return 0;
}