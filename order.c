#include "order.h"

void initOrder(struct Order *order, const char *orderID, const char *time, float money, const char *makerID, const char *venueID_od) {
     // 使用 strncpy 将数据复制到订单结构体中
    strncpy(order->orderID, orderID, sizeof(order->orderID));
    strncpy(order->time, time, sizeof(order->time));
    order->money = money;
    strncpy(order->makerID, makerID, sizeof(order->makerID));
    strncpy(order->venueID_od, venueID_od, sizeof(order->venueID_od));
}

// 打印订单信息的函数
void printOrder(const struct Order *order) {
    if (order == NULL) {
        printf("订单结构体指针为空，无法打印订单。\n");
        return;
    }

    printf("订单ID: %s\n", order->orderID);
    printf("订单时间: %s\n", order->time);
    printf("订单金额: %.2f\n", order->money);
    printf("创建者ID: %s\n", order->makerID);
    printf("场馆ID: %s\n", order->venueID_od);
}