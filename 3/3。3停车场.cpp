#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_CAPACITY 100
#define HOURLY_RATE 10  // 停车一小时的车费

// 车辆结构体
struct Car 
{
    char licensePlate[20];
    time_t enterTime;
};

// 停车场
struct Car parkingLot[MAX_CAPACITY];
int numCars = 0;

// 停车
void enterCar(const char* licensePlate, time_t enterTime) /*使用const防止车牌号和时间被意外修改*/
{
    if (numCars < MAX_CAPACITY)  // 停车场未满
    {
        struct Car car;
        strcpy(car.licensePlate, licensePlate);  // 保存输入的车牌号
        car.enterTime = enterTime;  // 保存输入的入场时间
        parkingLot[numCars] = car;  // 将车辆信息保存到停车场
        numCars++;  // 停车场车辆数加1
        printf("Car with license plate %s entered the parking lot.\n", licensePlate);
    } 
    else
    {
        printf("Parking lot is full. Cannot enter the car with license plate %s.\n", licensePlate);
    }
}

// 取车
void exitCar(const char* licensePlate, time_t exitTime) /*使用const防止车牌号和时间被意外修改*/
{
    int i;  // 循环变量
    for (i = 0; i < numCars; i++)  // 遍历停车场
    {
        if (strcmp(parkingLot[i].licensePlate, licensePlate) == 0)  // 找到车牌号相同的车辆
        {
            double parkingDuration = difftime(exitTime, parkingLot[i].enterTime);  // 计算停车时长（单位为秒）
            double parkingFee = (parkingDuration / 3600) * HOURLY_RATE;  // 计算停车费用
            printf("Car with license plate %s exited the parking lot. Parking duration: %.2f hours. Parking fee: %.2f RMB\n",
                licensePlate, parkingDuration / 3600, parkingFee);
            // 从停车场移除车辆
            for (int j = i; j < numCars - 1; j++)  // 将后面的车辆向前移动
            {
                parkingLot[j] = parkingLot[j + 1];
            }
            numCars--;
            return;
        }
    }
    printf("Car with license plate %s not found in the parking lot.\n", licensePlate);  // 未找到车牌号相同的车辆
}

// 显示停车场
void displayParkingLot() 
{
    printf("Cars in the parking lot:\n");
    for (int i = 0; i < numCars; i++) 
    {
        printf("License Plate: %s, Enter Time: %s", parkingLot[i].licensePlate, ctime(&parkingLot[i].enterTime));
    }
}

int main() {
    char option;
    char licensePlate[20];  // 在外部声明 licensePlate

    while (1) {
        printf("\nOptions:\n");
        printf("1. Enter car\n");
        printf("2. Exit car\n");
        printf("3. Display parking lot\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                time_t enterTime;
                printf("Enter license plate: ");
                scanf("%s", licensePlate);
                enterTime = time(NULL);
                enterCar(licensePlate, enterTime);
                break;
            case '2':
                time_t exitTime;
                printf("Enter license plate: ");
                scanf("%s", licensePlate);
                exitTime = time(NULL);
                exitCar(licensePlate, exitTime);
                break;
            case '3':
                displayParkingLot();
                break;
            case '4':
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
}


