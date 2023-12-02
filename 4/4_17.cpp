#include <stdio.h>
#include "../Status.h"     //**��01 ����**//
#include "SString.h"    //**��04 ��**//

/*
 * ��ʼ����StrAssign
 *
 *��ע��
 * �ú�������SString����ļ��ж���
 */
Status Algo_4_15(SString T, char* chars);

/*
 * �滻��Replace
 *
 *��ע��
 * �ú�������SString����ļ��ж���
 */
Status Algo_4_17(SString S, SString T, SString V);


int main(int argc, char* argv[]) {
    char* t = "ab**c*de***fg";
    char* s = "ab**c*de***fh";
    SString T, S, M1, M2;
    int i;
    
    printf("�������� 4.17 ��֤...������\n");
    Algo_4_15(M1, "**");
    Algo_4_15(M2, "^");
    Algo_4_17(S, M1, M2);
    printf("�� \"^\" �滻 \"**\" ��\nS = ");
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
/*
 * �滻��Replace
 *
 *��ע��
 * �ú�������SString����ļ��ж���
 */
Status Algo_4_17(SString S, SString T, SString V) {
    return Replace(S, T, V);
}
