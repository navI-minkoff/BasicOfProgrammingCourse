#ifndef INC_1_WORDSAREORDEREDLEXICOGRAPHICALLY_H
#define INC_1_WORDSAREORDEREDLEXICOGRAPHICALLY_H

#include "../string_.h"

bool wordsAreOrderedLexicographically(char *s) {
    WordDescriptor w1;
    WordDescriptor w2;
    char *beginSearch = s;

    if (!getWord(beginSearch, &w1)) {
        return true;
    }

    w2 = w1;
    while (getWord(beginSearch, &w1)) {
        if (areWordsEqual(w1, w2) < 0)
            return false;

        beginSearch = w1.end;
        w2 = w1;
    }

    return true;
}

void test_wordsAreOrderedLexicographically_oneLetterOrdered() {
    char s[] = "A B C D";
    assert(wordsAreOrderedLexicographically(s));
}

void test_wordsAreOrderedLexicographically_oneLetterUnordered() {
    char s[] = "A B A";
    assert(!wordsAreOrderedLexicographically(s));
}

void test_wordsAreOrderedLexicographically_ordered() {
    char s[] = "ABC ABCD";
    assert(wordsAreOrderedLexicographically(s));
}

void test_wordsAreOrderedLexicographically_unordered() {
    char s[] = "BCD BCD ABC";
    assert(!wordsAreOrderedLexicographically(s));
}

void test_wordsAreOrderedLexicographically_oneWord() {
    char s[] = "ABC";
    assert(wordsAreOrderedLexicographically(s));
}

void test_wordsAreOrderedLexicographically_emptyString() {
    char s[] = " ";
    assert(wordsAreOrderedLexicographically(s));
}

void test_wordsAreOrderedLexicographically() {
    test_wordsAreOrderedLexicographically_oneLetterOrdered();
    test_wordsAreOrderedLexicographically_oneLetterUnordered();
    test_wordsAreOrderedLexicographically_ordered();
    test_wordsAreOrderedLexicographically_unordered();
    test_wordsAreOrderedLexicographically_oneWord();
    test_wordsAreOrderedLexicographically_emptyString();
}

#endif //INC_1_WORDSAREORDEREDLEXICOGRAPHICALLY_H
