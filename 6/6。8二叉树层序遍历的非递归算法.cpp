#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct QueueNode {
    TreeNode* data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, TreeNode* data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

TreeNode* dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return NULL; // Queue is empty
    }
    QueueNode* frontNode = queue->front;
    TreeNode* data = frontNode->data;
    queue->front = frontNode->next;
    free(frontNode);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return data;
}

void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    Queue* queue = createQueue();
    enqueue(queue, root);

    while (queue->front != NULL) {
        TreeNode* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(queue, current->right);
        }
    }
    free(queue);
}

int main() {
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = 111;

    root->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->data = 222;
    root->left->left = root->left->right = NULL;

    root->right = (TreeNode*)malloc(sizeof(TreeNode));
    root->right->data = 333;

    root->right->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->right->left->data = 444;
    root->right->left->left = root->right->left->right = NULL;

    root->right->right = (TreeNode*)malloc(sizeof(TreeNode));
    root->right->right->data = 555;
    root->right->right->left = root->right->right->right = NULL;

    printf("²ãĞò±éÀú: ");
    levelOrderTraversal(root);

    return 0;
}
