#ifndef INC_1_EACHDIGITWITHITSCORRESPONDINGNUMBERGAPS_H
#define INC_1_EACHDIGITWITHITSCORRESPONDINGNUMBERGAPS_H

#include "../string_.h"

#define CODE_NULL 48

void eachDigitWithItsCorrespondingNumberGaps(char *s) {

    char *buffer = _stringBuffer;
    char *endString = getEndOfString(s);
    copy(s, endString, buffer);
    *(endString - s + buffer) = '\0';

    while (*buffer != '\0') {
        if (isalpha(*buffer))
            *s++ = *buffer;
        else if (isdigit(*buffer)) {
            int amountOfSpaces = *buffer - CODE_NULL;
            for (int i = 0; i < amountOfSpaces; i++)
                *s++ = ' ';
        }
        buffer++;
    }

    *s = '\0';
}

void test_eachDigitWithItsCorrespondingNumberGaps_figuresInWord() {
    char s[MAX_STRING_SIZE] = "A2B0C1";
    eachDigitWithItsCorrespondingNumberGaps(s);
    ASSERT_STRING("A  BC ", s);
}

void test_eachDigitWithItsCorrespondingNumberGaps_AfterBeforeWord() {
    char s[MAX_STRING_SIZE] = "2A3B1E0C";
    eachDigitWithItsCorrespondingNumberGaps(s);
    ASSERT_STRING("  A   B EC", s);
}

void test_eachDigitWithItsCorrespondingNumberGaps_noFigures() {
    char s[MAX_STRING_SIZE] = "ABEC";
    eachDigitWithItsCorrespondingNumberGaps(s);
    ASSERT_STRING("ABEC", s);
}

void test_eachDigitWithItsCorrespondingNumberGaps_noLetters() {
    char s[MAX_STRING_SIZE] = "123";
    eachDigitWithItsCorrespondingNumberGaps(s);
    ASSERT_STRING("      ", s);
}

void test_eachDigitWithItsCorrespondingNumberGaps_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    eachDigitWithItsCorrespondingNumberGaps(s);
    ASSERT_STRING("", s);
}

void test_eachDigitWithItsCorrespondingNumberGaps() {
    test_eachDigitWithItsCorrespondingNumberGaps_figuresInWord();
    test_eachDigitWithItsCorrespondingNumberGaps_AfterBeforeWord();
    test_eachDigitWithItsCorrespondingNumberGaps_noFigures();
    test_eachDigitWithItsCorrespondingNumberGaps_noLetters();
    test_eachDigitWithItsCorrespondingNumberGaps_emptyString();
}

#endif //INC_1_EACHDIGITWITHITSCORRESPONDINGNUMBERGAPS_H
