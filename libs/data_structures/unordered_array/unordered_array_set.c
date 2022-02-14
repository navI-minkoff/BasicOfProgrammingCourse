#include "unordered_array_set.h"

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../algorithms/array/array.h"

// возвращает пустое множество для capacity элементов
unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};
}

// освобождает неиспользуемую память, отведенную под
// множество a
static void unordered_array_set_shrinkToFit(unordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

// возвращает множество, состоящее из элементов массива a размера size
unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        unordered_array_set_insert(&set, a[i]);
    unordered_array_set_shrinkToFit(&set);
    return set;
}

// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_(set->data, set->size, value);
}

void qsort(void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *));

int compare_ints1(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return 1;
    if (arg1 > arg2) return -1;
    return 0;
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    assert(set1.size == set2.size);
    qsort(set1.data, set1.size, sizeof(int), compare_ints1);
    qsort(set2.data, set2.size, sizeof(int), compare_ints1);
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

// добавляет элемент value в множество set
void unordered_array_set_insert(unordered_array_set *set, int value) {
    if (unordered_array_set_in(set, value) == set->size) {
        unordered_array_set_isAbleAppend(set);
        append_(set->data, &set->size, value);
    }
}

// удаляет элемент value из множества set
void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    size_t pos = unordered_array_set_in(set, value);
    if (pos != set->size)
        deleteByPosUnsaveOrder_(set->data, &set->size, pos);
}

// возвращает объединение множеств set1 и set2
unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set set = unordered_array_set_create(set1.size + set2.size);
    for (size_t i = 0; i < set1.size; i++)
        append_(set.data, &set.size, set1.data[i]);
    for (size_t i = 0; i < set2.size; i++)
        unordered_array_set_insert(&set, set2.data[i]);
    return set;
}

// возвращает пересечение множеств set1 и set2
unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set set = unordered_array_set_create(set1.size + set2.size);
    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(&set2, set1.data[i]) != set2.size)
            append_(set.data, &set.size, set1.data[i]);
    }
    return set;
}

// возвращает разность множеств set1 и set2
unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set set = unordered_array_set_create(set1.size + set2.size);
    for (size_t i = 0; i < set1.size; i++)
        if (unordered_array_set_in(&set2, set1.data[i]) == set2.size)
            append_(set.data, &set.size, set1.data[i]);

    return set;
}

// возвращает симметрическую разность множеств set1 и set2
unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set difference1 = unordered_array_set_difference(set1, set2);
    unordered_array_set difference2 = unordered_array_set_difference(set2, set1);
    unordered_array_set difference3 = unordered_array_set_union(difference1, difference2);
    unordered_array_set_delete(difference1);
    unordered_array_set_delete(difference2);
    return difference3;
}

// возвращает дополнение до универсума множества set
unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {

    return (unordered_array_set) unordered_array_set_difference(universumSet, set);
}

// вывод множества set
void unordered_array_set_print(unordered_array_set set) {
    outputArray_(set.data, set.size);
}

// освобождает память, занимаемую множеством set
void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}
