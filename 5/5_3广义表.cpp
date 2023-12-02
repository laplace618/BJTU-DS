#include <stdio.h>
#include <stdlib.h>

typedef struct GNode {
    int tag; // 标志域，0表示原子，1表示子表
    union {
        char data; // 原子结点的值
        struct GNode* head; // 指向表头指针
    } ptr;
    struct GNode* tail; // 指向表尾指针
} GNode;

// 创建原子结点
GNode* createAtom(char data) {
    GNode* node = (GNode*)malloc(sizeof(GNode));
    if (node) {
        node->tag = 0;
        node->ptr.data = data;
        node->tail = NULL;
    }
    return node;
}

// 创建子表结点
GNode* createSubList(GNode* head, GNode* tail) {
    GNode* node = (GNode*)malloc(sizeof(GNode));
    if (node) {
        node->tag = 1;
        node->ptr.head = head;
        node->tail = tail;
    }
    return node;
}

// 输出广义表
void printGList(GNode* list) {
    if (!list) {
        printf("()");
        return;
    }

    if (list->tag == 0) {
        printf("%c", list->ptr.data);
    } else {
        printf("(");
        printGList(list->ptr.head);
        GNode* temp = list->tail;
        while (temp) {
            printf(", ");
            printGList(temp->ptr.head);
            temp = temp->tail;
        }
        printf(")");
    }
}

// 获取广义表的表头
GNode* getHead(GNode* list) {
    if (!list || list->tag == 0) {
        return NULL;
    } else {
        return list->ptr.head;
    }
}

// 获取广义表的表尾
GNode* getTail(GNode* list) {
    if (!list || list->tag == 0) {
        return NULL;
    } else {
        return list->tail;
    }
}

// 计算广义表的深度
int getDepth(GNode* list) {
    if (!list) {
        return 0;
    } else if (list->tag == 0) {
        return 1;
    } else {
        int max_depth = 0;
        GNode* temp = list->ptr.head;
        while (temp) {
            int temp_depth = getDepth(temp);
            if (temp_depth > max_depth) {
                max_depth = temp_depth;
            }
            temp = temp->tail;
        }
        return max_depth + 1;
    }
}

// 释放广义表内存
void freeGList(GNode* list) {
    if (!list) {
        return;
    }
    if (list->tag == 1) {
        GNode* temp = list->ptr.head;
        while (temp) {
            GNode* to_free = temp;
            temp = temp->tail;
            freeGList(to_free);
        }
    }
    free(list);
}

// 读取用户输入的广义表
GNode* readGList() {
    char c;
    scanf("%c", &c);

    if (c == '(') {
        GNode* head = NULL;
        GNode* tail = NULL;

        while (1) {
            scanf("%c", &c);
            if (c == ')') {
                break;
            }
            if (c == '(') {
                GNode* sublist = readGList();
                if (!head) {
                    head = sublist;
                    tail = sublist;
                } else {
                    tail->tail = createSubList(sublist, NULL);
                    tail = tail->tail;
                }
            } else if (c != ' ' && c != ',') {
                if (!head) {
                    head = createAtom(c);
                    tail = head;
                } else {
                    tail->tail = createAtom(c);
                    tail = tail->tail;
                }
            }
        }
        return createSubList(head, NULL);
    } else {
        return NULL;
    }
}

int main() {
    printf("请输入广义表：");
    GNode* list = readGList();

    printf("广义表为：");
    printGList(list);
    printf("\n");

    GNode* head = getHead(list);
    GNode* tail = getTail(list);
    int depth = getDepth(list);

    printf("广义表的表头为：");
    printGList(head);
    printf("\n");

    printf("广义表的表尾为：");
    printGList(tail);
    printf("\n");

    printf("广义表的深度为：%d\n", depth);

    freeGList(list);

    return 0;
}
