/*******************************************************************************************************************
* Name: Hamza El Sousi
* Student ID: 040-982-818
* Course: CST8234 C Language
* Lab section: 302
* Lab Professor: Natalie Gluzman
* Due date: Nov. 19, 2023
* Submission date: Nov. 11, 2023
* Professor: Surbhi Bahri, Harleen Kaur
* List of sources: <stdio.h>, <stdbool.h>, <ctype.h>, <string.h>
* Purpose : 
*******************************************************************************************************************/

#include "courses.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h> // Include the <stdbool.h> header

/******************************************************************************************************************
Functions Prototype :
Purpose: 

Function in: 

Function out: 

Version: 1.0
Author: Hamza El Sousi
EXAMPLE:
***************************************************************************************************************/
bool readCourse(Course *course) {
    char input[10]; // Buffer to read user input

    while (1) {
        printf("Enter the course ID [3-Alphas][4-digits]: ");
        if (!fgets(input, sizeof(input), stdin)) {
            perror("Error reading input");
            return false;
        }
        strtok(input, "\n"); // Remove newline character

        // Check for input length
        if (strlen(input) != 7) {
            printf("Error: Course ID must be 7 characters.\n");
            printf("\nEnter the course ID [3-Alphas][4-digits]: ");
            continue;
        }

        // Check for non-digit characters in the last 4 characters
        int i;
        for (i = 3; i < 7; i++) {
            if (!isdigit(input[i])) {
                printf("Error: Last 4 characters of Course ID must be digits.\n");
                break;
            }
        }

        // Check for non-alpha characters in the first 3 characters
        for (i = 0; i < 3; i++) {
            if (!isalpha(input[i])) {
                printf("Error: First 3 characters of Course ID must be alphabets.\n");
                break;
            }
        }

        // If all checks pass, the input is valid
        if (i == 3 && input[7] == '\0') {
            strcpy(course->id, input);
            return true;
        } else {
            printf("Error: Course ID must be 7 characters.\n");
        }
    }
}
/******************************************************************************************
*Function name:              isValidCourseID
*Purpose:                    Reads input and validates it is correct format for a course ID
*Function In parameters:     None
*Function Out parameters:    The validated student number
*Version:                    1
*Author:                     Hamza El Sousi
******************************************************************************************/
bool isValidCourseID(const char *id) {
    if (strlen(id) != 7) {
        return false;
    }
    for (int i = 0; i < 3; i++) {
        if (!isalpha(id[i])) {
            return false;
        }
    }
    for (int i = 3; i < 7; i++) {
        if (!isdigit(id[i])) {
            return false;
        }
    }
    return true;
}
