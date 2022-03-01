#ifndef INC_1_ALLTASKTESTS_H
#define INC_1_ALLTASKTESTS_H

#include "removeNonLetters.h"
#include "removeExtraSpaces.h"
#include "digitToStartForTheEntireString.h"
#include "digitsAtTheBeginningWithChangeLettersAtTheEnd.h"
#include "eachDigitWithItsCorrespondingNumberGaps.h"

void test_tasks() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_digitsBeginningChangeLettersEndForTheEntireString();
    test_digitsAtTheEndForTheEntireString();
    test_eachDigitWithItsCorrespondingNumberGaps();
}

#endif //INC_1_ALLTASKTESTS_H
