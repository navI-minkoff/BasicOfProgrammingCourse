#ifndef INC_1_HAVESAMEWORDS_H
#define INC_1_HAVESAMEWORDS_H

#include "../string_.h"

bool haveSameWords(char *s) {
    getBagOfWords(&_bag, s);

    for (size_t i = 0; i < _bag.size - 1; i++) {
        for (size_t j = i + 1; j < _bag.size - 1; j++)
            if (areWordsEqual(_bag.words[i], _bag.words[j]))
                return true;
    }

    return false;
}

void test_hasEqualWords_LettersHasEqualWords() {
    char s[] = "a b a d e";
    assert(haveSameWords(s));
}

void test_hasEqualWords_hasEqualWords() {
    char s[] = "Hello World Hello";
    assert(haveSameWords(s));
}

void test_hasEqualWords_hasNotEqualWords() {
    char s[] = "Hello World Hell";
    assert(!haveSameWords(s));
}

void test_hasEqualWords_oneWord() {
    char s[] = "Hello";
    assert(!haveSameWords(s));
}

void test_hasEqualWords_empty() {
    char s[] = "";
    assert(!haveSameWords(s));
}

void test_haveSameWords() {
    test_hasEqualWords_hasEqualWords();
    test_hasEqualWords_LettersHasEqualWords();
    test_hasEqualWords_hasNotEqualWords();
    test_hasEqualWords_oneWord();
    test_hasEqualWords_empty();
}

#endif
