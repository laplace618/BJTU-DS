#include <stdio.h>
#include <stdlib.h>

// �������ڵ�ṹ
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// �����µĶ������ڵ�
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// �ݹ�ʵ�ֶ��������������
void preOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);  // �ȷ��ʸ��ڵ�
        preOrderTraversal(root->left);   // �ٱ���������
        preOrderTraversal(root->right);  // ������������
    }
}

// �ݹ�ʵ�ֶ��������������
void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);    // �ȱ���������
        printf("%c ", root->data);  // �ٷ��ʸ��ڵ�
        inOrderTraversal(root->right);   // ������������
    }
}

// �ݹ�ʵ�ֶ������ĺ������
void postOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);  // �ȱ���������
        postOrderTraversal(root->right); // �ٱ���������
        printf("%c ", root->data);  // �����ʸ��ڵ�
    }
}

int main() {
    // ����һ�ö�����
    TreeNode* root = createNode('F');
    root->left = createNode('B');
    root->right = createNode('G');
    root->left->left = createNode('A');
    root->left->right = createNode('D');
    root->left->right->left = createNode('C');
    root->left->right->right = createNode('E');
    // root->right->left = createNode('F');
    root->right->right = createNode('H');

    printf("�������: ");
    preOrderTraversal(root);
    printf("\n");

    printf("�������: ");
    inOrderTraversal(root);
    printf("\n");

    printf("�������: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
