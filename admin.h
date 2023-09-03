#ifndef ADMIN_H
#define ADMIN_H

#include<string.h>
#include<stdio.h>

struct Admin {
    char adminID[20];
    char venueName[50];
    char name[50];
    char gender[10];
    char email[50];
    char password[20];
    char phoneNumber[15];
    char venueID[20];
};

void initAdmin(struct Admin *admin, const char *adminID, const char *venueName,
               const char *name, const char *gender, const char *email,
               const char *password, const char *phoneNumber,const char *venueID);

int adminLogin(struct Admin admins[],int adminNum);



#endif //ADMIN_H