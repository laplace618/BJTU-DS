#include <stdio.h>
#include <stdlib.h>

// 二叉树结点定义
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 根据中序和先序遍历序列构建二叉树
TreeNode* buildTree(char* inorder, char* preorder, int inStart, int inEnd, int preStart, int preEnd) {
    if (inStart > inEnd || preStart > preEnd) {
        return NULL;
    }

    // 根结点是前序遍历的第一个元素
    char rootValue = preorder[preStart];
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = rootValue;
    root->left = root->right = NULL;

    // 在中序遍历序列中找到根结点的位置
    int rootIndex;
    for (rootIndex = inStart; rootIndex <= inEnd; rootIndex++) {
        if (inorder[rootIndex] == rootValue) {
            break;
        }
    }

    // 递归构建左子树和右子树
    root->left = buildTree(inorder, preorder, inStart, rootIndex - 1, preStart + 1, preStart + (rootIndex - inStart));
    root->right = buildTree(inorder, preorder, rootIndex + 1, inEnd, preStart + (rootIndex - inStart) + 1, preEnd);

    return root;
}

// 先序遍历输出二叉树结构
void printTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%c ", root->data);
    if (root->left || root->right) {
        printf("(");
        printTree(root->left);
        printf(",");
        printTree(root->right);
        printf(")");
    }
}

int main() {
    char inorder[] = "ABCDEFGHIJK";
    char preorder[] = "EBADCFHGIKJ";
    int length = sizeof(inorder) / sizeof(inorder[0]);

    TreeNode* root = buildTree(inorder, preorder, 0, length - 1, 0, length - 1);

    printf("二叉树结构输出: ");
    printTree(root);
    printf("\n");

    return 0;
}
