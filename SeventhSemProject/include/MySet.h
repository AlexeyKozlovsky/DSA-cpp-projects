#include <set>
#include <unordered_set>

#ifndef SEVENTHSEMPROJECT_MYSET_H
#define SEVENTHSEMPROJECT_MYSET_H

template <typename T>
class MySet {
private:
    std::set<T> set;
public:
    static void printSet(const MySet<T> &set) {
        for (auto it = set.set.begin(); it != set.set.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    void insert(T value) {
        this->set.insert(value);
    }

    bool contains(T value) {
        return (bool)this->set.count(value);
    }

    std::size_t count() {
        return this->set.size();
    }

    MySet<T> operator | (const MySet<T> &mySet) const {
        MySet<T> result;
        for (auto it = this->set.begin(); it != this->set.end(); it++)
            result.insert(*it);

        for (auto it = mySet.set.begin(); it != mySet.set.end(); it++)
            result.insert(*it);

        return result;
    }

    MySet<T> operator & (const MySet<T> &mySet) const {
        MySet<T> result;
        for (auto it = this->set.begin(); it != this->set.end(); it++) {
            if (mySet.set.count(*it))
                result.insert(*it);
        }

        return result;
    }
};

#endif //SEVENTHSEMPROJECT_MYSET_H
