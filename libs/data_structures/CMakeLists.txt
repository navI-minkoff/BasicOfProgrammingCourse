add_library(data_structures
        bitset/bitset.c
        unordered_array/unordered_array_set.h ordered_array/ordered_array_set.c
        ordered_array/ordered_array_set.c ordered_array/ordered_array_set.h
        matrix/matrix.c matrix/matrix.h string/string_.c string/string_.h
        main.c
        string/tasks/removeNonLetters.h string/tasks/allTaskTests.h string/tasks/removeExtraSpaces.h string/tasks/digitToStartForTheEntireString.h string/tasks/digitsAtTheBeginningWithChangeLettersAtTheEnd.h string/tasks/eachDigitWithItsCorrespondingNumberGaps.h string/tasks/replace.h string/tasks/wordsAreOrderedLexicographically.h string/tasks/printWordsInReverseOrder.h string/tasks/countWordsPalindromes.h string/tasks/stringMerging.h string/tasks/reverseWordOrderOfAString.h string/tasks/wordBeforeFirstWordWithA.h string/tasks/getLastWordFirstStringInSecond.h)

target_link_libraries(data_structures algorithms)

cmake_minimum_required(VERSION 3.16)

project(project C)


set(CMAKE_C_STANDARD 11)


# определение точки входа. Будет запущен файл main.c .
# указывается произвольная метка, в данном случае - project
add_executable(project main.c)


# создаём библиотеку
add_library(str string/string_.h string/string_.c
        string/tasks/removeNonLetters.h

        )


# описываем, что для запуска project потребуется сборка tasks
target_link_libraries(project str)
