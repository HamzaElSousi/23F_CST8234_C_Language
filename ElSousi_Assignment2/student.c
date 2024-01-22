/*******************************************************************
* Student Name: Hamza El Sousi
* Student Number: 040 982 818
* Course: 23F_CST8234 C Language
* Declaration: This is my own original work except where sources have been cited.
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "student.h"
/******************************************************************************************************************
* Function Prototype: struct student *readStudentData(const char *filename, int *numStudents)
* Purpose: Read student data from a binary file.
* Function In parameters: filename - Name of the file to read, numStudents - Pointer to store the number of students.
* Function Out parameters: Returns a pointer to an array of students.
* Version: 1.0
* Author: Hamza El Sousi
***************************************************************************************************************/
struct student *readStudentData(const char *filename, int *numStudents) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    /* find the number of students in the file */
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    *numStudents = fileSize / sizeof(struct student);
    fseek(file, 0, SEEK_SET);

    /* allocate memory for students */
    struct student *students = (struct student *)malloc(fileSize);
    if (!students) {
        fclose(file);
        return NULL;
    }

    /* read the data from the file */
    fread(students, sizeof(struct student), *numStudents, file);

    fclose(file);

    return students;
}

/******************************************************************************************************************
* Function Prototype: void printStudentData(const struct student *students, int numStudents)
* Purpose: Print student data sorted by student ID.
* Function In parameters: students - Array of students, numStudents - Number of students.
* Function Out parameters: None.
* Version: 1.0
* Author: Hamza El Sousi
***************************************************************************************************************/
void printStudentData(const struct student *students, int numStudents) {
    printf("Student Data Sorted by studentID:\n");

    int i;
    for (i = 0; i < numStudents; i++) {
        printf("Student ID: %08d, Percent Mark: %.2lf, Letter Grade: %s\n",
               students[i].studentID, students[i].percentMark,
               calculateLetterGrade(students[i].percentMark));
    }
}

/******************************************************************************************************************
* Function Prototype: int compareStudentID(const void *a, const void *b)
* Purpose: Compare function for sorting students by ID.
* Function In parameters: a - Pointer to the first student, b - Pointer to the second student.
* Function Out parameters: Returns the result of the comparison.
* Version: 1.0
* Author: Hamza El Sousi
***************************************************************************************************************/
int compareStudentID(const void *a, const void *b) {
    return ((const struct student *)a)->studentID - ((const struct student *)b)->studentID;
}

/******************************************************************************************************************
* Function Prototype: double calculateAverage(const struct student *students, int numStudents)
* Purpose: Calculate the average of student percent marks.
* Function In parameters: students - Array of students, numStudents - Number of students.
* Function Out parameters: Returns the average percent mark.
* Version: 1.0
* Author: Hamza El Sousi
***************************************************************************************************************/
double calculateAverage(const struct student *students, int numStudents) {
    double sum = 0;

    int i;
    for (i = 0; i < numStudents; i++) {
        sum += students[i].percentMark;
    }

    return sum / numStudents;
}

/******************************************************************************************************************
* Function Prototype: 
* Purpose: 
* Function In parameters:
* Function Out parameters: 
* Version: 1.0
* Author: Hamza El Sousi
***************************************************************************************************************/
double calculateMedian(const struct student *students, int numStudents) {
    /* assuming the array is sorted */
    if (numStudents % 2 == 0) {
        /* if even, return the average of the two middle values */
        return (students[numStudents / 2 - 1].percentMark + students[numStudents / 2].percentMark) / 2.0;
    } else {
        /* if odd, return the middle value */
        return students[numStudents / 2].percentMark;
    }
}

/******************************************************************************************************************
* Function Prototype: double calculateMedian(const struct student *students, int numStudents)
* Purpose: Calculate the median of student percent marks.
* Function In parameters: students - Array of students, numStudents - Number of students.
* Function Out parameters: Returns the median percent mark.
* Version: 1.0
* Author: Hamza El Sousi
***************************************************************************************************************/
char* calculateLetterGrade(double percentMark) {
    /* Convert percentMark to letter grade based on the grading criteria */

    char* grade;

    if (percentMark >= 90) {
        if (percentMark >= 97) {
            grade = "A+";  /* A+ */
        } else if (percentMark >= 93) {
            grade = "A";  /* A */
        } else {
            grade = "A-";  /* A- */
        }
    } else if (percentMark >= 80) {
        if (percentMark >= 87) {
            grade = "B+";  /* B+ */
        } else if (percentMark >= 83) {
            grade = "B";  /* B */
        } else {
            grade = "B-";  /* B- */
        }
    } else if (percentMark >= 70) {
        if (percentMark >= 77) {
            grade = "C+";  /* C+ */
        } else if (percentMark >= 73) {
            grade = "C";  /* C */
        } else {
            grade = "C-";  /* C- */
        }
    } else if (percentMark >= 60) {
        if (percentMark >= 67) {
            grade = "D+";  /* D+ */
        } else if (percentMark >= 63) {
            grade = "D";  /* D */
        } else {
            grade = "D-";  /* D- */
        }
    } else {
        grade = "F";
    }

    return grade;
}
