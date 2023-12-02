#include <stdio.h>
#include <stdlib.h>

// ��������㶨��
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// �������������������й���������
TreeNode* buildTree(char* inorder, char* preorder, int inStart, int inEnd, int preStart, int preEnd) {
    if (inStart > inEnd || preStart > preEnd) {
        return NULL;
    }

    // �������ǰ������ĵ�һ��Ԫ��
    char rootValue = preorder[preStart];
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = rootValue;
    root->left = root->right = NULL;

    // ����������������ҵ�������λ��
    int rootIndex;
    for (rootIndex = inStart; rootIndex <= inEnd; rootIndex++) {
        if (inorder[rootIndex] == rootValue) {
            break;
        }
    }

    // �ݹ鹹����������������
    root->left = buildTree(inorder, preorder, inStart, rootIndex - 1, preStart + 1, preStart + (rootIndex - inStart));
    root->right = buildTree(inorder, preorder, rootIndex + 1, inEnd, preStart + (rootIndex - inStart) + 1, preEnd);

    return root;
}

// �����������������ṹ
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

    printf("�������ṹ���: ");
    printTree(root);
    printf("\n");

    return 0;
}
