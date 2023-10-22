#include <stdio.h>

int main() {
    int k = 4; // 4阶Fibonacci序列
    int max = 200;
    int fib[k]; // 存储最后k项Fibonacci序列
    int n = 0; // 项数

    // 初始化前k项
    for (int i = 0; i < k; i++) {
        fib[i] = 0;
    }
    fib[3] = 1; // 初始值 f3=1

    // 计算Fibonacci序列
    while (1) {
        int fn = fib[n % k];
        int fn_plus_1 = 0;

        for (int i = 0; i < k; i++) {
            fn_plus_1 += fib[(n - i + k) % k];
        }
        n++;

        // 输出 fn
        printf("f%d = %d\n", n - 1, fn);

        if (fn > max) {
            break;
        }

        // 将 fn+1 放入队列
        fib[n % k] = fn_plus_1;
    }

    return 0;
}
