#include <stdio.h>
#include <stdlib.h>

// ��������㶨��
typedef struct TreeNode {
    char data;  // �������
    struct TreeNode* left;  // ������
    struct TreeNode* right; // ������
} TreeNode;

// ջ��㶨��
typedef struct StackNode {
    TreeNode* node;  // ָ�����������ָ��
    struct StackNode* next;  // ��һ��ջ���
} StackNode;

// ջ����
typedef struct Stack {
    StackNode* top;  // ջ��ָ��
} Stack;

// ��ʼ��ջ
void initStack(Stack* stack) {
    stack->top = NULL;
}

// �ж�ջ�Ƿ�Ϊ��
int isStackEmpty(Stack* stack) {
    return stack->top == NULL;
}

// ��ջ����
void push(Stack* stack, TreeNode* node) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->node = node;
    newNode->next = stack->top;
    stack->top = newNode;
}

// ��ջ����
TreeNode* pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        return NULL;
    }

    TreeNode* poppedNode = stack->top->node;
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return poppedNode;
}

// ��������ǵݹ��㷨
void inOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    Stack stack;
    initStack(&stack);
    TreeNode* currentNode = root;

    while (currentNode || !isStackEmpty(&stack)) {
        while (currentNode) {
            push(&stack, currentNode);
            currentNode = currentNode->left;
        }

        currentNode = pop(&stack);
        printf("%c ", currentNode->data);

        currentNode = currentNode->right;
    }
}

int main() {
    // ����һ��ʾ��������
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = 'A';
    root->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->data = 'B';
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (TreeNode*)malloc(sizeof(TreeNode));
    root->right->data = 'C';
    root->right->left = NULL;
    root->right->right = NULL;

    printf("����������: ");
    inOrderTraversal(root);
    printf("\n");

    // �ͷ��ڴ�
    free(root->right);
    free(root->left);
    free(root);

    return 0;
}
