#include <stdio.h>
#include "../Status.h"     //**��01 ����**//
#include "SString.c"    //**��04 ��**//

/*
 * ��ʼ����StrAssign
 *
 *��ע��
 * �ú�������SString����ļ��ж���
 */
Status Algo_4_15(SString T, char* chars);

int main(int argc, char* argv[]) {
    char* t = "ab**c*de***fg";
    char* s = "ab**c*de***fh";
    SString T, S, M1, M2;
    int i;
    
    printf("�������� 4.15 ��֤...������\n");
    Algo_4_15(T, t);
    Algo_4_15(S, s);
    printf("T = ");
    StrPrint(T);
    printf("S = ");
    StrPrint(S);
    
    return 0;
}

/*
 * ��ʼ����StrAssign
 *
 *��ע��
 * �ú�������SString����ļ��ж���
 */
Status Algo_4_15(SString T, char* chars) {
    return StrAssign(T, chars);
}
