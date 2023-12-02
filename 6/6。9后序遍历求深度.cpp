#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

int Depth(BiTree T) {
    if (!T)
        return 0;
    else {
        int depthLeft = Depth(T->lchild);
        int depthRight = Depth(T->rchild);
        int depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
        return depthval;
    }
}

int main() {
    // 构建一个示例二叉树
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    root->data = 'A';
    root->lchild = (BiTree)malloc(sizeof(BiTNode));
    root->lchild->data = 'B';
    root->rchild = (BiTree)malloc(sizeof(BiTNode));
    root->rchild->data = 'C';
    root->lchild->lchild = root->lchild->rchild = NULL;
    root->rchild->lchild = root->rchild->rchild = NULL;

    // 计算二叉树深度
    int depth = Depth(root);
    printf("二叉树的深度为: %d\n", depth);

    // 释放内存
    free(root->rchild);
    free(root->lchild);
    free(root);

    return 0;
}

