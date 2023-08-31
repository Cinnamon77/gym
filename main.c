#include "customer.h"
#include<stdio.h>

int main() {
    struct Customer customers[100]; // 假设最多有100个顾客
    int numCustomers = 0;

    readCustomersFromFile(customers, &numCustomers);

    while (1) {
        printf("1. 注册\n");
        printf("2. 登陆\n");
        printf("3. 退出\n");
        printf("请选择操作： ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerCustomer(customers, &numCustomers);
                break;
            case 2:
                loginCustomer(customers, numCustomers);
                break;
            case 3:
                saveCustomersToFile(customers, numCustomers);
                printf("已保存顾客数据。\n");
                return 0;
            default:
                printf("无效选项，请重新选择。\n");
        }
    }

    return 0;
}
