#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_WINDOWS 6
#define MAX_QUEUE_SIZE 100

typedef enum {
    PUBLIC_FUND,
    PERSONAL_CARD,
    ENTERPRISE_CARD,
    INVALID_TYPE // 新增的无效类型
} BusinessType;

typedef struct {
    BusinessType type;
    int ticketNumber;
} Customer;

typedef struct {
    Customer queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue customerQueue;

bool isWindowOccupied[NUM_WINDOWS];

void initializeQueue() {
    customerQueue.front = -1;
    customerQueue.rear = -1;
}

bool isQueueEmpty() {
    return customerQueue.front == -1;
}

bool isQueueFull() {
    return (customerQueue.rear + 1) % MAX_QUEUE_SIZE == customerQueue.front;
}

void enqueue(Customer customer) {
    if (!isQueueFull()) {
        if (isQueueEmpty()) {
            customerQueue.front = 0;
        }
        customerQueue.rear = (customerQueue.rear + 1) % MAX_QUEUE_SIZE;
        customerQueue.queue[customerQueue.rear] = customer;
    } else {
        printf("Queue is full. Customer cannot be added.\n");
    }
}

Customer dequeue() {
    Customer customer;
    if (!isQueueEmpty()) {
        customer = customerQueue.queue[customerQueue.front];
        if (customerQueue.front == customerQueue.rear) {
            customerQueue.front = -1;
            customerQueue.rear = -1;
        } else {
            customerQueue.front = (customerQueue.front + 1) % MAX_QUEUE_SIZE;
        }
    } else {
        // Set customer.type to indicate an empty customer
        customer.type = INVALID_TYPE;
    }
    return customer;
}

void initializeWindows() {
    for (int i = 0; i < NUM_WINDOWS; i++) {
        isWindowOccupied[i] = false;
    }
}

void displayWindowStatus() {
    printf("Window Status:\n");
    for (int i = 0; i < NUM_WINDOWS; i++) {
        printf("Window %d: %s - Business Type: ", i + 1, isWindowOccupied[i] ? "Occupied" : "Free");
        if (isWindowOccupied[i]) {
            if (i == 0) {
                printf("Public Fund");
            } else if (i >= 1 && i <= 3) {
                printf("Personal Card");
            } else {
                printf("Enterprise Card");
            }
        } else {
            printf("N/A");
        }
        printf("\n");
    }
}

int main() {
    initializeQueue();
    initializeWindows();

    while (1) {
        char input;
        printf("Options:\n");
        printf("1. Customer Arrives\n");
        printf("2. Customer Departs\n");
        printf("3. Display Window Status\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &input);

        if (input == '1') {
            if (!isQueueFull()) {
                Customer customer;
                printf("Enter Business Type (P for Public Fund, C for Personal Card, E for Enterprise Card): ");
                scanf(" %c", &input);
                switch (input) {
                    case 'P':
                    case 'p':
                        customer.type = PUBLIC_FUND;
                        break;
                    case 'C':
                    case 'c':
                        customer.type = PERSONAL_CARD;
                        break;
                    case 'E':
                    case 'e':
                        customer.type = ENTERPRISE_CARD;
                        break;
                    default:
                        printf("Invalid Business Type.\n");
                        continue;
                }
                customer.ticketNumber = customerQueue.rear + 1;
                enqueue(customer);
            } else {
                printf("Queue is full. Customer cannot arrive.\n");
            }
        } else if (input == '2') {
            if (!isQueueEmpty()) {
                Customer customer = dequeue();
                bool served = false;
                for (int i = 0; i < NUM_WINDOWS; i++) {
                    if (!isWindowOccupied[i] && (i == 0 || (i >= 1 && i <= 3 && customer.type == PERSONAL_CARD) || (i >= 4 && customer.type == ENTERPRISE_CARD))) {
                        isWindowOccupied[i] = true;
                        served = true;
                        printf("Customer with Ticket Number %d is being served at Window %d.\n", customer.ticketNumber, i + 1);
                        break;
                    }
                }
                if (!served) {
                    printf("No available window for the customer. Customer must wait.\n");
                }
            } else {
                printf("Queue is empty. No customer to depart.\n");
            }
        } else if (input == '3') {
            displayWindowStatus();
        } else if (input == '4') {
            break;
        } else {
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}

