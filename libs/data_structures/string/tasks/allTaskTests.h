#ifndef INC_1_ALLTASKTESTS_H
#define INC_1_ALLTASKTESTS_H

#include "removeNonLetters.h"
#include "removeExtraSpaces.h"
#include "digitToStartForTheEntireString.h"
#include "digitsAtTheBeginningWithChangeLettersAtTheEnd.h"
#include "eachDigitWithItsCorrespondingNumberGaps.h"
#include "replace.h"
#include "wordsAreOrderedLexicographically.h"
#include "printWordsInReverseOrder.h"
#include "countWordsPalindromes.h"
#include "stringMerging.h"

void test_tasks() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_digitsBeginningChangeLettersEndForTheEntireString();
    test_digitsAtTheEndForTheEntireString();
    test_eachDigitWithItsCorrespondingNumberGaps();
    test_replace();
    test_wordsAreOrderedLexicographically();
    test_countWordsPalindromes();
    test_stringMerging();
}

#endif //INC_1_ALLTASKTESTS_H
