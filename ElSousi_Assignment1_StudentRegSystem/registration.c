/*******************************************************************************************************************
* Name: Hamza El Sousi
* Student ID: 040-982-818
* Course: CST8234 C Language
* Lab section: 302
* Lab Professor: Natalie Gluzman
* Due date: Nov. 19, 2023
* Submission date: Nov. 11, 2023
* Professors: Surbhi Bahri, Harleen Kaur
* List of sources: "students.h", "courses.h", "registration.h", <stdio.h>, <string.h>, <stdbool.h>, <stdlib.h>
* Purpose: This program provides functions for student registration into courses, including registration, dropping, 
* and displaying registration details.
*******************************************************************************************************************/
#include "students.h"
#include "courses.h"
#include "registration.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> // Include the <stdlib.h> header for dynamic memory allocation

/******************************************************************************************************************
* Function Prototype: bool registerStudentToCourse(Registration *registrations, int *registrationCount)
* Purpose: Register a student into a course and add the registration to the registration table.
* Function In parameters: Registration *registrations - An array of registration structures.
*                        int *registrationCount - A pointer to the count of registrations.
* Function Out parameters: Returns true if the registration is successful; otherwise, returns false.
* Version: 1.0
* Author: Hamza El Sousi
***************************************************************************************************************/
bool registerStudentToCourse(Registration *registrations, int *registrationCount) {
    char *studentId = (char *)malloc(6); // Dynamic allocation for student ID
    char *courseId = (char *)malloc(8); // Dynamic allocation for course ID

    if (studentId == NULL || courseId == NULL) {
        perror("Error allocating memory for student or course ID");
        free(studentId);
        free(courseId);
        return false;
    }

    // Display student IDs
    printf("List of Student IDs:\n");
    for (int i = 0; i < *registrationCount; i++) {
        printf("Index %d: %s\n", i, registrations[i].studentId);
    }
    
    // Prompt the user to enter the student ID and course ID
    printf("Enter the Student's ID to register a course: ");
    if (fgets(studentId, 6, stdin) == NULL) {
        perror("Error reading student ID");
        free(studentId);
        free(courseId);
        return false;
    }
    strtok(studentId, "\n"); // Remove newline character

    if (strlen(studentId) != 5) {
        printf("Error: Student ID must be 5 digits.\n");
        free(studentId);
        free(courseId);
        return false;
    }

    
    // Display Course IDs
    printf("List of Course IDs:\n");
    for (int i = 0; i < *registrationCount; i++) {
        printf("Index %d: %s\n", i, registrations[i].courseId);
    }

    // Prompt for the course ID and validate it
    while (1) {
        printf("Enter the Course ID to register: ");
        if (fgets(courseId, 8, stdin) == NULL) {
            perror("Error reading course ID");
            free(studentId);
            free(courseId);
            return false;
        }
        strtok(courseId, "\n"); // Remove newline character

        if (isValidCourseID(courseId)) {
            break; // Course ID is valid, exit the loop
        } else {
            printf("Course ID must be 7 characters in the format [3-Alphas][4-digits].\n");
        }
    }
    ///                      TODO : Correct message for error handling.
    // Check if the student is already registered for the course
    for (int i = 0; i < *registrationCount; i++) {
        if (strcmp(registrations[i].studentId, studentId) == 0 && strcmp(registrations[i].courseId, courseId) == 0) {
            printf("Error: Student dropped course and cannot rejoin course.\n");
            free(studentId);
            free(courseId);
            return false;
        }
    }

    // Register the student for the course
    if (*registrationCount < MAX_REGISTRATIONS) {
        strcpy(registrations[*registrationCount].studentId, studentId);
        strcpy(registrations[*registrationCount].courseId, courseId);
        registrations[*registrationCount].status = 'R';
        (*registrationCount)++;
        printf("Registration Successful.\n");
    } else {
        printf("Maximum registrations reached. Cannot register more students.\n");
    }

    free(studentId);
    free(courseId);
    return true;
}

/******************************************************************************************************************
* Function Prototype: bool dropStudentFromCourse(Registration *registrations, int *registrationCount)
* Purpose: Drop a student from a course and update the registration status.
* Function In parameters: Registration *registrations - An array of registration structures.
*                        int *registrationCount - A pointer to the count of registrations.
* Function Out parameters: Returns true if the student is dropped from the course successfully; otherwise, returns false.
* Version: 1.0
* Author: Hamza El Sousi
***************************************************************************************************************/
bool dropStudentFromCourse(Registration *registrations, int *registrationCount) {
    printf("Registration Table:\n");
    for (int i = 0; i < *registrationCount; i++) {
        printf("Index %d - Student ID: %s | Course ID: %s | Status: %c\n", i, registrations[i].studentId, registrations[i].courseId, registrations[i].status);
    }

    printf("Please select Index number to drop student registration: ");
    int index;
    scanf("%d", &index);

    if (index < 0 || index >= *registrationCount) {
        printf("Invalid index selected. Drop course failed.\n");
        return false;
    }

    // Change the registration status to 'D'
    registrations[index].status = 'D';

    printf("Drop course successful.\n");
    return true;
}

/******************************************************************************************************************
* Function Prototype: void displayRegistrations(Registration *registrations, int registrationCount)
* Purpose: Display the registration table with registration details.
* Function In parameters: Registration *registrations - An array of registration structures.
*                        int registrationCount - The number of registrations in the array.
* Function Out parameters: None
* Version: 1.0
* Author: Hamza El Sousi
***************************************************************************************************************/
void displayRegistrations(Registration *registrations, int registrationCount) {
    printf("                    Registration Table:\n");
    printf("Registration Index | Student ID | Course ID | Registration Status\n");
    for (int i = 0; i < registrationCount; i++) {
    printf("         %d         |    %s   |  %s  |        %c     \n", i, registrations[i].studentId, registrations[i].courseId, registrations[i].status);
    }
}

/******************************************************************************************************************
* Function Prototype: void initializeRegistrations(Registration *registrations, int maxRegistrations)
* Purpose: Initialize the registration table with empty data.
* Function In parameters: Registration *registrations - An array of registration structures.
*                        int maxRegistrations - The maximum number of registrations.
* Function Out parameters: None
* Version: 1.0
* Author: Hamza El Sousi
***************************************************************************************************************/
void initializeRegistrations(Registration *registrations, int maxRegistrations) {
    for (int i = 0; i < maxRegistrations; i++) {
        // Initialize student IDs and course IDs to empty strings
        strcpy(registrations[i].studentId, "");
        strcpy(registrations[i].courseId, "");
        // Set the registration status to 'D' for dropped (or any initial state you prefer)
        registrations[i].status = 'D';
    }
}
