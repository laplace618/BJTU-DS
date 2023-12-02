/*
2.4  某软件公司大约有300名员工，每名员工有姓名、工号、职务等属性，每年都有员工离职和入职。
    把所有员工建立一个线性表，建立离职和入职函数，当有员工离职或入职时，修改线性表，并且显示最新的员工名单。要求采用文件存储，需要实现文件的读写功能：
（1）顺序表存储；实现顺序表的插入、删除、查找、输出等基本操作；调用基本操作完成离职和入职函数；
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 300
#define MAX_NAME_LENGTH 50

// 员工结构体
typedef struct {
    int employee_id;
    char name[MAX_NAME_LENGTH];
    char position[MAX_NAME_LENGTH];
} Employee;

// 顺序表结构体
typedef struct {
    Employee employees[MAX_EMPLOYEES];
    int size;
} EmployeeList;

// 初始化顺序表
void initialize(EmployeeList *list) {
    list->size = 0;
}

// 插入员工
int insert(EmployeeList *list, Employee employee) {
    if (list->size < MAX_EMPLOYEES) {
        list->employees[list->size] = employee;
        list->size++;
        return 1; // 插入成功
    }
    return 0; // 插入失败，表已满
}

// 删除员工
int removeEmployee(EmployeeList *list, int employee_id) {
    int found = 0;
    for (int i = 0; i < list->size; i++) {
        if (list->employees[i].employee_id == employee_id) {
            found = 1;
            for (int j = i; j < list->size - 1; j++) {
                list->employees[j] = list->employees[j + 1];
            }
            list->size--;
            break;
        }
    }
    return found;
}

// 查找员工
Employee* findEmployee(EmployeeList *list, int employee_id) {
    for (int i = 0; i < list->size; i++) {
        if (list->employees[i].employee_id == employee_id) {
            return &list->employees[i];
        }
    }
    return NULL;
}

// 输出员工列表到文件
void saveToFile(EmployeeList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < list->size; i++) {
        fprintf(file, "%d,%s,%s\n", list->employees[i].employee_id, list->employees[i].name, list->employees[i].position);
    }

    fclose(file);
}

// 从文件加载员工列表
void loadFromFile(EmployeeList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    initialize(list); // 清空当前列表

    while (!feof(file) && list->size < MAX_EMPLOYEES) {
        Employee employee;
        int bytesRead = fscanf(file, "%d,%49[^,],%49[^,\n]\n", &employee.employee_id, employee.name, employee.position);
        if (bytesRead == 3) {
            insert(list, employee);
        }
    }

    fclose(file);
}

// 输出员工列表
void printEmployees(EmployeeList *list) {
    printf("Employee List:\n");
    for (int i = 0; i < list->size; i++) {
        printf("Employee ID: %d, Name: %s, Position: %s\n",
               list->employees[i].employee_id, list->employees[i].name, list->employees[i].position);
    }
}

int main() {
    EmployeeList employeeList;
    initialize(&employeeList);

    // 从文件加载员工列表（如果文件存在）
    loadFromFile(&employeeList, "test1018.txt");

    // 模拟员工入职
    Employee emp1 = {1, "Zhang San", "Manager"};
    Employee emp2 = {2, "Li Si", "Engineer"};
    Employee emp3 = {3, "Wang Wu", "Internship"};
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
    saveToFile(&employeeList, "test1018.txt");

    return 0;
}
