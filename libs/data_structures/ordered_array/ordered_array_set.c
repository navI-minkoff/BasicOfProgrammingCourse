#include "ordered_array_set.h"


#include <assert.h>
#include <malloc.h>
#include <stdbool.h>

// возвращает пустое множество, в которое можно вставить capacity элементов
ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};
}

// освобождает неиспользуемую память, отведенную под
// множество a
static void ordered_array_set_shrinkToFit(ordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

void qsort(void *ptr, size_t count, size_t size, int (*comp )(const void *, const void *));

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return 1;
    if (arg1 > arg2) return -1;
    return 0;
}

// возвращает множество, состоящее из элементов массива a размера size
ordered_array_set ordered_array_set_create_from_array(const int *a,
                                                      size_t size) {
    ordered_array_set set = ordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        ordered_array_set_insert(&set, a[i]);
    return set;
}

// возвращает значение позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t ordered_array_set_in(ordered_array_set *set, int value) {
    return binarySearch_(set->data, set->size, value);
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool ordered_array_set_isEqual(ordered_array_set set1,
                               ordered_array_set set2) {
    if (set1.size != set2.size)
        return false;
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}


// возвращает значение ’истина’, если subset является подмножеством set
// иначе - ’ложь’
bool ordered_array_set_isSubset(ordered_array_set subset,
                                ordered_array_set set) {
    if (subset.size == 0 || set.size == 0)
        return false;
    size_t subsetIndex = 0;
    size_t setIndex = 0;
    while (subsetIndex < subset.size || setIndex < set.size) {
        if (subset.data[subsetIndex] > set.data[setIndex])
            setIndex++;
        else if (subset.data[subsetIndex] == set.data[setIndex]) {
            subsetIndex++;
            setIndex++;
        }
        else
            return false;
    }
    return true;
}


// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

// добавляет элемент value в множество set
void ordered_array_set_insert(ordered_array_set *set, int value) {
    ordered_array_set_isAbleAppend(set);
    if (ordered_array_set_in(set, value) == set->size) {
        int positionInsert = binarySearchLessOrEqual_(set->data, set->size,
                                                      value);
        if (positionInsert == -1)
            insert_(set->data, &set->size, 0, value);
        else
            insert_(set->data, &set->size, positionInsert + 1, value);
    }
}


void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    size_t pos = ordered_array_set_in(set, value);
    if (pos != set->size) {
        size_t indexDelete = pos;
        deleteByPosSaveOrder_(set->data, &set->size, indexDelete);
    }
}

// возвращает объединение множеств set1 и set2
ordered_array_set ordered_array_set_union(ordered_array_set set1,
                                          ordered_array_set set2) {
    ordered_array_set set = ordered_array_set_create(set1.size + set2.size);
    for (size_t i = 0; i < set1.size; i++)
        append_(set.data, &set.size, set1.data[i]);
    for (size_t i = 0; i < set2.size; i++)
        ordered_array_set_insert(&set, set2.data[i]);
    return set;
}

// возвращает пересечение множеств set1 и set2
ordered_array_set ordered_array_set_intersection(ordered_array_set
                                                 set1, ordered_array_set set2) {
    ordered_array_set set3 = ordered_array_set_create(set1.size + set2.size);
    size_t i = 0;
    size_t j = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] > set2.data[j]) {
            j++;
        } else if (set1.data[i] < set2.data[j]) {
            i++;
        } else {
            append_(set3.data, &set3.size, set1.data[i++]);
            j++;
        }
    }
    return set3;
}

// возвращает разность множеств set1 и set2
ordered_array_set ordered_array_set_difference(ordered_array_set
                                               set1, ordered_array_set set2) {
    ordered_array_set set3 = ordered_array_set_create(set1.size + set2.size);
    size_t i = 0;
    size_t j = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] < set2.data[j]) {
            append_(set3.data, &set3.size, set1.data[i++]);
        } else if (set1.data[i] == set2.data[j]) {
            i++;
        } else {
            j++;
        }
    }
    for (size_t k = i; k < set1.size; k++) {
        append_(set3.data, &set3.size, set1.data[k]);
    }
    return set3;
}

// возвращает симметрическую разность множеств set1 и set2
ordered_array_set ordered_array_set_symmetricDifference(
        ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set difference1 = ordered_array_set_difference(set1, set2);
    ordered_array_set difference2 = ordered_array_set_difference(set2, set1);
    ordered_array_set difference3 = ordered_array_set_union(difference1, difference2);
    ordered_array_set_delete(difference1);
    ordered_array_set_delete(difference2);
    return difference3;
}

// возвращает дополнение до универсума universumSet множества set
ordered_array_set ordered_array_set_complement(ordered_array_set
                                               set, ordered_array_set universumSet) {
    return ordered_array_set_difference(universumSet, set);
}

// вывод множества set
void ordered_array_set_print(ordered_array_set set) {
    outputArray_(set.data, set.size);
}

// освобождает память, занимаемую множеством set
void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}
