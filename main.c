#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
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

void outputArray__(const long long *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
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
    for (size_t i = 0; i < 3; i++)
        assert(ms[i].nRows == 0 && ms[i].nCols == 0);
    freeMemMatrices(ms, 3);
}

void test_createArrayOfMatrixFromArray_manyRowsAndCols() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {}, 3, 2, 2);
    for (size_t i = 0; i < 3; i++)
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

int getMin(int *a, int n) {
    int min = a[0];
    for (size_t i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMin);
}

// third task

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

// fourth task

matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows) {
        fprintf(stderr, "unsuitable matrices");
        exit(1);
    }
    matrix m = getMemMatrix(m1.nRows, m2.nCols);
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++) {
            m.values[i][j] = 0;
            for (size_t k = 0; k < m1.nCols; k++)
                m.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }
    return m;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m)) {
        *m = mulMatrices(*m, *m);
    }
}

// fifth task

bool isUnique(long long *a, int n) {
    for (size_t i = 0; i < n - 1; i++)
        for (size_t j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return false;
    return true;
}

long long getSum_(int *a, int n) {
    long long s = a[0];
    for (int i = 1; i < n; i++)
        s += a[i];
    return s;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long sumRowsMatrix[m.nCols];
    for (size_t i = 0; i < m.nCols; i++)
        sumRowsMatrix[i] = getSum_(m.values[i], m.nCols);
    if (isUnique(sumRowsMatrix, m.nCols))
        transposeSquareMatrix(&m);
}

// sixth task

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix m = mulMatrices(m1, m2);
    return isEMatrix(m);
}

// seventh task

int max(int a, int b) {
    return a > b ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    if (m.nRows == 1 && m.nCols == 1)
        return 0;
    int n = m.nRows + m.nCols - 2;
    int maximaOfPseudodiagonals[n];
    for (size_t i = 0; i < n; i++)
        maximaOfPseudodiagonals[i] = 0;
    int indexPdDiagonalElement;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (j != i) {
                if (i > j)
                    indexPdDiagonalElement = j - i + m.nRows - 1;
                else if (i < j)
                    indexPdDiagonalElement = j - i + m.nRows - 2;
                maximaOfPseudodiagonals[indexPdDiagonalElement] =
                        max(maximaOfPseudodiagonals[indexPdDiagonalElement], m.values[i][j]);
            }
    return getSum_(maximaOfPseudodiagonals, n);
}

// eighth task

int getMinInArea(matrix m) {
    position posMax = getMaxValuePos(m);
    int min = m.values[posMax.rowIndex][posMax.colIndex];
    int rBorder = posMax.colIndex;
    int lBorder = posMax.colIndex;
    int potentialMin;
    for (int i = posMax.rowIndex - 1; i >= 0; i--) {
        if (rBorder != m.nCols - 1)
            rBorder++;
        if (lBorder != 0)
            lBorder--;
        potentialMin = getMin(&m.values[i][lBorder], rBorder - lBorder + 1);
        if (potentialMin < min)
            min = potentialMin;
    }
    return min;
}

// ninth task

