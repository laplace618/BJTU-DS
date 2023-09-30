#include <stdio.h>
#include <math.h>

int main() {
    int n; // 自变量数目
    printf("请输入自变量数目：");
    scanf("%d", &n);

    FILE *file = fopen("data.txt", "w"); // 打开文件用于写入

    for (int i = 1; i <= n; i++) {
        double x = i; // 这里可以根据需要定义自变量的范围和间隔
        double y1 = 5 * x * x;
        double y2 = 100 * x;
        double y3 = pow(2, x);
        double y4 = 200 * log(x);
        double y5 = 0.5 * x * x;

        fprintf(file, "%lf %lf %lf %lf %lf %lf\n", x, y1, y2, y3, y4, y5);
    }

    fclose(file); // 关闭文件

    return 0;
}
