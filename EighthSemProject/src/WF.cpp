#include <iostream>
#include "WF.h"


WF::WF(std::string firstString, std::string secondString) {
    this->rows = firstString.length() + 1;
    this->columns = secondString.length() + 1;
    this->firstString = firstString;
    this->secondString = secondString;
    this->matrix = new int*[this->rows];

    for (int i = 0; i < this->rows; i++)
        this->matrix[i] = new int[this->columns];

    for (int i = 0; i < this->rows; i++) this->matrix[i][0] = i;
    for (int i = 0; i < this->columns; i++) this->matrix[0][i] = i;
}

WF::~WF() {
    for (int i = 0; i < this->rows; i++) delete[] this->matrix[i];
    delete[] this->matrix;
}

int WF::getDistance() {
    for (int i = 1; i < this->rows; i++) {
        for (int j = 1; j < this->columns; j++) {
            int p = this->firstString[i] == this->secondString[j] ? 0 : 1;
            this->matrix[i][j] = this->min(this->matrix[i - 1][j] + 1, this->matrix[i][j - 1] + 1,
                                           this->matrix[i - 1][j - 1] + p);
        }
    }
    return this->matrix[this->rows - 1][this->columns - 1];
}

void WF::printMatrix() {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j++)
            std::cout << this->matrix[i][j] << '\t';
        std::cout << std::endl;
    }
}

