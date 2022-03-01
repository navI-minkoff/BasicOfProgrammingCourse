#ifndef INC_1_REMOVENONLETTERS_H
#define INC_1_REMOVENONLETTERS_H

#include "../string_.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

// TESTS

void test_removeNonLetters_emptyString() {
    char s[] = "";
    removeNonLetters(s);

    ASSERT_STRING("", s);
}

void test_removeNonLetters_noWhitespaceCharacters() {
    char s[] = "Iwantfive";
    removeNonLetters(s);

    ASSERT_STRING("Iwantfive", s);
}

void test_removeNonLetters_withWhitespaceCharacters1() {
    char s[] = "I want five";
    removeNonLetters(s);

    ASSERT_STRING("Iwantfive", s);
}

void test_removeNonLetters_withWhitespaceCharacters2() {
    char s[] = "I \t wa\tnt \n five";
    removeNonLetters(s);

    ASSERT_STRING("Iwantfive", s);
}

void test_removeNonLetters_onlyWhitespaceCharacters() {
    char s[] = "\t \t    \n";
    removeNonLetters(s);

    ASSERT_STRING("", s);
}

void test_removeNonLetters() {
    test_removeNonLetters_noWhitespaceCharacters();
    test_removeNonLetters_withWhitespaceCharacters1();
    test_removeNonLetters_withWhitespaceCharacters2();
    test_removeNonLetters_emptyString();
    test_removeNonLetters_onlyWhitespaceCharacters();

}

#endif
