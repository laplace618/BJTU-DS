#include "linked_list.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
    head = new ListNode(0); // 创建头结点
}

void LinkedList::create(int data[], int length) {
    clear(); // 清空已有的链表

    ListNode* current = head;

    for (int i = 0; i < length; i++) {
        current->next = new ListNode(data[i]);
        current = current->next;
    }
}

ListNode* LinkedList::search(int value) {
    ListNode* current = head->next; // 从第一个节点开始搜索

    while (current != nullptr) {
        if (current->data == value) {
            return current; // 找到元素
        }
        current = current->next;
    }

    return nullptr; // 未找到元素
}

bool LinkedList::insert(int value, int position) {
    if (position < 0) {
        return false; // 插入失败
    }

    ListNode* current = head;
    int index = 0;

    while (current != nullptr && index < position) {
        current = current->next;
        index++;
    }

    if (current == nullptr) {
        return false; // 插入失败
    }

    ListNode* newNode = new ListNode(value);
    newNode->next = current->next;
    current->next = newNode;

    return true; // 插入成功
}

void LinkedList::clear() {
    ListNode* current = head->next;

    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    head->next = nullptr;
}

bool LinkedList::remove(int value) {
    ListNode* current = head;
    
    while (current->next != nullptr) {
        if (current->next->data == value) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true; // 删除成功
        }
        current = current->next;
    }

    return false; // 未找到要删除的元素
}

void LinkedList::print() {
    ListNode* current = head->next;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}
