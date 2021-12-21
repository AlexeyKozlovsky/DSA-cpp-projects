#ifndef EIGHTHSEMPROJECT_WF_H
#define EIGHTHSEMPROJECT_WF_H

#include <string>


class WF {
private:
    std::string firstString, secondString;
    int rows, columns;
    int **matrix;

    inline int min(int a, int b, int c) const {return std::min(std::min(a, b), c);};
public:
    WF(std::string firstString, std::string secondString);
    ~WF();

    inline int getRows() const {return this->rows;};
    inline int getColumns() const {return this->columns;};
    inline int getItem(int i, int j) const {return this->matrix[i][j];};
    inline void setItem(int i, int j, int value) {this->matrix[i][j] = value;};

    int getDistance();

    void printMatrix();
};

#endif //EIGHTHSEMPROJECT_WF_H
