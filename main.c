#include "customer.h"
#include "menu.h"
#include "venue.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
    struct Venue venues[20];
    //初始化运动场地
     int venueNum=6;
     initVenue(&venues[0], "V001", "Region A", "Type 1", "Sport 1", "Reduction 1", 18, 50.0, true);
     initVenue(&venues[1], "V002", "Region B", "Type 1", "Sport 1", "Reduction 1", 19, 50.0, true);
     initVenue(&venues[2], "V003", "Region C", "Type 2", "Sport 2", "Reduction 2", 20, 50.0, true);
     initVenue(&venues[3], "V004", "Region D", "Type 2", "Sport 2", "Reduction 2", 21, 50.0, true);
     initVenue(&venues[4], "V005", "Region E", "Type 3", "Sport 3", "Reduction 3", 22, 50.0, true);
     initVenue(&venues[5], "V006", "Region F", "Type 3", "Sport 3", "Reduction 3", 23, 50.0, true);


     //显示菜单
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
        printf("顾客人数：%d\n",numCustomers);
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


            // 顾客开始操作
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
                    while(1)
                    {
                    showCustomerMenu();//显示顾客菜单
                    int choice_for_customer2;
                    scanf("%d", &choice_for_customer2);
                    switch (choice_for_customer2)
                    {
                    case 1:
                        
                        printf("展示体育场馆信息：\n");
                        printVenues(venues,venueNum);

                        break;
                    case 2:
                        char reserveVenueID[20];
                        printf("请输入预定场地编号：\n");
                        int flagVenue=0;
                        scanf("%s",reserveVenueID);
                        for(int i=0;i<venueNum;i++)
                        {
                            if(strcmp(venues[i].venueID,reserveVenueID)==0)
                            {
                                if(venues[i].isOk==false)
                                {
                                    printf("该场地已预定\n");
                                }
                                else{
                                venues[i].isOk=false;
                                printf("预定成功\n");
                                }
                                flagVenue=1;
                            }
                        }
                        if(flagVenue==0)
                        {
                            printf("该场地不存在\n");
                        }

                        

                        break;
                    }
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
        break;

    case 2:
        printf("您好管理员");
        break;

    case 3:
        return 0;

    default:
        break;
    }

    return 0;
}
