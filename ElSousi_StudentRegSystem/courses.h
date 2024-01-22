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
#ifndef COURSES_H
#define COURSES_H

#include <stdbool.h>

typedef struct {
    char id[8]; // 7 characters + null-terminator
} Course;

bool readCourse(Course *course); // Update the return type to 'bool'
bool isValidCourseID(const char *id);

#endif
