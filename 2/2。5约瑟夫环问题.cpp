/*local master
2.5  约瑟夫（Josephus）环问题：
    编号为1, 2, 3, …, n的n个人按顺时针方向围坐一圈，每人持有一个密码（正整数）。
    一开始任选一个正整数作为报数的上限值m，从第一个人开始按顺时针方向自1开始顺序报数,报到m时停止。
    报m的人出列，将他的密码作为新的m值，从他在顺时针方向上的下一人开始重新从1报数，如此下去，直到所有人全部出列为止。
    建立n个人的单循环链表存储结构，运行结束后，输出依次出队的人的序号。
*/

#include <iostream>
using namespace std;

// 定义一个结点结构
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}  // 构造函数
};

// 创建约瑟夫环链表
Node* createJosephusCircle(int n) {
    if (n <= 0) return nullptr;
    
    Node* head = new Node(1);  // 创建头结点
    Node* current = head;  // 当前结点
    
    for (int i = 2; i <= n; i++) {  // 依次创建 n-1 个结点(头结点已创建)
        current->next = new Node(i);  // 创建新结点
        current = current->next;  // 移动当前结点
    }
    
    current->next = head; // 将链表首尾相连，形成循环链表
    
    return head;
}

// 解决约瑟夫环问题
void solveJosephusProblem(Node* head, int m) {
    if (!head || m <= 0) return;  // 非法输入
    Node* current = head;  // 当前结点
    Node* prev = nullptr;  // 当前结点的前一个结点
    
    while (current->next != current) {  // 当链表中还有两个以上的结点时
        for (int i = 1; i < m; i++) {
            prev = current;  // 移动前一个结点
            current = current->next;  // 移动当前结点
        }
        
        // 当前结点出列
        Node* temp = current;
        prev->next = current->next;
        current = prev->next;
        cout << temp->data << " ";
        delete temp;
    }
    
    // 输出最后一个结点的序号
    cout << current->data << endl;
    
    // 释放头结点内存
    delete current;
}

int main() {
    int n, m;
    cout << "Please enter the total number of people n:";
    cin >> n;
    cout << "Please enter the maximum number of reports m:";
    cin >> m;
    
    Node* circle = createJosephusCircle(n);
    cout << "The team sequence number is:";
    solveJosephusProblem(circle, m);
    
    return 0;
}
