#include "venue.h"


void printVenues(struct Venue venues[], int venueNum) {
    for (int i = 0; i < venueNum; i++) {
        printf("Venue %d:\n", i + 1);
        printf("Venue ID: %s\n", venues[i].venueID);
        printf("Venue Region: %s\n", venues[i].venueRegion);
        printf("Venue Type: %s\n", venues[i].venueType);
        printf("Sport Type: %s\n", venues[i].sportType);
        printf("Sport Reduction: %s\n", venues[i].sportReduction);
        printf("Minimum Age: %d\n", venues[i].minAge);
        printf("Money: %.2lf\n", venues[i].money);
        printf("Is Available Slots: %s\n",venues[i].isOk?"true":"false");
        printf("\n\n");
    }
}


void initVenue(struct Venue *venue, const char *id, const char *region, const char *type,
               const char *sport, const char *reduction, int age, double money, bool isOk) {
    strcpy(venue->venueID, id);
    strcpy(venue->venueRegion, region);
    strcpy(venue->venueType, type);
    strcpy(venue->sportType, sport);
    strcpy(venue->sportReduction, reduction);
    venue->minAge = age;
    venue->money = money;
    venue->isOk=true;
}