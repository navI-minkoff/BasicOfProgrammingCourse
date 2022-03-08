#ifndef INC_1_REVERSEWORDORDEROFASTRING_H
#define INC_1_REVERSEWORDORDEROFASTRING_H

#include "../string_.h"

void reverseWordOrderOfAString(char *s) {
    char *end = copy(s, getEndOfString(s), _stringBuffer);
    char *beginSearch = end - 1;

    WordDescriptor currentWord;
    while (getWordReverse(beginSearch, _stringBuffer, &currentWord)) {
        s = copy(currentWord.begin, currentWord.end, s);
        *s++ = ' ';

        beginSearch = findNonSpaceReverse(currentWord.begin - 1, _stringBuffer);
    }

    if (*findNonSpace(s) != '\0')
        s--;

    *s = '\0';
}


void test_reverseWords_moreLettersInWord() {
    char s[MAX_STRING_SIZE] = "this   task   has   caused me   a lot of pain ";
    reverseWordOrderOfAString(s);

    ASSERT_STRING("pain of lot a me caused has task this", s);
}

void test_reverseWords_oneWord() {
    char s[MAX_STRING_SIZE] = "pain";
    reverseWordOrderOfAString(s);

    ASSERT_STRING("pain", s);
}

void test_reverseWords_oneLetter() {
    char s[MAX_STRING_SIZE] = "a b c a b c";
    reverseWordOrderOfAString(s);

    ASSERT_STRING("c b a c b a", s);
}

void test_reverseWords_empty() {
    char s[MAX_STRING_SIZE] = "";
    reverseWordOrderOfAString(s);

    ASSERT_STRING("", s);
}

void test_reverseWordOrderOfAString() {
    test_reverseWords_moreLettersInWord();
    test_reverseWords_oneLetter();
    test_reverseWords_empty();
    test_reverseWords_oneWord();
}

#endif
