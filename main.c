#include <stdio.h>
#include "libs/data_structures/bitset/bitset.h"
#include "libs/data_structures/unordered_array/unordered_array_set.h"
#include "libs/data_structures/ordered_array/ordered_array_set.h"
#include "libs/data_structures/matrix/matrix.h"

int getSum(int *a, int n) {
    int s = a[0];
    for (int i = 1; i < n; i++)
        s += a[i];
    return s;
}

// getMemMatrix

void test_getMemMatrix_zeroRowsAndCols() {
    matrix m = getMemMatrix(0, 0);
    assert(m.nRows == 0 && m.nCols == 0 && m.values != NULL);
    freeMemMatrix(&m);
}

void test_getMemMatrix_rowsAndCols() {
    matrix m = getMemMatrix(3, 2);
    assert(m.nRows == 3 && m.nCols == 2 && m.values != NULL);
    freeMemMatrix(&m);
}

void test_getMemMatrix() {
    test_getMemMatrix_zeroRowsAndCols();
    test_getMemMatrix_rowsAndCols();
}

// getMemArrayOfMatrices

void test_getMemArrayOfMatrices_zeroRowsAndCols() {
    matrix *ms = getMemArrayOfMatrices(3, 0, 0);
    for (size_t i = 0; i < 3; i++)
        assert(ms[i].nRows == 0 && ms[i].nCols == 0 && ms[i].values != NULL);
    assert(ms != NULL);
    freeMemMatrices(ms, 3);
}

void test_getMemArrayOfMatrices_rowsAndCols() {
    matrix *ms = getMemArrayOfMatrices(3, 4, 1);
    for (size_t i = 0; i < 3; i++)
        assert(ms[i].nRows == 4 && ms[i].nCols == 1 && ms[i].values != NULL);
    assert(ms != NULL);
    freeMemMatrices(ms, 3);
}

void test_getMemArrayOfMatrices() {
    test_getMemArrayOfMatrices_zeroRowsAndCols();
    test_getMemArrayOfMatrices_rowsAndCols();
}

// swapRows
void test_swapRows_oneRow() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 2, 3
                                      },
                                      1, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1, 2, 3
                                      },
                                      1, 3);
    swapRows(m1, 0, 0);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapRows_twoRows() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 2, 3,
                                              3, 2, 1
                                      },
                                      2, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              3, 2, 1,
                                              1, 2, 3
                                      },
                                      2, 3);
    swapRows(m1, 0, 1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapRows_manyRows() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              7, 8, 9,
                                              4, 5, 6,
                                              1, 2, 3,
                                      },
                                      3, 3);
    swapRows(m1, 0, 2);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapRows() {
    test_swapRows_oneRow();
    test_swapRows_twoRows();
    test_swapRows_manyRows();
}

// swapColumns

void test_swapColumns_oneColumn() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1,
                                              2,
                                              3
                                      },
                                      3, 1);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1,
                                              2,
                                              3
                                      },
                                      3, 1);
    swapColumns(m1, 0, 0);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapColumns_twoColumns() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 4,
                                              2, 5,
                                              3, 6
                                      },
                                      3, 2);
    matrix m2 = createMatrixFromArray((int[]) {
                                              4, 1,
                                              5, 2,
                                              6, 3
                                      },
                                      3, 2);
    swapColumns(m1, 0, 1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapColumns_manyColumns() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 4, 7,
                                              2, 5, 8,
                                              3, 6, 9
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              7, 4, 1,
                                              8, 5, 2,
                                              9, 6, 3
                                      },
                                      3, 3);
    swapColumns(m1, 0, 2);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapColumns() {
    test_swapColumns_oneColumn();
    test_swapColumns_twoColumns();
    test_swapColumns_manyColumns();
}

// insertionSortRowsMatrixByRowCriteria

void test_insertionSortRowsMatrixByRowCriteria_oneRow() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 2, 3,
                                      },
                                      1, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1, 2, 3
                                      },
                                      1, 3);
    insertionSortRowsMatrixByRowCriteria(m1, getSum);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_insertionSortRowsMatrixByRowCriteria_twoRows() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              3, 3, 3,
                                              2, 2, 2
                                      },
                                      2, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              2, 2, 2,
                                              3, 3, 3
                                      },
                                      2, 3);
    insertionSortRowsMatrixByRowCriteria(m1, getSum);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_insertionSortRowsMatrixByRowCriteria_manyRows() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              3, 3, 3,
                                              2, 2, 2,
                                              2, 2, 2
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              2, 2, 2,
                                              2, 2, 2,
                                              3, 3, 3
                                      },
                                      3, 3);
    insertionSortRowsMatrixByRowCriteria(m1, getSum);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_insertionSortRowsMatrixByRowCriteria() {
    test_insertionSortRowsMatrixByRowCriteria_oneRow();
    test_insertionSortRowsMatrixByRowCriteria_twoRows();
    test_insertionSortRowsMatrixByRowCriteria_manyRows();
}

