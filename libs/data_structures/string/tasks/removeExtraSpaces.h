#ifndef INC_1_REMOVEEXTRASPACES_H
#define INC_1_REMOVEEXTRASPACES_H

#include "../string_.h"


void removeExtraSpaces(char *s) {
    char *begin = s;
    char *destination = s;
    while (isspace(*begin) && *begin != '\0')
        *destination++ = *begin++;

    while (*begin != '\0') {
        if (!isspace(*begin)) {
            *destination++ = *begin++;
        } else if (isspace(*begin) && isspace(*(begin + 1))) {
            while (isspace(*(begin + 1)) && *begin != '\0')
                begin++;
        } else
            *destination++ = *begin++;
    }

    *destination = '\0';
}


// TESTS


void test_removeExtraSpaces_onlyWhitespaceCharacters() {
    char s[] = "  ";
    removeExtraSpaces(s);

    ASSERT_STRING("  ", s);
}


void test_removeExtraSpaces_withWhitespaceCharacters() {
    char s[] = "I want five";
    removeExtraSpaces(s);

    ASSERT_STRING("I want five", s);
}

void test_removeExtraSpaces_withMoreWhitespaceCharacters() {
    char s[] = " I    want    five ";
    removeExtraSpaces(s);

    ASSERT_STRING(" I want five ", s);
}


void test_removeExtraSpaces() {
    test_removeExtraSpaces_onlyWhitespaceCharacters();
    test_removeExtraSpaces_withWhitespaceCharacters();
    test_removeExtraSpaces_withMoreWhitespaceCharacters();
}

#endif //INC_1_REMOVEEXTRASPACES_H
