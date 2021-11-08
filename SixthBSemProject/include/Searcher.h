#include <list>
#include <cstring>
#include "BadCharTable.h"

#ifndef SIXTHBSEMPROJECT_SEARCHER_H
#define SIXTHBSEMPROJECT_SEARCHER_H

class Searcher {
public:
    static std::list<int> BMS(const char *t, const char *T) {
        std::list<int> result;
        BadCharTable chrTable;
        chrTable.init(t);

        int currentPosition = 0;
        int tLen = strlen(t);
        int TLen = strlen(T);

        while (currentPosition <= TLen - tLen) {
            int i;
            for (i =  tLen - 1; i != -1 && t[i] == T[i + currentPosition]; i--);

            if (i == -1) {
                result.push_back(currentPosition);
                currentPosition += tLen;
            } else currentPosition += i - chrTable[T[currentPosition + i]];
        }

        return result;
    }
};

#endif //SIXTHBSEMPROJECT_SEARCHER_H
