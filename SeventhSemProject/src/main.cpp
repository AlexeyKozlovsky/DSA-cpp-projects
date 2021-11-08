#include <iostream>
#include <set>
#include <unordered_set>
#include "../include/MySet.h"

template <typename valueType>
void printSet(const std::set<valueType> &set);

template <typename valueType>
void printSet(const std::unordered_set<valueType> &unorderedSet);


int main() {
    std::set<int> set;
    std::unordered_set<int> unorderedSet;

    for (int i = 0; i < 20; i++) {
        int value = std::rand() % 10;
        set.insert(value);
        unorderedSet.insert(value);
    }

    printSet(set);
    printSet(unorderedSet);

    MySet<int> MySet1;
    MySet<int> MySet2;

    for (int i = 0; i < 5; i++) {
        MySet1.insert(std::rand() % 10);
        MySet2.insert(std::rand() % 10 + 4);
    }

    MySet<int> result1 = MySet1 | MySet2;
    MySet<int> result2 = MySet1 & MySet2;

    MySet<int>::printSet(MySet1);
    MySet<int>::printSet(MySet2);
    MySet<int>::printSet(result1);
    MySet<int>::printSet(result2);

    std::cout << result1.contains(12) << std::endl;
    std::cout << result1.count() << std::endl;

    return 0;
}

template <typename valueType>
void printSet(const std::set<valueType> &set) {
    for (auto it = set.begin(); it != set.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename valueType>
void printSet(const std::unordered_set<valueType> &unorderedSet) {
    for (auto it = unorderedSet.begin(); it != unorderedSet.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}