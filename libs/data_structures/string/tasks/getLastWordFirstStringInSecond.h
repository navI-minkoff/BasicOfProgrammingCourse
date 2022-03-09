#ifndef INC_1_GETLASTWORDFIRSTSTRINGINSECOND_H
#define INC_1_GETLASTWORDFIRSTSTRINGINSECOND_H

#include "../string_.h"

void wordDescriptorToString(WordDescriptor word, char *destination) {
    *copy(word.begin, word.end, destination) = '\0';
}

WordDescriptor getLastWordFirstStringInSecond(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    WordDescriptor word = {NULL, NULL};

    for (int i = _bag.size - 1; i >= 0; i--) {
        for (int j = 0; j < _bag2.size; j++) {
            if (areWordsEqual(_bag.words[i], _bag2.words[j])) {
                word = _bag.words[i];
                j = _bag.size;
                i = -1;
            }
        }
    }

    return word;
}


void test_getLastWordInFirstStringInTheSecondString_hasWordInStrings() {
    char s1[] = "apple string last first second";
    char s2[] = "first third programming apple";
    WordDescriptor word = getLastWordFirstStringInSecond(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("first", res);
}

void test_getLastWordInFirstStringInTheSecondString_hasOneWordInStrings() {
    char s1[] = "apple cinema gaming programming";
    char s2[] = "math programming listening";
    WordDescriptor word = getLastWordFirstStringInSecond(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("programming", res);
}

void test_getLastWordInFirstStringInTheSecondString_hasNotUnion() {
    char s1[] = "apple cinema gaming";
    char s2[] = "math cooking listening";
    WordDescriptor word = getLastWordFirstStringInSecond(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING (" ", res);
}

void test_getLastWordInFirstStringInTheSecondString_emptyStrings() {
    char s1[] = "";
    char s2[] = "";
    WordDescriptor word = getLastWordFirstStringInSecond(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("", res);
}

void test_getLastWordFirstStringInSecond() {
    test_getLastWordInFirstStringInTheSecondString_hasWordInStrings();
    test_getLastWordInFirstStringInTheSecondString_hasOneWordInStrings();
    test_getLastWordInFirstStringInTheSecondString_hasNotUnion();
    test_getLastWordInFirstStringInTheSecondString_emptyStrings();
}
#endif
