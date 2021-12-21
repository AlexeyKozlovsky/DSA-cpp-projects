#include "WFOpt.h"

int getDistance(std::string firstString, std::string secondString) {
    int n = firstString.length();
    int m = secondString.length();

    int *p1 = new int[m + 1];
    int *p2 = new int[m + 1];

    for (int i = 0; i < m; i++) p1[i] = i;
    for (int i = 1; i < n; i++) {
        p2[0] = i;
        for (int j = 0; j < m; j++) {
            int p = firstString[i] == secondString[j] ? 0: 1;
            p2[j] = std::min(std::min(p2[j - 1] + 1, p1[j] + 1), p1[j - 1] + p);
        }

        for (int j = 0; j < m; j++) p1[j] = p2[j];
    }

    int result = p2[m - 1];

    delete[] p1;
    delete[] p2;
    return result;
}
