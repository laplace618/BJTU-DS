#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <xls.h>

int main() {
    xlsWorkBook* pWB;
    xlsWorkSheet* pWS;
    int n, i;
    printf("请输入自变量数目：");
    scanf("%d", &n);

    pWB = xlsNewWorkbook();
    pWS = xlsNewWorksheet(pWB, "Data");

    xlsWriteStr(pWS, 1, 1, "x");
    xlsWriteStr(pWS, 1, 2, "x^2");
    xlsWriteStr(pWS, 1, 3, "x^3");
    xlsWriteStr(pWS, 1, 4, "exp(x)");
    xlsWriteStr(pWS, 1, 5, "log(x)");
    xlsWriteStr(pWS, 1, 6, "x");

    for (i = 1; i <= n; i++) {
        double x = i; // 这里可以根据需要定义自变量的范围和间隔
        double y_square = x * x;
        double y_cube = x * x * x;
        double y_exponential = exp(x);
        double y_logarithmic = log(x);
        double y_linear = x;

        xlsWriteNumber(pWS, i + 1, 1, x);
        xlsWriteNumber(pWS, i + 1, 2, y_square);
        xlsWriteNumber(pWS, i + 1, 3, y_cube);
        xlsWriteNumber(pWS, i + 1, 4, y_exponential);
        xlsWriteNumber(pWS, i + 1, 5, y_logarithmic);
        xlsWriteNumber(pWS, i + 1, 6, y_linear);
    }

    xlsSave(pWB, "data.xls");
    xlsClose(pWB);

    return 0;
}
