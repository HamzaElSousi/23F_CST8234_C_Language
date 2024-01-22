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
#ifndef STUDENTS_H
#define STUDENTS_H

#include <stdbool.h> 

typedef struct {
    char id[6]; // 5 digits + null-terminator
} Student;

bool readStudent(Student *student); // Update the return type to 'bool'
bool isValidStudentID(const char *id);
void listStudentIDs(Student *students, int studentCount);
#endif
