#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "temp.h"
#include "wind_speed.h"
#include "wind_gusts.h"
int main() {
    struct TempMessage temp_messages[1000];
    struct WindSpeedMessage wind_speed_messages[1000];
    struct WindGustsMessage wind_gusts_messages[1000];

    int temp_count = 0;
    int wind_speed_count = 0;
    int wind_gusts_count = 0;

    char line[100];
    char *token;
    int timestamp;
    int type;
    double value;

    while (fgets(line, sizeof(line), stdin) != NULL) {
        token = strtok(line, ",");
        if (token == NULL) {
            fprintf(stderr, "Invalid input line: %s", line);
            continue;
        }

        timestamp = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            fprintf(stderr, "Invalid input line: %s", line);
            continue;
        }

        type = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            fprintf(stderr, "Invalid input line: %s", line);
            continue;
        }

        value = atof(token);

        if (type == 1) {
            temp_messages[temp_count].timestamp = timestamp;
            temp_messages[temp_count].celsius = value;
            temp_count++;
        } else if (type == 2) {
            wind_speed_messages[wind_speed_count].timestamp = timestamp;
            wind_speed_messages[wind_speed_count].kmPerH = value;
            wind_speed_count++;
        } else if (type == 3) {
            wind_gusts_messages[wind_gusts_count].timestamp = timestamp;
            wind_gusts_messages[wind_gusts_count].current = value;
            wind_gusts_count++;
        }
    }

    /*printf("Date Time Celsius\n");*/
    printTempTable(temp_messages, temp_count);

    /*printf("Date Time Speed Direction\n");*/
    printWindSpeedTable(wind_speed_messages, wind_speed_count);

    /*printf("Date Time Wind Change\n");*/
    printWindGustsTable(wind_gusts_messages, wind_gusts_count);

    return 0;
}