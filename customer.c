#include "customer.h"
#include <stdio.h>
#include <string.h>

void my_fwrite(char *str,FILE *file) {
    fwrite(str,sizeof(char),strlen(str),file);
}

void saveCustomersToFile(struct Customer customers[], int numCustomers) {
    FILE *file = fopen("customer.dat", "a");
    if (file == NULL) {
        printf("无法打开文件\n");
        return;
    }
    char data[30];int now = 0;
    int len_userID = strlen(customers[numCustomers].userID);

    for (int i = 0; i < len_userID; ++i) {
        data[now] = customers[numCustomers].userID[i];
        now++;
    }
    data[now] = ' ';
    now++;
    int len_password = strlen(customers[numCustomers].password);

    for (int i = 0; i < len_password; ++i) {
        data[now] = customers[numCustomers].password[i];
        now++;
    }
    data[now] = '\n';now++;
    data[now] = '\0';

    my_fwrite(data,file);
    // my_fwrite(customers[numCustomers].userID,file);
    // fwrite(customers[numCustomers].userID, sizeof(char), strlen(customers[numCustomers].userID), file);
    fclose(file);
}

void readCustomersFromFile(struct Customer customers[], int *numCustomers) {
    FILE *file = fopen("customer.dat", "r");
    if (file == NULL) {
        printf("无法打开文件\n");
        return;
    }
    *numCustomers = fread(customers, sizeof(struct Customer), *numCustomers, file);
    fclose(file);
}

void registerCustomer(struct Customer customers[], int *numCustomers) {
    // 读取顾客信息并添加到数组中
    struct Customer newCustomer;
    printf("请输入以下信息进行注册：\n");
    printf("用户ID: ");
    scanf("%s", newCustomer.userID);
   
    printf("密码：");
    scanf("%s",newCustomer.password);
    // ... 依次输入其他信息
    (*numCustomers)++;
    customers[*numCustomers] = newCustomer;
    saveCustomersToFile(customers, *numCustomers);
    printf("注册成功！\n");
}

void loginCustomer(struct Customer customers[], int numCustomers,int *flag) {
    char userID[11];
    char password[20];
    printf("请输入用户ID: ");
    scanf("%s", userID);
    printf("请输入密码: ");
    scanf("%s", password);

    for (int i = 1; i <= numCustomers; i++) {
        if (strcmp(customers[i].userID, userID) == 0 && strcmp(customers[i].password, password) == 0) {
            *flag=1;
            printf("登陆成功！\n");
            

            return;
        }
    }

    printf("登陆失败，请检查用户ID和密码。\n");
    
}


