#ifndef WIND_GUSTS_H
#define WIND_GUSTS_H

#include <time.h>

struct WindGustsMessage {
    time_t timestamp;
    int type;
    double prev;
    double current;
    char change[20]; /* Added the 'change' field here*/
};

void printWindGustsTable(struct WindGustsMessage *messages, int count);

#endif
