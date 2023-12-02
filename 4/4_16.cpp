#include <stdio.h>
#include "../Status.h"     //**▲01 绪论**//
#include "SString.c"    //**▲04 串**//

/*
 * 比较：StrCompare
 *
 *【注】
 * 该函数已在SString相关文件中定义
 */
int Algo_4_16(SString S, SString T);

int main(int argc, char* argv[]) {
    char* t = "ab**c*de***fg";
    char* s = "ab**c*de***fh";
    SString T, S, M1, M2;
    int i;
    
    printf("███题 4.16 验证...███\n");
    i = Algo_4_16(S, T);
    if(i > 0) {
        printf("S > T\n");
    } else if(i < 0) {
        printf("S < T\n");
    } else {
        printf("S == T\n");
    }
    
    return 0;
}

/*
 * 比较：StrCompare
 *
 *【注】
 * 该函数已在SString相关文件中定义
 */
int Algo_4_16(SString S, SString T) {
    return StrCompare(S, T);
}


