#include <stdio.h>
#include "../Status.h"     //**▲01 绪论**//
#include "SString.c"    //**▲04 串**//

/*
 * 初始化：StrAssign
 *
 *【注】
 * 该函数已在SString相关文件中定义
 */
Status Algo_4_15(SString T, char* chars);

int main(int argc, char* argv[]) {
    char* t = "ab**c*de***fg";
    char* s = "ab**c*de***fh";
    SString T, S, M1, M2;
    int i;
    
    printf("███题 4.15 验证...███\n");
    Algo_4_15(T, t);
    Algo_4_15(S, s);
    printf("T = ");
    StrPrint(T);
    printf("S = ");
    StrPrint(S);
    
    return 0;
}

/*
 * 初始化：StrAssign
 *
 *【注】
 * 该函数已在SString相关文件中定义
 */
Status Algo_4_15(SString T, char* chars) {
    return StrAssign(T, chars);
}
