/*******************************************************************************************************************
* Name: Hamza El Sousi
* Student ID: 040-982-818
* Course: CST8234 C Language
* Lab section: 302
* Lab Professor: Natalie Gluzman
* Due date: Nov. 19, 2023
* Submission date: Nov. 11, 2023
* Professors: Surbhi Bahri, Harleen Kaur
* List of sources: <stdio.h>, <string.h>, <ctype.h>, "students.h"
* Purpose: This program provides functions to read and validate student IDs, as well as list student IDs.
*******************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "students.h"

/******************************************************************************************************************
* Function Prototype: bool readStudentId(char *studentId)
* Purpose: Reads and validates a student ID with 5 digits.
* Function In parameters: char *studentId - A character array to store the validated student ID.
* Function Out parameters: Returns true if a valid student ID is read; otherwise, returns false.
* Version: 1.0
* Author: Hamza El Sousi
***************************************************************************************************************/
bool readStudentId(char *studentId) {
    char input[10]; // Buffer to read user input

    do {
        if (!fgets(input, sizeof(input), stdin)) {
            perror("Error reading input");
            return false;
        }
        strtok(input, "\n"); // Remove newline character

        // Check for input length
        if (strlen(input) != 5) {
            printf("Error: Student ID must be 5 digits.\n");
            continue;
        }

        // Check for non-digit characters
        int i;
        for (i = 0; i < 5; i++) {
            if (!isdigit(input[i])) {
                printf("Error: Student ID must contain only digits.\n");
                break;
            }
        }

        // If a non-digit character is found, restart the loop
        if (i < 5) {
            continue;
        }

        // If all checks pass, the input is valid
        strcpy(studentId, input);
        return true;
    } while (1); // Continue until valid input is provided
}

/******************************************************************************************************************
* Function Prototype: bool isValidStudentID(const char *id)
* Purpose: Validates a student ID format (5 digits).
* Function In parameters: const char *id - The student ID to validate.
* Function Out parameters: Returns true if the ID is in a valid format; otherwise, returns false.
* Version: 1.0
* Author: Hamza El Sousi
***************************************************************************************************************/
bool isValidStudentID(const char *id) {
    if (strlen(id) != 5) {
        return false;
    }
    for (int i = 0; i < 5; i++) {
        if (!isdigit(id[i])) {
            return false;
        }
    }
    return true;
}

/******************************************************************************************************************
* Function Prototype: void listStudentIDs(Student *students, int studentCount)
* Purpose: Lists all student IDs with their respective indexes.
* Function In parameters: Student *students - An array of student structures.
*                        int studentCount - The number of students in the array.
* Function Out parameters: None
* Version: 1.0
* Author: Hamza El Sousi
***************************************************************************************************************/
void listStudentIDs(Student *students, int studentCount) {
    printf("List of Student IDs:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Index %d: %s\n", i, students[i].id);
    }
}
