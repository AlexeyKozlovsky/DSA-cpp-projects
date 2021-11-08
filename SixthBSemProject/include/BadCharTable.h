#include <list>

#ifndef SIXTHASEMPROJECT_BADCHARTABLE_H
#define SIXTHASEMPROJECT_BADCHARTABLE_H

class BadCharTable {
    int badChar[256]{};

public:
    BadCharTable() {
        this->init();
    }

    void init() {
        for (int &i : this->badChar) i = -1;
    }

    void init(const char *line) {
        for (int & i : this->badChar) i = -1;
        int i = 0;
        while (*(line + 1)) {
            this->badChar[*line] = i;
            line++; i++;
        }
    }

    int operator[] (unsigned char c) const {
        return this->badChar[c];
    }
};

#endif //SIXTHASEMPROJECT_BADCHARTABLE_H
