#include "admin.h"

void initAdmin(struct Admin *admin, const char *adminID, const char *venueName,
               const char *name, const char *gender, const char *email,
               const char *password, const char *phoneNumber,const char *venueID) {
    // 使用 strcpy 复制字符串到结构体的成员中
    strcpy(admin->adminID, adminID);
    strcpy(admin->venueName, venueName);
    strcpy(admin->name, name);
    strcpy(admin->gender, gender);
    strcpy(admin->email, email);
    strcpy(admin->password, password);
    strcpy(admin->phoneNumber, phoneNumber);
    strcpy(admin->venueID, venueID);
}

int adminLogin(struct Admin admins[],int adminNum) {
    char adminID[20];
    char password[20];

    printf("请输入管理员用户名：");
    scanf("%s", adminID);
    printf("请输入密码：");
    scanf("%s", password);

    // 遍历管理员数组，验证用户名和密码
    for (int i = 0; i < adminNum; i++) {
        if (strcmp(adminID, admins[i].adminID) == 0 && strcmp(password, admins[i].password) == 0) {
            printf("管理员 %s 登录成功！\n", adminID);
            return 1; // 登录成功，返回 1
        }
    }

    printf("管理员用户名或密码不正确。\n");
    return 0; // 登录失败，返回 0
}