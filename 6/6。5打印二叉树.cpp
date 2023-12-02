#include <stdio.h>
#include <stdlib.h>

// ��������㶨��
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ��������ͺ������й���������
TreeNode* buildTree(char* inorder, char* postorder, int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) {
        return NULL;
    }

    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = postorder[postEnd];

    int inIndex;
    for (inIndex = inStart; inIndex <= inEnd; inIndex++) {
        if (inorder[inIndex] == root->data) {
            break;
        }
    }

    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postEnd - (inEnd - inIndex), postEnd - 1);
    root->left = buildTree(inorder, postorder, inStart, inIndex - 1, postStart, postStart + (inIndex - inStart) - 1);

    return root;
}

// ���һ�ö������Ľṹ
void printTreeStructure(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    printf("%c(", root->data);
    printTreeStructure(root->left);
    printf(",");
    printTreeStructure(root->right);
    printf(")");
}

int main() {
    char inorder[] = "DCBGEAHFIJK";
    char postorder[] = "DCEGBFHKJIA";

    TreeNode* root = buildTree(inorder, postorder, 0, 10, 0, 10);

    printf("�������ĽṹΪ: ");
    printTreeStructure(root);
    printf("\n");

    return 0;
}
