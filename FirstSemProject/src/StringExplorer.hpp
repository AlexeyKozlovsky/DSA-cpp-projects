#ifndef FIRSTSEMPROJECT_STRINGEXPLORER_H
#define FIRSTSEMPROJECT_STRINGEXPLORER_H

class StringExplorer {
public:
    static int countSymbols(char *line, char s);
    static int countWords(char *line);
    static int countMinWordLength(char *line);
    static int countMaxWordLength(char *line);
    static char* reverseLine(char *line);
    static bool isPalindrom(char *line);
};

#endif /* FIRSTSEMPROJECT_STRINGEXPLORER_H */
