#ifndef TEMP_H
#define TEMP_H


#include <time.h>

struct TempMessage {
    time_t timestamp;
    int type;
    double celsius;
};

void printTempTable(struct TempMessage *messages, int count);

#endif
