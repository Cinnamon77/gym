#include "customer.h"
#include "menu.h"
#include "venue.h"
#include "order.h"
#include "admin.h"
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
    int orderNum=0;
    struct Order orders[100];
    //初始化订单

    int adminNum=6;
    struct Admin admins[20];
    initAdmin(&admins[0],"Admin001", "Type 1","name1", "f", "100@qq.com","123456","19955217075","V001");
    initAdmin(&admins[1],"Admin002", "Type 1","name2", "m", "101@qq.com","123456","19955217075","V002");
    initAdmin(&admins[2],"Admin003", "Type 2","name3", "f", "102@qq.com","123456","19955217075","V003");
    initAdmin(&admins[3],"Admin004", "Type 2","name4", "m", "103@qq.com","123456","19955217075","V004");
    initAdmin(&admins[4],"Admin005", "Type 3","name5", "f", "104@qq.com","123456","19955217075","V005");
    initAdmin(&admins[5],"Admin006", "Type 3","name6", "m", "105@qq.com","123456","19955217075","V006");





   
    //初始化管理员 venueName对应体育馆venueType 一个管理员管理一个场地





    struct Venue venues[20];
     int venueNum=6;
    //初始化运动场地
    
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
                char currUserID[20]; //用户标记在这
                loginCustomer(customers, numCustomers, &flag,currUserID);
                
                if (flag == 1)  //可以用int型返回值优化 
                {
                    // printf("请再次输入您的用户名\n");
                    // scanf("%s",currUserID);
                    //对该用户进行操作
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
                                    //创建订单
                                    sprintf(orders[orderNum].orderID, "%04d", orderNum);
                                    initOrder(&orders[orderNum],orders[orderNum].orderID, "2023.6.5",50.0, currUserID, reserveVenueID);//时间和价格未加入
                                    printOrder(&orders[orderNum]);
                                    orderNum++;
                                }
                                flagVenue=1;
                            }
                        }
                        if(flagVenue==0)
                        {
                            printf("该场地不存在\n");
                        }
  

                        break;
                    case 3:
                        printf("个人信息中心\n");
                        
                        
                        for(int i=0;i<numCustomers;i++)
                        {
                            if(strcmp(customers[i].userID,currUserID)==0)
                            {
                                printf("您的个人信息为：\n");
                                printf("用户名：%s",customers[i].userID);
                                printf("密码：%s",customers[i].password);
                                printf("是否修改? 1.修改 2.不修改\n");
                                int choice_for_personalInformation;
                                scanf("%d",&choice_for_personalInformation);
                                if(choice_for_personalInformation==1)
                                {
                                    
                                    int choice_for_fix;
                                    while(1)
                                    {
                                    printf("请输入您想修改的内容\n");
                                    printf("1.用户名 \n2.密码 \n");
                                    scanf("%d",&choice_for_fix);
                                    switch (choice_for_fix)
                                    {
                                    case 1:
                                        printf("请输入新用户名\n");
                                        char new_userID[20];
                                        scanf("%s",new_userID);
                                        strcpy(customers[i].userID,new_userID);
                                        strcpy(currUserID,new_userID);
                                        
                                    
                                        break;
                                    
                                    case 2:
                                        printf("请输入新密码\n");
                                        char new_password[20];
                                        scanf("%s",new_password);
                                        strcpy(customers[i].password,new_password);
                                       

                                        break;
                                    
                                    default:
                                        break;
                                    }
                                    if(choice_for_fix==3)
                                    {
                                        break;
                                    }
                                    
                                    }
                                }
                                


                            }
                            

                        }
                        break;


                    case 4:
                        printf("取消预定\n");
                        printf("请输入您想取消的订单编号：");
                        char currOrderID[20];
                        scanf("%s",currOrderID);
                        for(int i=0;i<orderNum;i++)
                        {
                            if(strcmp(orders[i].orderID,currOrderID)==0)//是这个顾客的订单
                            {
                                for(int j=0;j<venueNum;j++)
                                {
                                    if(strcmp(venues[j].venueID,orders[i].venueID_od)==0)//是对应的体育场馆
                                    {
                                        venues[j].isOk==true;//把对应场馆清空  有问题先写管理员去了
                                        clearOrder(&orders[i]);

                                        printf("取消成功\n");
                                    }
                                }
                            }
                        }
                        break;
                    case 5:
                        printf("您的现有订单为：\n");
                        int flag_order=0;//标记是否有订单
                         for(int i=0;i<orderNum;i++)
                        {
                            if(strcmp(orders[i].makerID,currUserID)==0)
                            {
                                
                                flag_order++;

                            }

                        }

                         if(flag_order==0)
                        {
                            printf("您没有创建订单\n\n");
                        }
                        else
                        {
                             for(int i=0;i<orderNum;i++)
                                {
                                 if(strcmp(orders[i].makerID,currUserID)==0)
                                    {
                                        printOrder(&orders[i]);
                                        

                                    }
                                    printf("\n");

                        }
                        }


                        break;
                    case 6:
                        break;
                    default:
                         break;

                    }
                    }
                }

                break;//这个顾客功能结尾
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
        printf("请先登陆");


        break;

    case 3:
        return 0;

    default:
        break;
    }

    return 0;
}
