/*******************************************************************************************************************
* Name: Hamza El Sousi
* Student ID: 040-982-818
* Course: CST8234 C Language
* Lab section: 302
* Lab Professor: Natalie Gluzman
* Due date: Nov. 19, 2023
* Submission date: Nov. 11, 2023
* Professors: Surbhi Bahri, Harleen Kaur
* List of sources: <stdio.h>, <stdlib.h>, "students.h", "courses.h", "registration.h"
* Purpose: This program provides a Student Registration System, allowing registration and management of students in courses.
*******************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "students.h"
#include "courses.h"
#include "registration.h"

/******************************************************************************************************************
* Function Prototype: int main()
* Purpose: Entry point of the Student Registration System program.
* Function In parameters: None
* Function Out parameters: Returns 0 upon successful execution.
* Version: 1.0
* Author: Hamza El Sousi
***************************************************************************************************************/
int main() {
    Student *students = NULL;
    Course *courses = NULL;
    Registration *registrations = NULL;
    int studentCount = 0, courseCount = 0, registrationCount = 0;

    printf("Welcome to Student Registration System.\n");

    printf("Enter the number of students to register: ");
    scanf("%d", &studentCount);
    getchar(); // consume newline character

    students = (Student *)malloc(studentCount * sizeof(Student));
    if (students == NULL) {
        perror("Memory allocation for students failed");
        exit(1);
    }

    for (int i = 0; i < studentCount; i++) {
        printf("Enter the student index[%d] ID [5-digits]: ", i);
        if (!readStudentId(students[i].id)) {
            free(students);
            exit(1);
        }
    }

    printf("Enter the number of courses available: ");
    scanf("%d", &courseCount);
    getchar(); // consume newline character

    courses = (Course *)malloc(courseCount * sizeof(Course));
    if (courses == NULL) {
        perror("Memory allocation for courses failed");
        free(students);
        exit(1);
    }

    for (int i = 0; i < courseCount; i++) {
        printf("Enter the course index[%d] ID [3-Alphas][4-digits]: ", i);
        if (!readCourse(courses[i].id)) {
            free(students);
            free(courses);
            exit(1);
        }
    }

    // Calculate the maximum number of possible registrations
    int maxRegistrations = studentCount * courseCount;
    registrations = (Registration *)malloc(maxRegistrations * sizeof(Registration));
    if (registrations == NULL) {
        perror("Memory allocation for registrations failed");
        free(students);
        free(courses);
        exit(1);
    }

    initializeRegistrations(registrations, maxRegistrations);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("[1] Register a student into a course.\n");
        printf("[2] Drop a student from a course.\n");
        printf("[3] Display Registration table.\n");
        printf("[4] Exit.\n");
        printf("Enter an option from the menu: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                listStudentIDs(students, studentCount);
                registerStudentToCourse(registrations, &registrationCount);
                    // printf("Registration Successful.\n")
                break;
            case 2:
                if (dropStudentFromCourse(registrations, &registrationCount)) {
                    printf("Student dropped from the course.\n");
                }
                break;
            case 3:
                displayRegistrations(registrations, registrationCount);
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    // Free dynamically allocated memory
    free(students);
    free(courses);
    free(registrations);

    return 0;
}