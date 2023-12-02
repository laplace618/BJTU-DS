#include <stdio.h>
#include <stdlib.h>

// 二叉树节点结构
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建新的二叉树节点
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 递归实现二叉树的先序遍历
void preOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);  // 先访问根节点
        preOrderTraversal(root->left);   // 再遍历左子树
        preOrderTraversal(root->right);  // 最后遍历右子树
    }
}

// 递归实现二叉树的中序遍历
void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);    // 先遍历左子树
        printf("%c ", root->data);  // 再访问根节点
        inOrderTraversal(root->right);   // 最后遍历右子树
    }
}

// 递归实现二叉树的后序遍历
void postOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);  // 先遍历左子树
        postOrderTraversal(root->right); // 再遍历右子树
        printf("%c ", root->data);  // 最后访问根节点
    }
}

int main() {
    // 创建一棵二叉树
    TreeNode* root = createNode('F');
    root->left = createNode('B');
    root->right = createNode('G');
    root->left->left = createNode('A');
    root->left->right = createNode('D');
    root->left->right->left = createNode('C');
    root->left->right->right = createNode('E');
    // root->right->left = createNode('F');
    root->right->right = createNode('H');

    printf("先序遍历: ");
    preOrderTraversal(root);
    printf("\n");

    printf("中序遍历: ");
    inOrderTraversal(root);
    printf("\n");

    printf("后序遍历: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
