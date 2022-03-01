add_library(data_structures
        bitset/bitset.c
        unordered_array/unordered_array_set.h ordered_array/ordered_array_set.c
        ordered_array/ordered_array_set.c ordered_array/ordered_array_set.h
        matrix/matrix.c matrix/matrix.h string/string_.c string/string_.h)

target_link_libraries(data_structures algorithms)