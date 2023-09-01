#include"menu.h"
#include <stdio.h>

void showMainMenu() {
    printf("欢迎使用综合体育场馆管理系统\n");
    printf("1. 顾客登陆\n");
    printf("2. 管理员登陆\n");
    printf("3. 退出\n");
    printf("请输入选项：");
}

void showCustomerMenu() {
    printf("\n顾客功能菜单\n");
    printf("1. 查询场地\n");
    printf("2. 预定场地\n");
    printf("3. 个人信息管理\n");
    printf("4. 取消预定\n");
    printf("5. 查询订单\n");
    printf("0. 返回上级菜单\n");
    printf("请输入选项：");
}

void showAdminMenu() {
    printf("\n管理员功能菜单\n");
    printf("1. 查看用户预定情况\n");
    printf("2. 统计用户预定信息\n");
    printf("3. 场地管理\n");
    printf("4. 个人信息管理\n");
    printf("0. 返回上级菜单\n");
    printf("请输入选项：");
}



void showVenueMenu() {
    printf("\n体育馆查询菜单:\n");
    printf("1. 根据场地名称查询\n");
    printf("2. 根据场馆名称查询\n");
    printf("3. 根据场地类别和所属区域查询\n");
    printf("4. 根据是否有空余场地过滤查询结果\n");
    printf("5. 根据租金排序所有场地\n");
    printf("6. 根据预定量排序所有场地\n");
    printf("0. 退出\n");
}