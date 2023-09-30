/*
2.4  某软件公司大约有300名员工，每名员工有姓名、工号、职务等属性，每年都有员工离职和入职。
    把所有员工建立一个线性表，建立离职和入职函数，当有员工离职或入职时，修改线性表，并且显示最新的员工名单。要求采用文件存储，需要实现文件的读写功能：
（2）链表存储；实现链表的插入、删除、查找、输出等基本操作；调用基本操作完成离职和入职函数。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// 员工结构体
typedef struct Employee {
    int employee_id;
    char name[MAX_NAME_LENGTH];
    char position[MAX_NAME_LENGTH];
    struct Employee* next;
} Employee;

// 链表结构体
typedef struct {
    Employee* head;
} EmployeeList;

// 初始化链表
void initialize(EmployeeList* list) {
    list->head = NULL;
}

// 插入员工
int insert(EmployeeList* list, Employee employee) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    if (newEmployee == NULL) {
        return 0; // 内存分配失败，插入失败
    }

    newEmployee->employee_id = employee.employee_id;
    strcpy(newEmployee->name, employee.name);
    strcpy(newEmployee->position, employee.position);
    newEmployee->next = list->head;

    list->head = newEmployee;
    return 1; // 插入成功
}

// 删除员工
int removeEmployee(EmployeeList* list, int employee_id) {
    Employee* current = list->head;
    Employee* prev = NULL;
    int found = 0;

    while (current != NULL) {
        if (current->employee_id == employee_id) {
            found = 1;
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }

    return found;
}

// 查找员工
Employee* findEmployee(EmployeeList* list, int employee_id) {
    Employee* current = list->head;

    while (current != NULL) {
        if (current->employee_id == employee_id) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// 输出员工列表到文件
void saveToFile(EmployeeList* list, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    Employee* current = list->head;
    while (current != NULL) {
        fprintf(file, "%d,%s,%s\n", current->employee_id, current->name, current->position);
        current = current->next;
    }

    fclose(file);
}

// 从文件加载员工列表
void loadFromFile(EmployeeList* list, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    initialize(list); // 清空当前列表

    while (!feof(file)) {
        Employee employee;
        int bytesRead = fscanf(file, "%d,%49[^,],%49[^,\n]\n", &employee.employee_id, employee.name, employee.position);
        if (bytesRead == 3) {
            insert(list, employee);
        }
    }

    fclose(file);
}

// 输出员工列表
void printEmployees(EmployeeList* list) {
    printf("Employee List:\n");
    Employee* current = list->head;
    while (current != NULL) {
        printf("Employee ID: %d, Name: %s, Position: %s\n",
               current->employee_id, current->name, current->position);
        current = current->next;
    }
}

// 清空链表
void clear(EmployeeList* list) {
    Employee* current = list->head;
    while (current != NULL) {
        Employee* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
}

int main() {
    EmployeeList employeeList;
    initialize(&employeeList);

    // 从文件加载员工列表（如果文件存在）
    loadFromFile(&employeeList, "test.txt");

    // 模拟员工入职
    Employee emp1 = {1, "Zhang San", "Manager", NULL};
    Employee emp2 = {2, "Li Si", "Engineer", NULL};
    Employee emp3 = {3, "Wang Wu", "Internship", NULL};
    insert(&employeeList, emp1);
    insert(&employeeList, emp2);
    insert(&employeeList, emp3);

    // 显示当前员工列表
    printEmployees(&employeeList);

    // 模拟员工离职
    int removed = removeEmployee(&employeeList, 1);
    if (removed) {
        printf("Employee with ID 1 has left the company.\n");
    } else {
        printf("Employee with ID 1 was not found.\n");
    }

    // 显示更新后的员工列表
    printEmployees(&employeeList);

    // 保存员工列表到文件
    saveToFile(&employeeList, "test.txt");

    // 清空链表
    clear(&employeeList);

    return 0;
}