// insertionSortColsMatrixByColCriteria

void test_insertionSortColsMatrixByColCriteria_oneCol() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1,
                                              2,
                                              3
                                      },
                                      3, 1);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1,
                                              2,
                                              3
                                      },
                                      3, 1);
    insertionSortColsMatrixByColCriteria(m1, getSum);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_insertionSortColsMatrixByColCriteria_twoCols() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              3, 2,
                                              3, 2,
                                              3, 2

                                      },
                                      3, 2);
    matrix m2 = createMatrixFromArray((int[]) {
                                              2, 3,
                                              2, 3,
                                              2, 3
                                      },
                                      3, 2);
    insertionSortColsMatrixByColCriteria(m1, getSum);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_insertionSortColsMatrixByColCriteria_manyCols() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              3, 2, 2,
                                              3, 2, 2,
                                              3, 2, 2
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              2, 2, 3,
                                              2, 2, 3,
                                              2, 2, 3
                                      },
                                      3, 3);
    insertionSortColsMatrixByColCriteria(m1, getSum);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_insertionSortColsMatrixByColCriteria() {
    test_insertionSortColsMatrixByColCriteria_oneCol();
    test_insertionSortColsMatrixByColCriteria_twoCols();
    test_insertionSortColsMatrixByColCriteria_manyCols();
}

// isSquareMatrix

void test_isSquareMatrix_squareM() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 2, 2,
                                             3, 1, 2,
                                             3, 2, 1
                                     },
                                     3, 3);
    assert(isSquareMatrix(m));
    freeMemMatrix(&m);
}

void test_isSquareMatrix_notSquareM() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 2, 1,
                                             2, 1, 2,
                                     },
                                     2, 3);
    assert(!isSquareMatrix(m));
    freeMemMatrix(&m);
}

void test_isSquareMatrix() {
    test_isSquareMatrix_squareM();
    test_isSquareMatrix_notSquareM();
}

// areTwoMatricesEqual

void test_areTwoMatricesEqual_equal() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              3, 2, 1,
                                              3, 2, 1,
                                              3, 2, 1

                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              3, 2, 1,
                                              3, 2, 1,
                                              3, 2, 1
                                      },
                                      3, 3);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_areTwoMatricesEqual_notEqual1() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              3, 2, 2,
                                              3, 2, 2,
                                              3, 2, 2
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              2, 2, 3,
                                              2, 2, 3,
                                              2, 2, 3
                                      },
                                      3, 3);
    assert(!areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_areTwoMatricesEqual_notEqual2() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              3, 2, 2,
                                              3, 2, 2,
                                              3, 2, 2
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              2, 2, 3,
                                              2, 2, 3
                                      },
                                      2, 3);
    assert(!areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_areTwoMatricesEqual() {
    test_areTwoMatricesEqual_equal();
    test_areTwoMatricesEqual_notEqual1();
    test_areTwoMatricesEqual_notEqual2();
}

// isEMatrix

void test_isEMatrix_identity() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 0, 0,
                                             0, 1, 0,
                                             0, 0, 1
                                     },
                                     3, 3);
    assert(isEMatrix(m));
    freeMemMatrix(&m);
}

void test_isEMatrix_notIdentity() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 0, 1,
                                             0, 1, 0,
                                             1, 0, 1
                                     },
                                     3, 3);
    assert(!isEMatrix(m));
    freeMemMatrix(&m);
}

void test_isEMatrix() {
    test_isEMatrix_identity();
    test_isEMatrix_notIdentity();
}

// isSymmetricMatrix

void test_isSymmetricMatrix_symmetric() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 0, 0,
                                             0, 1, 0,
                                             0, 0, 1
                                     },
                                     3, 3);
    assert(isSymmetricMatrix(m));
    freeMemMatrix(&m);
}

void test_isSymmetricMatrix_notSymmetric() {
    matrix m = createMatrixFromArray((int[]) {
                                             5, 4, 3,
                                             0, 5, 0,
                                             5, 4, 5
                                     },
                                     3, 3);
    assert(!isSymmetricMatrix(m));
    freeMemMatrix(&m);
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_symmetric();
    test_isSymmetricMatrix_notSymmetric();
}

// transposeSquareMatrix

