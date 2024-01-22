#include <stdio.h>
#include "wind_speed.h"

void printWindSpeedTable(struct WindSpeedMessage *messages, int count) {
    int i;
    printf("Date Time Speed Direction\n");
    for (i = 0; i < count; i++) {
        struct tm *timeinfo = localtime(&messages[i].timestamp);
        char timeStr[20];
        strftime(timeStr, 20, "%Y/%m/%d %H:%M:%S", timeinfo);

        if (messages[i].degrees == 0) {
            printf("%s %.2f \n", timeStr, messages[i].kmPerH);
        } else {
            printf("%s %.2f %d\n", timeStr, messages[i].kmPerH, messages[i].degrees);
        }
    }
}
