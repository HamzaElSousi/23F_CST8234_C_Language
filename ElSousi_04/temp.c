#include <stdio.h>
#include <time.h>
#include "temp.h"

void printTempTable(struct TempMessage messages[], int count) {
    int i;
    printf("Date Time Celsius\n");
    for (i = 0; i < count; i++) {
        char timeStr[20];
        struct tm *timeinfo = localtime(&(messages[i].timestamp));
        strftime(timeStr, 20, "%Y/%m/%d %H:%M:%S", timeinfo);
        printf("%s %.2f\n", timeStr, messages[i].celsius);
    }
}
