#include <stdio.h>
#include <stdlib.h>

// 二叉树结点定义
typedef struct TreeNode {
    char data;  // 结点数据
    struct TreeNode* left;  // 左子树
    struct TreeNode* right; // 右子树
} TreeNode;

// 栈结点定义
typedef struct StackNode {
    TreeNode* node;  // 指向二叉树结点的指针
    struct StackNode* next;  // 下一个栈结点
} StackNode;

// 栈定义
typedef struct Stack {
    StackNode* top;  // 栈顶指针
} Stack;

// 初始化栈
void initStack(Stack* stack) {
    stack->top = NULL;
}

// 判断栈是否为空
int isStackEmpty(Stack* stack) {
    return stack->top == NULL;
}

// 入栈操作
void push(Stack* stack, TreeNode* node) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->node = node;
    newNode->next = stack->top;
    stack->top = newNode;
}

// 出栈操作
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

// 中序遍历非递归算法
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
    // 构建一个示例二叉树
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

    printf("中序遍历结果: ");
    inOrderTraversal(root);
    printf("\n");

    // 释放内存
    free(root->right);
    free(root->left);
    free(root);

    return 0;
}
