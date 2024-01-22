/*******************************************************************
* Student Name: Hamza El Sousi
* Student Number: 040 982 818
* Course: 23F_CST8234 C Language
* Declaration: This is my own original work except where sources have been cited.
*******************************************************************/
#ifndef STUDENT_H
#define STUDENT_H

struct student {
    int studentID;
    double percentMark;
};
/* Function prototypes */
struct student *readStudentData(const char *filename, int *numStudents);
void printStudentData(const struct student *students, int numStudents);
int compareStudentID(const void *a, const void *b);
double calculateAverage(const struct student *students, int numStudents);
double calculateMedian(const struct student *students, int numStudents);
char* calculateLetterGrade(double percentMark);  /* Updated the return type*/

#endif  /* STUDENT_H */