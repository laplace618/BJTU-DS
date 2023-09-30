#include "linear_list.h"

LinearList::LinearList() {
    length = 0;
}

void LinearList::initialize() {
    length = 0;
}

int LinearList::search(int value) {
    for (int i = 0; i < length; i++) {
        if (data[i] == value) {
            return i; // 返回元素在线性表中的位置（索引）
        }
    }
    return -1; // 表示未找到元素
}

bool LinearList::insert(int value, int position) {
    if (length >= MAX_SIZE || position < 0 || position > length) {
        return false; // 插入失败
    }

    // 后续元素向后移动一个位置
    for (int i = length; i > position; i--) {
        data[i] = data[i - 1];
    }

    // 插入新元素
    data[position] = value;
    length++;
    return true; // 插入成功
}

bool LinearList::remove(int value) {
    int position = search(value);
    if (position == -1) {
        return false; // 未找到要删除的元素
    }

    // 删除元素，并将后续元素向前移动一个位置
    for (int i = position; i < length - 1; i++) {
        data[i] = data[i + 1];
    }

    length--;
    return true; // 删除成功
}

int LinearList::getLength() {
    return length;
}
