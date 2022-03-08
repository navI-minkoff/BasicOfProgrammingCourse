#ifndef INC_1_WORDBEFOREFIRSTWORDWITHA_H
#define INC_1_WORDBEFOREFIRSTWORDWITHA_H

#include "../string_.h"

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;


WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, char **beginWordBefore, char **endWordBefore) {
    char *beginSearch = s;

    WordDescriptor previousW;
    if (!getWord(beginSearch, &previousW)) {
        return EMPTY_STRING;
    } else if (find(previousW.begin, previousW.end, 'a') != previousW.end ||
               find(previousW.begin, previousW.end, 'A') != previousW.end)
        return FIRST_WORD_WITH_A;

    beginSearch = previousW.end + 1;
    WordDescriptor currentW;
    while (getWord(beginSearch, &currentW)) {
        if (find(currentW.begin, currentW.end, 'a') != currentW.end ||
            find(currentW.begin, currentW.end, 'A') != currentW.end) {
            *beginWordBefore = previousW.begin;
            *endWordBefore = previousW.end;

            return WORD_FOUND;
        }

        beginSearch = currentW.end;
        previousW = currentW;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char *s) {
    WordDescriptor w;

    if (getWordBeforeFirstWordWithA(s, &w.begin, &w.end) == WORD_FOUND) {
        printf("%s\n", w.begin);
    }
}

void testAll_getWordBeforeFirstWordWithA() {
    char *beginWord, *endWord;

    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &beginWord, &endWord) == EMPTY_STRING);

    char s2[] = " ABC";
    assert(getWordBeforeFirstWordWithA(s2, &beginWord, &endWord) == FIRST_WORD_WITH_A);

    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3, &beginWord, &endWord) == WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING("BC", got);

    char s4[] = "bc a";
    assert(getWordBeforeFirstWordWithA(s4, &beginWord, &endWord) == WORD_FOUND);
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING("bc", got);

    char s5[] = "B Q WE YR OW IUWR ";
    assert(getWordBeforeFirstWordWithA(s5, &beginWord, &endWord) == NOT_FOUND_A_WORD_WITH_A);
}

#endif
