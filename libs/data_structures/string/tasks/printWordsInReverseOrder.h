#ifndef INC_1_PRINTWORDSINREVERSEORDER_H
#define INC_1_PRINTWORDSINREVERSEORDER_H

#include "../string_.h"

void printWord(WordDescriptor word) {
    while (word.begin != word.end) {
        putchar(*word.begin);
        word.begin++;
    }

    printf("\n");
}

void printWordsInReverseOrder(char *s) {
    getBagOfWords(&_bag, s);

    for (int i = _bag.size - 1; i >= 0; i--) {
        printWord(_bag.words[i]);
    }
}


#endif //INC_1_PRINTWORDSINREVERSEORDER_H
