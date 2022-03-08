#ifndef INC_1_COUNTWORDSPALINDROMES_H
#define INC_1_COUNTWORDSPALINDROMES_H

#include "../string_.h"

bool isPalindrome(char *begin, char *end) {

    while (begin < end) {
        if (*begin != *end)
            return false;

        begin++;
        end--;
    }

    return true;
}

int countWordsPalindromes(char *s) {
    int countWPalindromes = 0;
    char *endS = getEndOfString(s);
    char *commaPosition = find(s, endS, ',');
    char *lastCommaPosition = findReverse(endS, s, ',');
    char *lastWord = findNonSpaceReverse(endS, s);

    char *currentPosition = findNonSpace(s);
    while (*currentPosition != '\0') {

        if (*commaPosition == '\0') {
            countWPalindromes += isPalindrome(currentPosition,
                                              lastWord - 1);
            currentPosition = endS;
        } else {
            countWPalindromes += isPalindrome(currentPosition, commaPosition - 1);


            currentPosition = commaPosition + 1;
            commaPosition = find(currentPosition, endS, ',');
        }

    }

    return countWPalindromes;
}

void test_countOfPalindrome_hasPalindromes() {
    char s[] = "radar,tot,noon,redder,stats,apple,poop";
    assert(countWordsPalindromes(s) == 6);
}

void test_countOfPalindrome_oneWord() {
    char s[] = "radar";
    assert(countWordsPalindromes(s) == 1);
}

void test_countOfPalindrome_noSpaces() {
    char s[] = "radar,tot,noon,redder,stats,apple,poop";
    assert(countWordsPalindromes(s) == 6);
}

void test_countOfPalindrome_oneLetter() {
    char s[] = "a,b,c,d,e,f,g";
    assert(countWordsPalindromes(s) == 7);
}

void test_countWordsPalindromes() {
    test_countOfPalindrome_hasPalindromes();
    test_countOfPalindrome_noSpaces();
    test_countOfPalindrome_oneLetter();
    test_countOfPalindrome_oneWord();
}

#endif