void test_transposeSquareMatrix_oneRowAndCol() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1
                                      },
                                      1, 1);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1
                                      },
                                      1, 1);
    transposeSquareMatrix(&m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_transposeSquareMatrix_manyRowsAndCols() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 2, 3,
                                              1, 2, 3,
                                              1, 2, 3
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1, 1, 1,
                                              2, 2, 2,
                                              3, 3, 3
                                      },
                                      3, 3);
    transposeSquareMatrix(&m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_transposeSquareMatrix_twoTransposes() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 2, 3,
                                              1, 2, 3,
                                              1, 2, 3
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1, 2, 3,
                                              1, 2, 3,
                                              1, 2, 3
                                      },
                                      3, 3);
    transposeSquareMatrix(&m1);
    transposeSquareMatrix(&m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_transposeSquareMatrix() {
    test_transposeSquareMatrix_oneRowAndCol();
    test_transposeSquareMatrix_manyRowsAndCols();
    test_transposeSquareMatrix_twoTransposes();
}

// getMinValuePos

void test_getMinValuePos_oneElement() {
    matrix m = createMatrixFromArray((int[]) {
                                             5
                                     },
                                     1, 1);
    position p = getMinValuePos(m);
    assert(p.rowIndex == 0 && p.colIndex == 0);
    freeMemMatrix(&m);
}

void test_getMinValuePos_manyElements1() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 2, 3,
                                             1, 2, 3,
                                             1, 2, 3
                                     },
                                     3, 3);
    position p = getMinValuePos(m);
    assert(p.rowIndex == 0 && p.colIndex == 0);
    freeMemMatrix(&m);
}

void test_getMinValuePos_manyElements2() {
    matrix m = createMatrixFromArray((int[]) {
                                             2, 2, 3,
                                             5, 2, 3,
                                             1, 2, 3
                                     },
                                     3, 3);
    position p = getMinValuePos(m);
    assert(p.rowIndex == 2 && p.colIndex == 0);
    freeMemMatrix(&m);
}

void test_getMinValuePos() {
    test_getMinValuePos_oneElement();
    test_getMinValuePos_manyElements1();
    test_getMinValuePos_manyElements2();
}

// getMaxValuePos

void test_getMaxValuePos_oneElement() {
    matrix m = createMatrixFromArray((int[]) {
                                             5
                                     },
                                     1, 1);
    position p = getMaxValuePos(m);
    assert(p.rowIndex == 0 && p.colIndex == 0);
    freeMemMatrix(&m);
}

void test_getMaxValuePos_manyElements1() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 2, 3,
                                             1, 2, 3,
                                             1, 2, 3
                                     },
                                     3, 3);
    position p = getMaxValuePos(m);
    assert(p.rowIndex == 0 && p.colIndex == 2);
    freeMemMatrix(&m);
}

void test_getMaxValuePos_manyElements2() {
    matrix m = createMatrixFromArray((int[]) {
                                             2, 2, 3,
                                             5, 2, 3,
                                             1, 2, 3
                                     },
                                     3, 3);
    position p = getMaxValuePos(m);
    assert(p.rowIndex == 1 && p.colIndex == 0);
    freeMemMatrix(&m);
}

void test_getMaxValuePos() {
    test_getMaxValuePos_oneElement();
    test_getMaxValuePos_manyElements1();
    test_getMaxValuePos_manyElements2();
}

// createMatrixFromArray

void test_createMatrixFromArray_zeroRowsAndCols() {
    matrix m = createMatrixFromArray((int[]) {

                                     },
                                     0, 0);
    assert(m.nRows == 0 && m.nCols == 0);
    freeMemMatrix(&m);
}

void test_createMatrixFromArray_manyRowsAndCols() {
    matrix m = createMatrixFromArray((int[]) {
                                             2, 2, 3,
                                             5, 2, 3,
                                             1, 2, 3
                                     },
                                     3, 3);
    assert(m.nRows == 3 && m.nCols == 3);
    freeMemMatrix(&m);
}

void test_createMatrixFromArray() {
    test_createMatrixFromArray_zeroRowsAndCols();
    test_createMatrixFromArray_manyRowsAndCols();

}

// createArrayOfMatrixFromArray
void test_createArrayOfMatrixFromArray_zeroRowsAndCols() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {}, 3, 0, 0);
    for(size_t i = 0; i < 3; i++)
        assert(ms[i].nRows == 0 && ms[i].nCols == 0);
    freeMemMatrices(ms, 3);
}

void test_createArrayOfMatrixFromArray_manyRowsAndCols() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {}, 3, 2, 2);
    for(size_t i = 0; i < 3; i++)
        assert(ms[i].nRows == 2 && ms[i].nCols == 2);
    freeMemMatrices(ms, 3);
}

void test_createArrayOfMatrixFromArray() {
    test_createArrayOfMatrixFromArray_zeroRowsAndCols();
    test_createArrayOfMatrixFromArray_manyRowsAndCols();
}

void test() {
    test_getMemMatrix();
    test_getMemArrayOfMatrices();
    test_swapRows();
    test_isSquareMatrix();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
    test_areTwoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
    test_createMatrixFromArray();
    test_createArrayOfMatrixFromArray();
}


// first task

void swapColsWithMaxAndMinSquareMatrix(matrix m) {
    position maxPos = getMaxValuePos(m);
    position minPos = getMinValuePos(m);
    swapColumns(m, maxPos.colIndex, minPos.colIndex);
}

// second task

int getMax(const int *a, int n) {
    int max = a[0];
    for (size_t i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getSum);
}

// third task

int main() {
    matrix m = getMemMatrix(3, 3);

    inputMatrix(m);

    sortRowsByMinElement(m);

    outputMatrix(m);

//    test();

    return 0;
}
