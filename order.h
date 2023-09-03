#ifndef ORDER_H
#define ORDER_H
#include<stdio.h>
#include<string.h>

struct Order
{
    char orderID[20];
    char time[30];
    float money;
    char makerID[20];
    char venueID_od[20];


};

void initOrder(struct Order *order, const char *orderID, const char *time, float money, const char *makerID, const char *venueID_od);

void printOrder(const struct Order *order);

void clearOrder(struct Order *order);

#endif // ORDER_H
