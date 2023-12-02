#include <stdio.h>

#define MAX_SIZE 100

void findSaddlePoint(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int i, j, k;
    int saddlePointFound = 0;

    for (i = 0; i < rows; i++) {
        // 找到行中的最小值
        int minInRow = matrix[i][0];
        int minColumn = 0;

        for (j = 1; j < cols; j++) {
            if (matrix[i][j] < minInRow) {
                minInRow = matrix[i][j];
                minColumn = j;
            }
        }

        // 检查是否是所在列的最大值
        int isSaddlePoint = 1;
        for (k = 0; k < rows; k++) {
            if (matrix[k][minColumn] > minInRow) {
                isSaddlePoint = 0;
                break;
            }
        }

        // 输出鞍点位置
        if (isSaddlePoint) {
            printf("鞍点位置：A[%d,%d] = %d\n", i, minColumn, minInRow);
            saddlePointFound = 1;
        }
    }

    if (!saddlePointFound) {
        printf("矩阵中不存在鞍点。\n");
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols, i, j;

    printf("请输入矩阵的行数和列数：\n");
    scanf("%d %d", &rows, &cols);

    printf("请输入矩阵元素：\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    findSaddlePoint(matrix, rows, cols);

    return 0;
}
