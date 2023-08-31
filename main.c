#include "customer.h"
#include "menu.h"
#include <stdio.h>
#include <string.h>

void init(struct Customer customers[],int *numCustomers,FILE *file) {
    char userID[20],password[20];
    while (~fscanf(file,"%s %s",userID,password)) {
        ++(*numCustomers);
        strcpy(customers[*numCustomers].userID ,userID);
        strcpy(customers[*numCustomers].password ,password);
    }
}
int main()
{

    
    showMainMenu();
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1: // 顾客选择
        printf("您好顾客\n");
        printf("请先登陆：");
        struct Customer customers[100]; // 假设最多有100个顾客
        FILE *file = fopen("customer.dat", "r");
        int numCustomers = 0;
        init(customers,&numCustomers,file);
        fclose(file);

        int flag = 0; // 标记是否登陆成功
        while (1)
        {

            printf("1. 注册\n");
            printf("2. 登陆\n");
            printf("3. 退出\n");
            printf("请选择操作： ");
            int choice_for_customer;

            scanf("%d", &choice_for_customer);

            switch (choice_for_customer)
            {
            case 1:
                registerCustomer(customers, &numCustomers);
                // saveCustomersToFile(customers, numCustomers);
                printf("已保存顾客数据。\n");
                break;
            case 2:
                loginCustomer(customers, numCustomers, &flag);
                if (flag == 1)
                {
                    showCustomerMenu();
                    int choice_for_customer2;
                    scanf("%d", &choice_for_customer2);
                    switch (choice_for_customer2)

                    {
                    case 1:
                        break;
                    case 2:
                        break;
                    }
                }

                break;
            case 3:

                break;
            default:
                printf("无效选项，请重新选择。\n");
            }

            if (choice_for_customer == 3)
            {
                break;
            }
        }

    case 2:
        printf("您好管理员");

    case 3:
        return 0;

    default:
        break;
    }

    return 0;
}
