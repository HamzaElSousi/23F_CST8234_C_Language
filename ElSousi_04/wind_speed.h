#ifndef WIND_SPEED_H
#define WIND_SPEED_H

#include <time.h>

struct WindSpeedMessage {
    time_t timestamp;
    int type;      /* Add the type member*/
    double kmPerH; /*Add the kmPerH member*/
    int degrees;
};

/* Function prototypes*/
void printWindSpeedTable(struct WindSpeedMessage* messages, int count);

#endif
