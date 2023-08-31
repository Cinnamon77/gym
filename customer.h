#ifndef CUSTOMER_H
#define CUSTOMER_H

struct Customer {
    char userID[11];
    char name[50];
    char gender;
    int age;
    char phoneNumber[12];
    char password[20];
    char email[50];
    double accountBalance;
    char geographicRegion[50];
};

void saveCustomersToFile(struct Customer customers[], int numCustomers);
void readCustomersFromFile(struct Customer customers[], int *numCustomers);
void registerCustomer(struct Customer customers[], int *numCustomers);
void loginCustomer(struct Customer customers[], int numCustomers);

#endif // CUSTOMER_H
