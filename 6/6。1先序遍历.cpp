#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char TElemType; // 假设二叉树结点数据类型为字符

// 二叉树结点定义
typedef struct BiTNode {
    TElemType data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
} BiTNode, *BiTree;

// 创建二叉树函数
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

// 先序遍历二叉树
void PreOrderTraverse(BiTree T) {
    if (T) {
        printf("%c ", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

int main() {
    char input[] = "FBA  DC  E  G H  "; // 先序遍历的扩展序列
    int index = 0;
    
    BiTree T = CreateBiTree(input, &index);

    printf("先序遍历结果为: ");
    PreOrderTraverse(T);
    printf("\n");

    return 0;
}
