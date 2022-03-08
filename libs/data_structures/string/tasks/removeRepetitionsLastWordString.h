#ifndef INC_1_REMOVEREPETITIONSLASTWORDSTRING_H
#define INC_1_REMOVEREPETITIONSLASTWORDSTRING_H

#include "../string_.h"

void removeRepetitionsLastWordString(char *s) {
    WordDescriptor lastWord;
    WordDescriptor currentWord;
    if (!getWordReverse(getEndOfString(s), s - 1, &lastWord))
        return;

    char *beginSearch = s;
    while (getWord(beginSearch, &currentWord)) {
        if (areWordsEqual(currentWord, lastWord) != 0) {
            s = copy(currentWord.begin, currentWord.end, s);
            *s++ = ' ';
        }

        beginSearch = currentWord.end;
    }

    if (*findNonSpace(s) != '\0')
        s--;

    *s = '\0';
}

void test_deleteMatchesWithTheLastWord_someLastWords() {
    char s[] = "Hello World Hello Hello Book Hello";
    removeRepetitionsLastWordString(s);
//    ASSERT_STRING("World Book", s);
}

void test_deleteMatchesWithTheLastWord_moreEqualWords() {
    char s[] = "Hello Hello Hello Hello";
    removeRepetitionsLastWordString(s);
//    ASSERT_STRING("", s);
}

void test_deleteMatchesWithTheLastWord_oneWord() {
    char s[] = "Hello";
    removeRepetitionsLastWordString(s);
//    ASSERT_STRING("", s);
}

void test_deleteMatchesWithTheLastWord_empty() {
    char s[] = "";
    removeRepetitionsLastWordString(s);
    ASSERT_STRING("", s);
}

void test_removeRepetitionsLastWordString() {
    test_deleteMatchesWithTheLastWord_someLastWords();
    test_deleteMatchesWithTheLastWord_oneWord();
    test_deleteMatchesWithTheLastWord_empty();
    test_deleteMatchesWithTheLastWord_moreEqualWords();
}

#endif
