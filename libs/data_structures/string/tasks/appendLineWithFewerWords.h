#ifndef INC_1_APPENDLINEWITHFEWERWORDS_H
#define INC_1_APPENDLINEWITHFEWERWORDS_H

#include "../string_.h"

int countWords(char *s) {
    int countW = 0;
    WordDescriptor w;

    char *beginSearch = s;
    while (getWord(beginSearch, &w)) {
        countW++;
        beginSearch = w.end;
    }

    return countW;
}


void appendLineWithFewerWords_(char *s1, char *s2, int n1, int n2) {
    int addWords = n1 - n2;
    WordDescriptor w;
    char *beginSearch = getEndOfString(s1) - 1;
    for (size_t i = 0; i < addWords; i++) {
        getWordReverse(beginSearch, s1, &w);

        beginSearch = findNonSpaceReverse(w.begin - 1, s1);
    }

    char *endS2 = getEndOfString(s2);
    *endS2++ = ' ';
    *copy(w.begin, getEndOfString(s1), endS2) = '\0';
}

void appendLineWithFewerWords(char *s1, char *s2) {
    int sizeS1 = countWords(s1);
    int sizeS2 = countWords(s2);

    if (sizeS1 == sizeS2)
        return;
    else if (sizeS1 > sizeS2) {
        appendLineWithFewerWords_(s1, s2, sizeS1, sizeS2);
    } else
        appendLineWithFewerWords_(s2, s1, sizeS2, sizeS1);
}

void test_addLastWordsSecondStringToFirstString_firstStringMoreSecond() {
    char s1[MAX_STRING_SIZE] = "Hello Fucking World Bye";
    char s2[MAX_STRING_SIZE] = "Cat Home";

    appendLineWithFewerWords(s1, s2);

    ASSERT_STRING("Cat Home World Bye", s2);
}

void test_addLastWordsSecondStringToFirstString_oneWordInFirst() {
    char s1[MAX_STRING_SIZE] = "Hello";
    char s2[MAX_STRING_SIZE] = "Cat Home";

    appendLineWithFewerWords(s1, s2);

    ASSERT_STRING("Hello Home", s1);
}

void test_addLastWordsSecondStringToFirstString_oneWordInStrings() {
    char s1[MAX_STRING_SIZE] = "Hello";
    char s2[MAX_STRING_SIZE] = "";

    appendLineWithFewerWords(s1, s2);

    ASSERT_STRING("Hello", s1);
}

void test_addLastWordsSecondStringToFirstString_emptyStrings() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";

    appendLineWithFewerWords(s1, s2);

    ASSERT_STRING("", s1);
    ASSERT_STRING("", s2);
}

void test_addLastWordsSecondStringToFirstString_secondStringMoreFirstString() {
    char s1[MAX_STRING_SIZE] = "Cat Home";
    char s2[MAX_STRING_SIZE] = "Hello Fucking World Bye";

    appendLineWithFewerWords(s1, s2);

    ASSERT_STRING("Cat Home World Bye", s1);
}

void test_appendLineWithFewerWords() {
    test_addLastWordsSecondStringToFirstString_secondStringMoreFirstString();
    test_addLastWordsSecondStringToFirstString_firstStringMoreSecond();
    test_addLastWordsSecondStringToFirstString_oneWordInFirst();
    test_addLastWordsSecondStringToFirstString_oneWordInStrings();
    test_addLastWordsSecondStringToFirstString_emptyStrings();
}
#endif
