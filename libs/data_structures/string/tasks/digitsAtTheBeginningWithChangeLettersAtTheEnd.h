#ifndef INC_1_DIGITSATTHEBEGINNINGWITHCHANGELETTERSATTHEEND_H
#define INC_1_DIGITSATTHEBEGINNINGWITHCHANGELETTERSATTHEEND_H

#include "../string_.h"

void digitsAtTheEndOfALetterAtTheBeginningWithReordering(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitsAtTheEndTheEntireString(char *s) {
    WordDescriptor w;
    char *beginSearch = s;
    while (getWord(beginSearch, &w)) {
        digitsAtTheEndOfALetterAtTheBeginningWithReordering(w);
        beginSearch = w.end;
    }
}

// TESTS

void test_digitsAtTheEndForTheEntireString_digitsAtTheEnd() {
    char s[] = "ABC123";
    digitsAtTheEndTheEntireString(s);

    ASSERT_STRING("123ABC", s);
}

void test_digitsAtTheEndForTheEntireString_digitsInWords() {
    char s[] = "A3B2C1       F42C42F42";
    digitsAtTheEndTheEntireString(s);

    ASSERT_STRING("321ABC       424242FCF", s);
}

void test_digitsAtTheEndForTheEntireString_digitsInStart() {
    char s[] = "321ABC       424242FCF";
    digitsAtTheEndTheEntireString(s);

    ASSERT_STRING("321ABC       424242FCF", s);
}

void test_digitsAtTheEndForTheEntireString_noDigits() {
    char s[] = "ABC FCF";
    digitsAtTheEndTheEntireString(s);

    ASSERT_STRING("ABC FCF", s);
}

void test_digitsAtTheEndForTheEntireString_noLetters() {
    char s[] = "123 4 56";
    digitsAtTheEndTheEntireString(s);

    ASSERT_STRING("123 4 56", s);
}

void test_digitsAtTheEndForTheEntireString_allSpaces() {
    char s[] = "\n   \t \n";
    digitsAtTheEndTheEntireString(s);

    ASSERT_STRING("\n   \t \n", s);
}

void test_digitsAtTheEndForTheEntireString_emptyString() {
    char s[] = "";
    digitsAtTheEndTheEntireString(s);
    ASSERT_STRING("", s);
}

void test_digitsAtTheEndForTheEntireString() {
    test_digitsAtTheEndForTheEntireString_digitsAtTheEnd();
    test_digitsAtTheEndForTheEntireString_digitsInWords();
    test_digitsAtTheEndForTheEntireString_digitsInStart();
    test_digitsAtTheEndForTheEntireString_noDigits();
    test_digitsAtTheEndForTheEntireString_noLetters();
    test_digitsAtTheEndForTheEntireString_allSpaces();
    test_digitsAtTheEndForTheEntireString_emptyString();

}

#endif
