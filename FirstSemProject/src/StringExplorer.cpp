#include <iostream>
#include <stdlib.h>
#include "StringExplorer.hpp"


int StringExplorer::countSymbols(char *line, char s) {
    int result = 0;
    char *p = line;
    while (*p){
        if (*p == s) result++;
        p++;
    } 

    return result;
}

int StringExplorer::countWords(char *line) {
    char *p = line;
    bool isWord = *p != ' ';
    int result = isWord ? 1 : 0;
    while (*p) {
        if (*p != ' ' && !isWord) {
            result++;
            isWord = true;
        } else if (*p == ' ') isWord = false;
        p++;
    }

    return result;
}

int StringExplorer::countMinWordLength(char *line) {
    char *p = line;
    int currentResult = 0, result = sizeof(line);
    bool isWord = *p != ' ';
    while (*p) {
        if (*p == ' ' && isWord) {
            isWord = false;
            if (currentResult < result) result = currentResult;
            currentResult = 0;
        } else if (*p != ' ') {
            currentResult++;
            isWord = true;
        }
        p++;
    }

    // Здесь вторая часть условия проверяет, не является ли последний символ строки пробелом, потому что, если это так,
    // то currentResult будет 0, а следовательно и занулит result, что в большинстве случаев будет ошибкой.
    // Единственный случай, в котором это не будет ошибкой покрывается в следующем условии
    if (currentResult < result && *(p - 1) != ' ') result = currentResult;

    // Чтобы не заводить лишнюю переменную и не делать новые костыли добавлено следующее условие
    // Оно сделано для того, чтобы функция не выполнялась неправильно при передаче аргументом строки из одних пробелов
    // Если isWord - false - это значит, что мы точно наткнулись на пробел. То есть длина минимального слова уже не может
    // быть равной длине всей строки, а это значит, что если у нас эти два условия выполняются, то появляется противоречие
    // и, следовательно, строка состоит из одних пробелов (так как если бы это было бы не так, то хоть раз бы выполнился
    // кусок кода, где согласно currentResult выставляется значение для result.
    if (!isWord && result == sizeof(line)) result = 0;

    return result;
}

int StringExplorer::countMaxWordLength(char *line) {
    char *p = line;
    int currentResult = 0, result = 0;
    bool isWord = *p != ' ';

    while (*p) {
        if (*p == ' ' && isWord) {
            isWord = false;
            if (currentResult > result) result = currentResult;
            currentResult = 0;
        } else if (*p != ' ') {
            isWord = true;
            currentResult++;
        }
        p++;
    }

    if (currentResult > result) result = currentResult;
    return result;
}

char* StringExplorer::reverseLine(char *line) {
    char *result = static_cast<char *>(malloc(sizeof(line)));
    char *currenResult = result;
    char *p = line;
    while (*p) p++;

    int i = 0;
    while (--p != line - 1) {
        *currenResult = *p;
        currenResult++;
        i++;
    }

    return result;
}

bool StringExplorer::isPalindrom(char *line) {
    char *reversed = StringExplorer::reverseLine(line);
    while(*line) {
        if (*reversed != *line) return false;
        line++;
        reversed++;
    }

    return true;
}
