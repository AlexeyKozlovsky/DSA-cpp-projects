#include <unordered_set>
#include <set>

#ifndef SEVENTHSEMPROJECT_MYUNORDEREDSET_H
#define SEVENTHSEMPROJECT_MYUNORDEREDSET_H

template <typename T>
class MyUnorderedSet {
private:
    std::unordered_set<T> set;
public:
    static void printSet(const MyUnorderedSet<T> &set) {
        for (auto it = set.set.begin(); it != set.set.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    void insert(T value) {
        set.insert(value);
    }

    MyUnorderedSet<T> operator | (const MyUnorderedSet<T> &MyUnorderedSet1) const {
        MyUnorderedSet<T> result;
        for (auto it = this->set.begin(); it != this->set.end(); it++)
            result.insert(*it);

        for (auto it = MyUnorderedSet1.set.begin(); it != MyUnorderedSet1.set.end(); it++)
            result.insert(*it);

        return result;
    }

    MyUnorderedSet<T> operator & (const MyUnorderedSet<T> &MyUnorderedSet1) const {
        MyUnorderedSet<T> result;
        for (auto it = this->set.begin(); it != this->set.end(); it++) {
            if (MyUnorderedSet1.set.count(*it))
                result.insert(*it);
        }

        return result;
    }
};

#endif //SEVENTHSEMPROJECT_MYUNORDEREDSET_H
