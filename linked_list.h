#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head; // 头结点指针

public:
    // 构造函数
    LinkedList();

    // 创建操作
    void create(int data[], int length);

    // 查找操作
    ListNode* search(int value);

    // 插入元素操作
    bool insert(int value, int position);

    // 撤销操作
    void clear();

    // 删除元素操作
    bool remove(int value);

    // 打印链表
    void print();
};

#endif