float getDistance(int *a, int n) {
    double sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += pow(a[i], 2);
    return sqrt(sum);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m,
                                           float (*criteria)(int *, int)) {
    float auxiliaryArray[m.nRows];
    for (size_t i = 0; i < m.nRows; i++)
        auxiliaryArray[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++) {
        float t = auxiliaryArray[i];
        int j = i;

        while (j > 0 && auxiliaryArray[j - 1] > t) {
            auxiliaryArray[j] = auxiliaryArray[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        auxiliaryArray[j] = t;
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

// tenth task

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);

    int countUnique = 1;
    for (size_t i = 0; i < n - 1; i++)
        if (a[i] != a[i + 1])
            countUnique++;

    return countUnique;
}

int countEqClassesByRowsSum(matrix m) {
    long long sumStockArray[m.nRows];
    for (size_t i = 0; i < m.nRows; i++) {
        long long sumStock = 0;
        for (size_t j = 0; j < m.nCols; j++)
            sumStock += m.values[i][j];
        sumStockArray[i] = sumStock;
    }

    return countNUnique(sumStockArray, m.nRows);
}

// eleventh task

int getNSpecialElement(matrix m) {
    int countSpecialElement = 0;
    for (size_t j = 0; j < m.nCols; j++) {
        long long sumCol = 0;
        int maxElement = m.values[0][j];
        for (size_t i = 0; i < m.nRows; i++) {
            if (m.values[i][j] > maxElement)
                maxElement = m.values[i][j];
            sumCol += m.values[i][j];
        }
        if (sumCol - maxElement < maxElement)
            countSpecialElement++;
    }

    return countSpecialElement;
}

// twelfth task

void swapPenultimateRow(matrix m) {
    if (m.nRows < 2) {
        fprintf(stderr, "few rows\n");
        exit(3);
    }

    position posMin = getMinValuePos(m);
    int firsRowElement = m.values[m.nRows - 2][posMin.colIndex];
    for (size_t i = 0; i < m.nRows; i++)
        m.values[m.nRows - 2][i] = m.values[i][posMin.colIndex];

    m.values[m.nRows - 2][m.nCols - 2] = firsRowElement;
}

// thirteenth task

bool isNonDescendingSorted(const int *a, int n) {
    for (size_t i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;

    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;

    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int countNonDescendingMatrices = 0;
    for (size_t i = 0; i < nMatrix; i++)
        countNonDescendingMatrices += hasAllNonDescendingRows(ms[i]);

    return countNonDescendingMatrices;
}

// fourteenth task

int countZeroRows(matrix m) {
    int zeroRows = 0;
    for (size_t i = 0; i < m.nRows; i++) {
        bool isZeroRow = true;
        for (size_t j = 0; j < m.nCols && isZeroRow; j++) {
            if (m.values[i][j] != 0)
                isZeroRow = false;
        }
        zeroRows += isZeroRow;
    }

    return zeroRows;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int countZeroRowsMatrix[nMatrix];
    int maxZeroRows = 0;
    for (size_t i = 0; i < nMatrix; i++) {
        int zeroRows = countZeroRows(ms[i]);
        countZeroRowsMatrix[i] = zeroRows;
        if (zeroRows > maxZeroRows)
            maxZeroRows = zeroRows;
    }

    for (size_t i = 0; i < nMatrix; i++)
        if (countZeroRowsMatrix[i] == maxZeroRows)
            outputMatrix(ms[i]);
}

// fifteenth task

double getMaximumRate(matrixf m) {
    double maxRate = fabs(m.values[0][0]);
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            double potentialMaxRate = fabs(m.values[i][j]);
            if (potentialMaxRate > maxRate)
                maxRate = potentialMaxRate;
        }
    }

    return maxRate;
}

void printMatrixWithMaxRate(matrixf *ms, int nMatrix) {
    double minRate = getMaximumRate(ms[0]);
    double maxRatesMatrix[nMatrix];
    maxRatesMatrix[0] = minRate;
    for (size_t i = 1; i < nMatrix; i++) {
        double maxRate = getMaximumRate(ms[i]);
        maxRatesMatrix[i] = maxRate;
        if (maxRate < minRate)
            minRate = maxRate;
    }

    for (size_t i = 0; i < nMatrix; i++) {
        if (fabs(maxRatesMatrix[i] - minRate) < DBL_EPSILON)
            outputMatrixF(ms[i]);
    }
}

// sixteenth task

int getNSpecialElement2(matrix m) {
    int countSpecialElement = 0;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            bool isSpecialElement = 1;
            for (size_t k = 0; k < m.nCols; k++) {
                if (k < j) {
                    if (m.values[i][j] <= m.values[i][k])
                        isSpecialElement = false;
                } else if (k > j)
                    if (m.values[i][j] > m.values[i][k])
                        isSpecialElement = false;
            }
            countSpecialElement += isSpecialElement;
        }
    }

    return countSpecialElement;
}

// TEST FOR TASKS

