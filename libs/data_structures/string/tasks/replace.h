#ifndef INC_1_REPLACE_H
#define INC_1_REPLACE_H

#include "../string_.h"


void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    while (*readPtr != '\0') {
        if (*readPtr == *word1.begin) {
            if (areWordsEqual(word1, (WordDescriptor) {readPtr, readPtr + w1Size}) <= 0) {
                copy(word2.begin, word2.end, recPtr);
                readPtr += w1Size;
                recPtr += w2Size;
            } else {
                *recPtr++ = *readPtr++;
            }

        } else
            *recPtr++ = *readPtr++;
    }

    *recPtr = '\0';
}

void test_replace_sizeWordsIsEqual() {
    char s[MAX_STRING_SIZE] = "AB AB";
    replace(s, "AB", "BA");
    ASSERT_STRING("BA BA", s);
}

void test_replace_witchRandomWord() {
    char s[MAX_STRING_SIZE] = "AB A AB";
    replace(s, "AB", "BA");
    ASSERT_STRING("BA A BA", s);
}

void test_replace_sizeW1MoreW2() {
    char s[MAX_STRING_SIZE] = "ABC ABC";
    replace(s, "ABC", "BA");
    ASSERT_STRING("BA BA", s);
}

void test_replace_sizeW2MoreW1() {
    char s[MAX_STRING_SIZE] = "AB AB";
    replace(s, "AB", "CBA");
    ASSERT_STRING("CBA CBA", s);
}

void test_replace_emptyString() {
    char s[] = " ";
    replace(s, "AB", "BA");

    ASSERT_STRING(" ", s);
}

void test_replace() {
    test_replace_sizeWordsIsEqual();
    test_replace_witchRandomWord();
    test_replace_sizeW1MoreW2();
    test_replace_emptyString();

}

#endif //INC_1_REPLACE_H
