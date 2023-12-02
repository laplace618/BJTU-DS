#include <stdio.h>

#define MAX_TERMS 101
#define MAX_COL 50

typedef struct {
    int row;
    int col;
    int value;
} Element;

typedef struct {
    Element data[MAX_TERMS];
    int rows;
    int cols;
    int terms;
} SparseMatrix;

void transposeSparse(SparseMatrix* original, SparseMatrix* transposed) {
    int numCols = original->cols;
    int numRows = original->rows;
    int numTerms = original->terms;
    int numTransposed = 0;

    transposed->rows = numCols;
    transposed->cols = numRows;
    transposed->terms = numTerms;

    if (numTerms > 0) {
        int col, i;
        int rowTerms[MAX_COL], startingPos[MAX_COL];

        for (col = 0; col < numCols; col++) {
            rowTerms[col] = 0;
        }

        for (i = 0; i < numTerms; i++) {
            col = original->data[i].col;
            rowTerms[col]++;
        }

        startingPos[0] = 0;

        for (col = 1; col < numCols; col++) {
            startingPos[col] = startingPos[col - 1] + rowTerms[col - 1];
        }

        for (i = 0; i < numTerms; i++) {
            col = original->data[i].col;
            int j = startingPos[col];
            transposed->data[j].row = original->data[i].col;
            transposed->data[j].col = original->data[i].row;
            transposed->data[j].value = original->data[i].value;
            startingPos[col]++;
        }
    }
}

void displaySparseMatrix(SparseMatrix* matrix) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < matrix->terms; i++) {
        printf("%d\t%d\t%d\n", matrix->data[i].row, matrix->data[i].col, matrix->data[i].value);
    }
}

int main() {
    SparseMatrix originalMatrix, transposedMatrix;

    printf("Enter the number of rows and columns in the matrix: ");  
    scanf("%d %d", &originalMatrix.rows, &originalMatrix.cols);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &originalMatrix.terms);

    printf("Enter row, column, and value for each non-zero element:\n");
    for (int i = 0; i < originalMatrix.terms; i++) {
        scanf("%d %d %d", &originalMatrix.data[i].row, &originalMatrix.data[i].col, &originalMatrix.data[i].value);
    }

    printf("\nOriginal Sparse Matrix:\n");
    displaySparseMatrix(&originalMatrix);

    transposeSparse(&originalMatrix, &transposedMatrix);

    printf("\nTransposed Sparse Matrix:\n");
    displaySparseMatrix(&transposedMatrix);

    return 0;
}
