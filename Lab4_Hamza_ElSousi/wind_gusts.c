#include <stdio.h>
#include <time.h>
#include "wind_gusts.h"
#include <string.h>

void printWindGustsTable(struct WindGustsMessage *messages, int count) {
    int i;
    double prevWindSpeed = 0.0;  /* Initialize the previous wind speed */
    printf("Date Time Wind Change\n");

    for (i = 0; i < count; i++) {
        struct tm *timeinfo = localtime(&messages[i].timestamp);        
        char timeStr[20];
        char change[20]; /* Declare the 'change' variable at the beginning */
        strftime(timeStr, 20, "%Y/%m/%d %H:%M:%S", timeinfo);

        if (prevWindSpeed < messages[i].current) {
            strcpy(change, "Increasing");
        } else if (prevWindSpeed > messages[i].current) {
            strcpy(change, "Decreasing");
        } else {
            strcpy(change, "Unchanged");
        }

        printf("%s %s\n", timeStr, change);
        prevWindSpeed = messages[i].current;  /* Update the previous wind speed */
    }
}
