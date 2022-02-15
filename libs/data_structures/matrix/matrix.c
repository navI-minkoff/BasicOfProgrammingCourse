#include "matrix.h"


matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);
    free(m->values);
    m->nRows = 0;
    m->nCols = 0;
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(&ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (size_t i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (size_t i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
        printf("\n");
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (size_t i = 0; i < m.nRows; i++)
        swap(&m.values[i][j1], &m.values[i][j2]);
}

void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int auxiliaryArray[m.nRows];
    for (size_t i = 0; i < m.nRows; i++)
        auxiliaryArray[i] = criteria(m.values[i], m.nCols);
    for (int i = 1; i < m.nRows; i++) {
        int t = auxiliaryArray[i];
        int j = i;
        while (j > 0 && auxiliaryArray[j - 1] > t) {
            auxiliaryArray[j] = auxiliaryArray[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        auxiliaryArray[j] = t;
    }
}

void copyColMatrix(matrix m, int col, int *a) {
    for (size_t i = 0; i < m.nRows; i++)
        a[i] = m.values[i][col];
}

void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int auxiliaryArray[m.nCols];
    int copyCol[m.nRows];
    for (int i = 0; i < m.nCols; i++) {
        copyColMatrix(m, i, copyCol);
        auxiliaryArray[i] = criteria(copyCol, m.nRows);
    }
    for (int i = 1; i < m.nCols; i++) {
        int t = auxiliaryArray[i];
        int j = i;
        while (j > 0 && auxiliaryArray[j - 1] > t) {
            auxiliaryArray[j] = auxiliaryArray[j - 1];
            swapColumns(m, j, j - 1);
            j--;
        }
        auxiliaryArray[j] = t;
    }
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;
    for (size_t i = 0; i < m1.nRows; i++)
        for (size_t j = 0; j < m1.nCols; j++)
            if (m1.values[i][j] != m2.values[i][j])
                return false;
    return true;
}

bool isEMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            if ((i == j && m.values[i][j] != 1) ||
                (i != j && m.values[i][j] != 0))
                return false;
    return true;
}

bool isSymmetricMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            if (i != j && m.values[i][j] != m.values[j][i])
                return false;
    return true;
}

void transposeSquareMatrix(matrix *m) {
    size_t nRows = 0;
    for (size_t j = 0; j < m->nCols; j++, nRows++) {
        for (size_t i = nRows; i < m->nRows; i++)
            if (i != j)
                swap(&m->values[i][j], &m->values[j][i]);
    }
}

position getMinValuePos(matrix m) {
    position p = {0, 0};
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < m.values[p.rowIndex][p.colIndex]) {
                p.rowIndex = i;
                p.colIndex = j;
            }
    return p;

}

position getMaxValuePos(matrix m) {
    position p = {0, 0};
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] > m.values[p.rowIndex][p.colIndex]) {
                p.rowIndex = i;
                p.colIndex = j;
            }
    return p;
}

matrix createMatrixFromArray(const int *a,
                             int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values,
                                     int nMatrices, int nRows, int nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}