// 1
void test_swapColsWithMaxAndMinSquareMatrix_maxAndMinimumInDifferentColumns() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 4, 9,
                                              2, 5, 8,
                                              3, 6, 7
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              9, 4, 1,
                                              8, 5, 2,
                                              7, 6, 3
                                      },
                                      3, 3);
    swapColsWithMaxAndMinSquareMatrix(m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapColsWithMaxAndMinSquareMatrix_maxAndMinimumInOneColumn() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 4, 3,
                                              2, 5, 8,
                                              9, 6, 7
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1, 4, 3,
                                              2, 5, 8,
                                              9, 6, 7
                                      },
                                      3, 3);
    swapColsWithMaxAndMinSquareMatrix(m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapColsWithMaxAndMinSquareMatrix_oneElement() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1
                                      },
                                      1, 1);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1
                                      },
                                      1, 1);
    swapColsWithMaxAndMinSquareMatrix(m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapColsWithMaxAndMinSquareMatrix() {
    test_swapColsWithMaxAndMinSquareMatrix_maxAndMinimumInDifferentColumns();
    test_swapColsWithMaxAndMinSquareMatrix_maxAndMinimumInOneColumn();
    test_swapColsWithMaxAndMinSquareMatrix_oneElement();
}

// 2
void test_sortRowsByMinElement_differentMin() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              2, 4, 3,
                                              1, 5, 8,
                                              9, 6, 7
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1, 5, 8,
                                              2, 4, 3,
                                              9, 6, 7
                                      },
                                      3, 3);
    sortRowsByMinElement(m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortRowsByMinElement_sameMin() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              2, 1, 3,
                                              1, 5, 8,
                                              9, 6, 1
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              2, 1, 3,
                                              1, 5, 8,
                                              9, 6, 1
                                      },
                                      3, 3);
    sortRowsByMinElement(m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortRowsByMinElement_oneElement() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1
                                      },
                                      1, 1);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1
                                      },
                                      1, 1);
    sortRowsByMinElement(m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortRowsByMinElement() {
    test_sortRowsByMinElement_differentMin();
    test_sortRowsByMinElement_sameMin();
    test_sortRowsByMinElement_oneElement();
}

// 3

void test_sortColsByMinElement_differentMin() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              2, 4, 3,
                                              8, 5, 1,
                                              9, 6, 7
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              3, 2, 4,
                                              1, 8, 5,
                                              7, 9, 6
                                      },
                                      3, 3);
    sortColsByMinElement(m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortColsByMinElement_sameMin() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              2, 1, 3,
                                              1, 5, 8,
                                              9, 6, 1
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              2, 1, 3,
                                              1, 5, 8,
                                              9, 6, 1
                                      },
                                      3, 3);
    sortColsByMinElement(m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortColsByMinElement_oneElement() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1
                                      },
                                      1, 1);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1
                                      },
                                      1, 1);
    sortColsByMinElement(m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortColsByMinElement() {
    test_sortColsByMinElement_differentMin();
    test_sortColsByMinElement_sameMin();
    test_sortColsByMinElement_oneElement();
}

// 4

void test_getSquareOfMatrixIfSymmetric_symmetric() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 2, 3,
                                              2, 1, 2,
                                              3, 2, 1
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              14, 10, 10,
                                              10, 9, 10,
                                              10, 10, 14
                                      },
                                      3, 3);
    getSquareOfMatrixIfSymmetric(&m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_getSquareOfMatrixIfSymmetric_notSymmetric() {
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
    getSquareOfMatrixIfSymmetric(&m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_symmetric();
    test_getSquareOfMatrixIfSymmetric_notSymmetric();
}

// 5

void test_transposeIfMatrixHasNotEqualSumOfRows_hasNotEqualSum() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9
                                      },
                                      3, 3);
    matrix m2 = createMatrixFromArray((int[]) {
                                              1, 4, 7,
                                              2, 5, 8,
                                              3, 6, 9
                                      },
                                      3, 3);
    transposeIfMatrixHasNotEqualSumOfRows(m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_hasEqualSum() {
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
    transposeIfMatrixHasNotEqualSumOfRows(m1);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    test_transposeIfMatrixHasNotEqualSumOfRows_hasNotEqualSum();
    test_transposeIfMatrixHasNotEqualSumOfRows_hasEqualSum();
}

// 6

void test_isMutuallyInverseMatrices_inverseMatrices() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              3, -5,
                                              1, -2
                                      },
                                      2, 2);
    matrix m2 = createMatrixFromArray((int[]) {
                                              2, -5,
                                              1, -3
                                      },
                                      2, 2);
    assert(isMutuallyInverseMatrices(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_isMutuallyInverseMatrices_notInverseMatrices() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              3, -5,
                                              1, -2
                                      },
                                      2, 2);
    matrix m2 = createMatrixFromArray((int[]) {
                                              2, -5,
                                              2, -3
                                      },
                                      2, 2);
    assert(!isMutuallyInverseMatrices(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices_inverseMatrices();
    test_isMutuallyInverseMatrices_notInverseMatrices();
}

// 7

void test_findSumOfMaxesOfPseudoDiagonal_oneElement() {
    matrix m = createMatrixFromArray((int[]) {
                                             1
                                     },
                                     1, 1);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 0);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneRow() {
    matrix m = createMatrixFromArray((int[]) {
                                             1, 2, 3
                                     },
                                     1, 3);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 5);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneCol() {
    matrix m = createMatrixFromArray((int[]) {
                                             1,
                                             2,
                                             3
                                     },
                                     3, 1);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 5);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonal_manyRowsAndCols() {
    matrix m = createMatrixFromArray((int[]) {
                                             3, 2, 5, 4,
                                             1, 3, 6, 3,
                                             3, 2, 1, 2
                                     },
                                     3, 4);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 20);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    test_findSumOfMaxesOfPseudoDiagonal_oneElement();
    test_findSumOfMaxesOfPseudoDiagonal_oneRow();
    test_findSumOfMaxesOfPseudoDiagonal_oneCol();
    test_findSumOfMaxesOfPseudoDiagonal_manyRowsAndCols();
}

