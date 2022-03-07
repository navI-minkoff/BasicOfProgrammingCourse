#ifndef INC_1_WORDSAREORDEREDLEXICOGRAPHICALLY_H
#define INC_1_WORDSAREORDEREDLEXICOGRAPHICALLY_H

#include "../string_.h"

bool wordsAreOrderedLexicographically(char *s) {
    WordDescriptor currentWord;
    WordDescriptor previousWord;
    char *beginSearch = s;

    if (!getWord(beginSearch, &currentWord)) {
        return true;
    }

    previousWord = currentWord;
    while (getWord(beginSearch, &currentWord)) {
        if (areWordsEqual(currentWord, previousWord) < 0)
            return false;

        beginSearch = currentWord.end;
        previousWord = currentWord;
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
