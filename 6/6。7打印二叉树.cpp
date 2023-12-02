#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��������㶨��
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ��������ͺ���������й���������
TreeNode* buildTree(char* inorder, char* postorder, int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) {
        return NULL;
    }

    char rootValue = postorder[postEnd];
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = rootValue;
    root->left = NULL;
    root->right = NULL;

    int inRootIdx; // ������������ҵ����ڵ��λ��
    for (inRootIdx = inStart; inRootIdx <= inEnd; inRootIdx++) {
        if (inorder[inRootIdx] == rootValue) {
            break;
        }
    }

    int leftSize = inRootIdx - inStart;
    
    root->left = buildTree(inorder, postorder, inStart, inRootIdx - 1, postStart, postStart + leftSize - 1);
    root->right = buildTree(inorder, postorder, inRootIdx + 1, inEnd, postStart + leftSize, postEnd - 1);

    return root;
}

// ���һ�ö������Ľṹ
void printTreeStructure(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    printf("%c(", root->data);
    if (root->left != NULL) {
        printTreeStructure(root->left);
    }
    printf(",");
    if (root->right != NULL) {
        printTreeStructure(root->right);
    }
    printf(")");
}

int main() {
    char inorder[] = "DCBGEAHFIJK";
    char postorder[] = "DCEGBFHKJIA";

    int len = strlen(inorder);

    TreeNode* root = buildTree(inorder, postorder, 0, len - 1, 0, len - 1);

    printf("�������ĽṹΪ: ");
    printTreeStructure(root);
    printf("\n");

    return 0;
}
