#include "customer.h"
#include"menu.h"
#include<stdio.h>

int main() {
    showMainMenu();
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1://顾客选择
        printf("您好顾客");
        printf("请先登陆：");
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
                break;
            default:
                printf("无效选项，请重新选择。\n");
        }
    }
        showCustomerMenu();
        int choice_for_customer;
        switch(choice_for_customer)
        {
        }
        break;

    case 2:
        printf("您好管理员");



    case 3:
        return 0 ;
    
    default:
        break;
    }


    

    return 0;
}
