#ifndef INC_1_DIGITTOSTARTFORTHEENTIRESTRING_H
#define INC_1_DIGITTOSTARTFORTHEENTIRESTRING_H

#include "../string_.h"

void digitsAtTheBeginningWithChangeLettersAtTheEnd(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);

}

void digitsBeginningChangeLettersEndForTheEntireString(char *s) {
    WordDescriptor w;
    char *beginSearch = s;
    while (getWord(beginSearch, &w)) {
        digitsAtTheBeginningWithChangeLettersAtTheEnd(w);
        beginSearch = w.end;
    }
}

// TESTS

void test_digitsBeginningChangeLettersEndForTheEntireString_digitsAtTheEnd() {
    char s[] = "ABC123";
    digitsBeginningChangeLettersEndForTheEntireString(s);

    ASSERT_STRING("321ABC", s);
}

void test_digitsBeginningChangeLettersEndForTheEntireString_digitsInWords() {
    char s[] = "A3B2C1       F42C42F42";
    digitsBeginningChangeLettersEndForTheEntireString(s);

    ASSERT_STRING("123ABC       242424FCF", s);
}

void test_digitsBeginningChangeLettersEndForTheEntireString_digitsInStart() {
    char s[] = "321ABC       424242FCF";
    digitsBeginningChangeLettersEndForTheEntireString(s);

    ASSERT_STRING("123ABC       242424FCF", s);
}

void test_digitsBeginningChangeLettersEndForTheEntireString_noDigits() {
    char s[] = "ABC FCF";
    digitsBeginningChangeLettersEndForTheEntireString(s);

    ASSERT_STRING("ABC FCF", s);
}

void test_digitsBeginningChangeLettersEndForTheEntireString_noLetters() {
    char s[] = "123 4 56";
    digitsBeginningChangeLettersEndForTheEntireString(s);

    ASSERT_STRING("321 4 65", s);
}

void test_digitsBeginningChangeLettersEndForTheEntireString_allSpaces() {
    char s[] = "\n   \t \n";
    digitsBeginningChangeLettersEndForTheEntireString(s);

    ASSERT_STRING("\n   \t \n", s);
}

void test_digitsBeginningChangeLettersEndForTheEntireString_emptyString() {
    char s[] = "";
    digitsBeginningChangeLettersEndForTheEntireString(s);
    ASSERT_STRING("", s);
}

void test_digitsBeginningChangeLettersEndForTheEntireString() {
    test_digitsBeginningChangeLettersEndForTheEntireString_digitsAtTheEnd();
    test_digitsBeginningChangeLettersEndForTheEntireString_digitsInWords();
    test_digitsBeginningChangeLettersEndForTheEntireString_digitsInStart();
    test_digitsBeginningChangeLettersEndForTheEntireString_noDigits();
    test_digitsBeginningChangeLettersEndForTheEntireString_noLetters();
    test_digitsBeginningChangeLettersEndForTheEntireString_allSpaces();
    test_digitsBeginningChangeLettersEndForTheEntireString_emptyString();

}

#endif //INC_1_DIGITTOSTARTFORTHEENTIRESTRING_H
