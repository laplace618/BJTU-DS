#include <stdio.h>
#include "../Status.h"     //**��01 ����**//
#include "SString.c"    //**��04 ��**//

/*
 * �Ƚϣ�StrCompare
 *
 *��ע��
 * �ú�������SString����ļ��ж���
 */
int Algo_4_16(SString S, SString T);

int main(int argc, char* argv[]) {
    char* t = "ab**c*de***fg";
    char* s = "ab**c*de***fh";
    SString T, S, M1, M2;
    int i;
    
    printf("�������� 4.16 ��֤...������\n");
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
 * �Ƚϣ�StrCompare
 *
 *��ע��
 * �ú�������SString����ļ��ж���
 */
int Algo_4_16(SString S, SString T) {
    return StrCompare(S, T);
}


