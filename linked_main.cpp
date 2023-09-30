#include <iostream>
#include "linked_list.h"

using namespace std;

int main() {
    LinkedList myList;

    int data[] = {1, 2, 3, 4, 5};
    int length = sizeof(data) / sizeof(data[0]);

    myList.create(data, length);

    cout << "Linked List: ";
    myList.print();

    cout << "Searching for element 3..." << endl;
    ListNode* result = myList.search(3);
    if (result != nullptr) {
        cout << "Element 3 found." << endl;
    } else {
        cout << "Element 3 not found." << endl;
    }

    cout << "Inserting element 6 at position 2..." << endl;
    myList.insert(6, 2);
    myList.print();

    cout << "Removing element 4..." << endl;
    if (myList.remove(4)) {
        cout << "Element 4 removed successfully." << endl;
    } else {
        cout << "Element 4 not found and couldn't be removed." << endl;
    }

    cout << "Linked List after removal: ";
    myList.print();

    myList.clear();
    cout << "Linked List cleared." << endl;

    return 0;
}
