#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

const int MAX_SIZE = 100; // 假设线性表的最大容量为100

class LinearList {
private:
    int data[MAX_SIZE]; // 用于存储线性表数据
    int length;         // 当前线性表的长度

public:
    // 构造函数
    LinearList();

    // 结构初始化
    void initialize();

    // 查找元素
    int search(int value);

    // 插入元素
    bool insert(int value, int position);

    // 删除元素
    bool remove(int value);

    // 求长度
    int getLength();
};

#endif
