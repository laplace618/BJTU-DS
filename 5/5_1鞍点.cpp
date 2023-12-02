#include <stdio.h>

#define MAX_SIZE 100

void findSaddlePoint(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int i, j, k;
    int saddlePointFound = 0;

    for (i = 0; i < rows; i++) {
        // �ҵ����е���Сֵ
        int minInRow = matrix[i][0];
        int minColumn = 0;

        for (j = 1; j < cols; j++) {
            if (matrix[i][j] < minInRow) {
                minInRow = matrix[i][j];
                minColumn = j;
            }
        }

        // ����Ƿ��������е����ֵ
        int isSaddlePoint = 1;
        for (k = 0; k < rows; k++) {
            if (matrix[k][minColumn] > minInRow) {
                isSaddlePoint = 0;
                break;
            }
        }

        // �������λ��
        if (isSaddlePoint) {
            printf("����λ�ã�A[%d,%d] = %d\n", i, minColumn, minInRow);
            saddlePointFound = 1;
        }
    }

    if (!saddlePointFound) {
        printf("�����в����ڰ��㡣\n");
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols, i, j;

    printf("����������������������\n");
    scanf("%d %d", &rows, &cols);

    printf("���������Ԫ�أ�\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    findSaddlePoint(matrix, rows, cols);

    return 0;
}
