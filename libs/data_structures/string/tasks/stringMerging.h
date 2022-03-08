#ifndef INC_1_STRINGMERGING_H
#define INC_1_STRINGMERGING_H

#include "../string_.h"


void stringMerging(char *s1, char *s2, char *s3) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            s3 = copy(word1.begin, word1.end, s3);
            beginSearch1 = word1.end;
            *s3++ = ' ';
        }
        if (isW2Found) {
            s3 = copy(word2.begin, word2.end, s3);
            beginSearch2 = word2.end;
            *s3++ = ' ';
        }

    }

    if (*findNonSpace(s3) != '\0')
        s3--;

    *s3 = '\0';
    }

void test_changingWords_stringsAreEmpty() {
    char s[MAX_STRING_SIZE] = "";
    stringMerging(" ", " ", s);
    ASSERT_STRING("", s);
}

void test_changingWords_equalWordCount() {
    char s[MAX_STRING_SIZE];
    stringMerging("Hello World", "Wow Beautiful", s);
    ASSERT_STRING("Hello Wow World Beautiful", s);
}

void test_changingWords_moreWordInFirstString() {
    char s[MAX_STRING_SIZE];
    stringMerging("Hello World Beautiful", "Wow", s);
    ASSERT_STRING("Hello Wow World Beautiful", s);
}

void test_changingWords_moreWordInSecondString() {
    char s[MAX_STRING_SIZE];
    stringMerging("Wow", "Hello World Beautiful", s);
    ASSERT_STRING("Wow Hello World Beautiful", s);
}

void test_changingWords_firstStringIsEmpty() {
    char s[MAX_STRING_SIZE];
    stringMerging("", "Hello World Beautiful", s);
    ASSERT_STRING("Hello World Beautiful", s);
}

void test_changingWords_secondStringIsEmpty() {
    char s[MAX_STRING_SIZE];
    stringMerging("Hello World Beautiful", "", s);
    ASSERT_STRING("Hello World Beautiful", s);
}



void test_stringMerging() {
    test_changingWords_equalWordCount();
    test_changingWords_moreWordInFirstString();
    test_changingWords_moreWordInSecondString();
    test_changingWords_firstStringIsEmpty();
    test_changingWords_secondStringIsEmpty();
    test_changingWords_stringsAreEmpty();
}

#endif