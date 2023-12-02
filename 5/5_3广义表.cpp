#include <stdio.h>
#include <stdlib.h>

typedef struct GNode {
    int tag; // ��־��0��ʾԭ�ӣ�1��ʾ�ӱ�
    union {
        char data; // ԭ�ӽ���ֵ
        struct GNode* head; // ָ���ͷָ��
    } ptr;
    struct GNode* tail; // ָ���βָ��
} GNode;

// ����ԭ�ӽ��
GNode* createAtom(char data) {
    GNode* node = (GNode*)malloc(sizeof(GNode));
    if (node) {
        node->tag = 0;
        node->ptr.data = data;
        node->tail = NULL;
    }
    return node;
}

// �����ӱ���
GNode* createSubList(GNode* head, GNode* tail) {
    GNode* node = (GNode*)malloc(sizeof(GNode));
    if (node) {
        node->tag = 1;
        node->ptr.head = head;
        node->tail = tail;
    }
    return node;
}

// ��������
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

// ��ȡ�����ı�ͷ
GNode* getHead(GNode* list) {
    if (!list || list->tag == 0) {
        return NULL;
    } else {
        return list->ptr.head;
    }
}

// ��ȡ�����ı�β
GNode* getTail(GNode* list) {
    if (!list || list->tag == 0) {
        return NULL;
    } else {
        return list->tail;
    }
}

// ������������
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

// �ͷŹ�����ڴ�
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

// ��ȡ�û�����Ĺ����
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
    printf("����������");
    GNode* list = readGList();

    printf("�����Ϊ��");
    printGList(list);
    printf("\n");

    GNode* head = getHead(list);
    GNode* tail = getTail(list);
    int depth = getDepth(list);

    printf("�����ı�ͷΪ��");
    printGList(head);
    printf("\n");

    printf("�����ı�βΪ��");
    printGList(tail);
    printf("\n");

    printf("���������Ϊ��%d\n", depth);

    freeGList(list);

    return 0;
}
