#ifndef INC_1_HAVEWORDSMADEUPSAMELETTERS_H
#define INC_1_HAVEWORDSMADEUPSAMELETTERS_H

#include "../string_.h"
#include "haveSameWords.h"
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(const char *) a - *(const char *) b;
}

bool haveWordsMadeUpSameLetters(char *s) {
    *copy(s, getEndOfString(s), _stringBuffer) = '\0';
    getBagOfWords(&_bag, _stringBuffer);

    for (size_t i = 0; i < _bag.size; i++)
        qsort(_bag.words[i].begin, _bag.words[i].end - _bag.words[i].begin,
              sizeof(char), cmp);

    return haveSameWords(_stringBuffer);
}

void test_areWordsFromSameLetters_hasThisWords() {
    char s[] = "bananz apple banzan";
    assert(haveWordsMadeUpSameLetters(s));
}

void test_areWordsFromSameLetters_hasThisWords2() {
    char s[] = "gognsog gosggon";
    assert(haveWordsMadeUpSameLetters(s));
}

void test_areWordsFromSameLetters_hasNotThisWords() {
    char s[] = "bananz apple banvan";
    assert(!haveWordsMadeUpSameLetters(s));
}

void test_areWordsFromSameLetters_empty() {
    char s[] = "";
    assert(!haveWordsMadeUpSameLetters(s));
}

void test_areWordsFromSameLetters_oneWord() {
    char s[] = "banana";
    assert(!haveWordsMadeUpSameLetters(s));
}

void test_areWordsFromSameLetters_differentRegisters() {
    char s[] = "banana bAnana";
    assert(!haveWordsMadeUpSameLetters(s));
}

void test_haveWordsMadeUpSameLetters() {
//    test_areWordsFromSameLetters_hasThisWords();
//    test_areWordsFromSameLetters_hasNotThisWords();
//    test_areWordsFromSameLetters_hasThisWords2();
//    test_areWordsFromSameLetters_empty();
    test_areWordsFromSameLetters_oneWord();
    test_areWordsFromSameLetters_differentRegisters();
}

#endif
