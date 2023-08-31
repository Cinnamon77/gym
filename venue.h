#ifndef VENUE_H
#define VENUE_H
#include <stdbool.h>
struct venue
{
    char venueID[11];
    char venueRegion[20];
    char venueType[10];
    char sportType[10];
    char sportReduction[20];
    int minAge;
    double money;
    bool isOk[19];

};

void initVenue();

#endif // VENUE_H


