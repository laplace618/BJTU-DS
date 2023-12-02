#include <stdio.h>
#include <stdlib.h>

// ��������㶨��
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ���һ�ö������Ľṹ
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
    // ����һ��ʾ��������
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = 'A';
    root->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->data = 'B';
    root->left->left = root->left->right = NULL;
    root->right = (TreeNode*)malloc(sizeof(TreeNode));
    root->right->data = 'C';
    root->right->left = root->right->right = NULL;

    // ����������Ľṹ
    printTreeStructure(root);
    printf("\n");

    return 0;
}
