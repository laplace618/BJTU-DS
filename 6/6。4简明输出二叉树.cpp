#include <stdio.h>
#include <stdlib.h>

// 二叉树结点定义
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 输出一棵二叉树的结构
void printTreeStructure(TreeNode* root) {
    if (root == NULL) {
        printf(" ");
        return;
    }

    printf("%c(", root->data);
    printTreeStructure(root->left);
    printf(",");
    printTreeStructure(root->right);
    printf(")");
}

int main() {
    // 构建一棵示例二叉树
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = 'A';
    root->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->data = 'B';
    root->left->left = root->left->right = NULL;
    root->right = (TreeNode*)malloc(sizeof(TreeNode));
    root->right->data = 'C';
    root->right->left = root->right->right = NULL;

    // 输出二叉树的结构
    printTreeStructure(root);
    printf("\n");

    return 0;
}
