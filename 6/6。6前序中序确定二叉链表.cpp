#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char TElemType;

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

// ��������
void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);

// ����ǰ�����к��������й����������ĵݹ麯��
BiTree BuildTree(char *pre, char *in, int pre_start, int pre_end, int in_start, int in_end);

int main() {
    char pre[] = "ABDGHECFIKLMJ";
    char in[] = "GDHBEACMLKIFJ";

    // ����ʵ��1��
    // ǰ�����У�ABDECF
    // �������У�DBEACF
    
    // ����ʵ��2��
    // ǰ������: "GDAFECB"
    // ��������: "ADEFGBC"

    BiTree root = BuildTree(pre, in, 0, strlen(pre) - 1, 0, strlen(in) - 1);

    // ��������õĶ�����
    printf("��������ǰ��������Ϊ: ");
    PreOrderTraverse(root);
    printf("\n");

    printf("������������������Ϊ: ");
    InOrderTraverse(root);
    printf("\n");

    return 0;
}

// ǰ�����
void PreOrderTraverse(BiTree T) {
    if (T != NULL) {
        printf("%c ", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

// �������
void InOrderTraverse(BiTree T) {
    if (T != NULL) {
        InOrderTraverse(T->lchild);
        printf("%c ", T->data);
        InOrderTraverse(T->rchild);
    }
}

BiTree BuildTree(char *pre, char *in, int pre_start, int pre_end, int in_start, int in_end) {
    if (pre_start > pre_end || in_start > in_end) {
        return NULL;
    }

    BiTNode *T = (BiTNode *)malloc(sizeof(BiTNode));
    if (!T) {
        exit(0);
    }

    T->data = pre[pre_start];
    T->lchild = T->rchild = NULL;

    int i;
    for (i = in_start; i <= in_end; i++) {
        if (in[i] == T->data) {
            break;
        }
    }

    int left_len = i - in_start;
    T->lchild = BuildTree(pre, in, pre_start + 1, pre_start + left_len, in_start, i - 1);
    T->rchild = BuildTree(pre, in, pre_start + left_len + 1, pre_end, i + 1, in_end);

    return T;
}
