#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char TElemType; // ��������������������Ϊ�ַ�

// ��������㶨��
typedef struct BiTNode {
    TElemType data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
} BiTNode, *BiTree;

// ��������������
BiTree CreateBiTree(char* str, int* index) {
    char ch = str[(*index)++];
    if (ch == ' ' || ch == '\0') {
        return NULL;
    } else {
        BiTree T = (BiTNode*)malloc(sizeof(BiTNode));
        T->data = ch;
        T->lchild = CreateBiTree(str, index);
        T->rchild = CreateBiTree(str, index);
        return T;
    }
}

// �������������
void PreOrderTraverse(BiTree T) {
    if (T) {
        printf("%c ", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

int main() {
    char input[] = "FBA  DC  E  G H  "; // �����������չ����
    int index = 0;
    
    BiTree T = CreateBiTree(input, &index);

    printf("����������Ϊ: ");
    PreOrderTraverse(T);
    printf("\n");

    return 0;
}