// 8

void test_getMinInArea_maxInFirstRow() {
    matrix m = createMatrixFromArray((int[]) {
                                             3, 12, 5, 4,
                                             1, 3, 6, 3,
                                             3, 2, 1, 2
                                     },
                                     3, 4);
    assert(getMinInArea(m) == 12);
    freeMemMatrix(&m);
}

void test_getMinInArea_oneElement() {
    matrix m = createMatrixFromArray((int[]) {
                                             1
                                     },
                                     1, 1);
    assert(getMinInArea(m) == 1);
    freeMemMatrix(&m);
}

void test_getMinInArea_maxLeft() {
    matrix m = createMatrixFromArray((int[]) {
                                             3, 4, 5, 4,
                                             1, 3, 6, 3,
                                             12, 2, 1, 2
                                     },
                                     3, 4);
    assert(getMinInArea(m) == 1);
    freeMemMatrix(&m);
}

void test_getMinInArea_maxRight() {
    matrix m = createMatrixFromArray((int[]) {
                                             3, 4, 5, 4,
                                             1, 3, 6, 3,
                                             7, 2, 1, 12
                                     },
                                     3, 4);
    assert(getMinInArea(m) == 3);
    freeMemMatrix(&m);
}

void test_getMinInArea_maxInCenter() {
    matrix m = createMatrixFromArray((int[]) {
                                             3, 4, 5, 4, 1,
                                             1, 3, 6, 3, 3,
                                             7, 2, 12, 6, 4,
                                             4, 1, 11, 8, 1
                                     },
                                     4, 5);
    assert(getMinInArea(m) == 1);
    freeMemMatrix(&m);
}

void test_getMinInArea() {
    test_getMinInArea_maxInFirstRow();
    test_getMinInArea_oneElement();
    test_getMinInArea_maxLeft();
    test_getMinInArea_maxRight();
    test_getMinInArea_maxInCenter();


}

void test_tasks() {
    test_swapColsWithMaxAndMinSquareMatrix();
    test_sortRowsByMinElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea();

}

int main() {

//    test();
//    test_tasks();
//
//    matrixf *ms = createArrayOfMatrixFromArrayF(
//            (double[]) {
//                    0.2, 1.2,
//                    1.4, 0.2,
//                    0.3, 0.2,
//
//                    0.1, 1.2,
//                    1.4, 0.2,
//                    0.3, 0.1,
//
//                    0.1, 1.2,
//                    1.3, 0.2,
//                    0.3, 0.1,
//            },
//            3, 3, 2);
//
//    printMatrixWithMaxRate(ms, 3);
//    swapPenultimateRow(m);
//    outputMatrix(m);
    matrix m = createMatrixFromArray((int[]) {
            2, 3, 5, 5, 6,
            6, 2, 3, 8, 12,
            12, 12, 2, 1, 2
    }, 3, 5);
    printf("%d", getNSpecialElement2(m));
    return 0;
}
