#ifndef VENUE_H
#define VENUE_H
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


struct Venue
{
    char venueID[11];
    char venueRegion[20];
    char venueType[10];
    char sportType[10];
    char sportReduction[20];
    int minAge;
    double money;
    bool isOk;

};


void printVenues(struct Venue venues[], int venueNum);
void initVenue(struct Venue *venue, const char *id, const char *region, const char *type,
               const char *sport, const char *reduction, int age, double money, bool isOk);

#endif // VENUE_H


