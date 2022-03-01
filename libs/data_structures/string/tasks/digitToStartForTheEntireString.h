#ifndef INC_1_DIGITTOSTARTFORTHEENTIRESTRING_H
#define INC_1_DIGITTOSTARTFORTHEENTIRESTRING_H

#include "../string_.h"

void digitToStartWithoutChangingOrder(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartForTheEntireString(char *s) {
    WordDescriptor w;
    char *beginSearch = s;
    while (getWord(beginSearch, &w)) {
        digitToStartWithoutChangingOrder(w);
        beginSearch = w.end;
    }
}

// TESTS

void test_digitToStartForTheEntireString_digitsAtTheEnd() {
    char s[] = "ABC123";
    digitToStartForTheEntireString(s);

    ASSERT_STRING("123ABC", s);
}

void test_digitToStartForTheEntireString_digitsInWords() {
    char s[] = "A3B2C1       F42C42F42";
    digitToStartForTheEntireString(s);

    ASSERT_STRING("321ABC       424242FCF", s);
}

void test_digitToStartForTheEntireString_digitsInStart() {
    char s[] = "321ABC       424242FCF";
    digitToStartForTheEntireString(s);

    ASSERT_STRING("321ABC       424242FCF", s);
}

void test_digitToStartForTheEntireString_noDigits() {
    char s[] = "ABC FCF";
    digitToStartForTheEntireString(s);

    ASSERT_STRING("ABC FCF", s);
}

void test_digitToStartForTheEntireString_noLetters() {
    char s[] = "123 4 56";
    digitToStartForTheEntireString(s);

    ASSERT_STRING("123 4 56", s);
}

void test_digitToStartForTheEntireString_allSpaces() {
    char s[] = "\n   \t \n";
    digitToStartForTheEntireString(s);

    ASSERT_STRING("\n   \t \n", s);
}

void test_digitToStartForTheEntireString_emptyString() {
    char s[] = "";
    digitToStartForTheEntireString(s);
    ASSERT_STRING("", s);
}

void test_digitToStartForTheEntireString() {
    test_digitToStartForTheEntireString_digitsAtTheEnd();
    test_digitToStartForTheEntireString_digitsInWords();
    test_digitToStartForTheEntireString_digitsInStart();
    test_digitToStartForTheEntireString_noDigits();
    test_digitToStartForTheEntireString_noLetters();
    test_digitToStartForTheEntireString_allSpaces();
    test_digitToStartForTheEntireString_emptyString();

}
#endif //INC_1_DIGITTOSTARTFORTHEENTIRESTRING_H
