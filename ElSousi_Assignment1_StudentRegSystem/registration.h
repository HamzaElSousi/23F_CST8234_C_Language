/*******************************************************************************************************************
* Name: Hamza El Sousi
* Student ID: 040-982-818
* Course: CST8234 C Language
* Lab section: 302
* Lab Professor: Natalie Gluzman
* Due date: Nov. 19, 2023
* Submission date: Nov. 11, 2023
* Professor: Surbhi Bahri, Harleen Kaur
* List of sources: <stdbool.h>
* Purpose : 
*******************************************************************************************************************/
#ifndef REGISTRATION_H
#define REGISTRATION_H
#define MAX_REGISTRATIONS 100 // Adjust as needed
#include <stdbool.h> // Include the <stdbool.h> header for the 'bool' type

typedef struct {
    char studentId[6]; // 5 digits + null-terminator
    char courseId[8]; // 7 characters + null-terminator
    char status; // 'R' for Registered, 'D' for Dropped
} Registration;

bool registerStudentToCourse(Registration *registrations, int *registrationCount);
bool dropStudentFromCourse(Registration *registrations, int *registrationCount);
void displayRegistrationTable(Registration *registrations, int registrationCount);
void initializeRegistrations(Registration *registrations, int maxRegistrations);


#endif
