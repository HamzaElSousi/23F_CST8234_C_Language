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
* Function Prototype: int main(int argc, char *argv[])
* Purpose: The main function of the program.
* Function In parameters: argc - The number of command-line arguments, argv - Array of command-line arguments.
* Function Out parameters: Returns 0 on successful execution.
* Version: 1.0
* Author: Hamza El Sousi
***************************************************************************************************************/
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    /* Task #1 - obtain the name of the file from the command line */
    char *filename = argv[1];

    /* Task #2 - open the file and read its contents */
    int numStudents;
    struct student *students = readStudentData(filename, &numStudents);

    if (students == NULL) {
        fprintf(stderr, "Error reading file %s\n", filename);
        return 1;
    }

    /* Task #3 - sort the data in ascending order using the student identifier */
    qsort(students, numStudents, sizeof(struct student), compareStudentID);

    /* convert the mark to letter grade and print the sorted data */
    printStudentData(students, numStudents);

    /* Task #4 - calculate the average and median numeric grade */
    double average = calculateAverage(students, numStudents);
    double median = calculateMedian(students, numStudents);

    /* print the median and average */
    printf("\nMedian Percent Mark: %.2f\n", median);
    printf("Average Percent Mark: %.2f\n", average);

    /* free allocated memory */
    free(students);

    return 0;
}