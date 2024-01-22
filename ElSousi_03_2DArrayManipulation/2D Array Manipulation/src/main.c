/*******************************************************************************************************************
* Name: Hamza El Sousi
* Student ID: 040-982-818
* Course: CST8234 C Language
* Lab section: 302
* Lab Professor: Natalie Gluzman, Prableen singh
* Due date: Oct. 22, 2023
* Submission date: TBD
* Professors: Surbhi Bahri, Harleen Kaur
* List of sources: 
*                     C_Files[] = { main.c, print_array.c, randomize_array.c, reverse_array.c, sort_array.c}
*                     H_Files[] = { array_operations.h}
* Purpose: This program allows the user to work with a square 2D array, guiding them through populating the array 
*          and offering various manipulation options such as reversing, randomizing, and sorting. The user can choose 
*          from these operations repeatedly until they decide to exit.  
*******************************************************************************************************************/

#include "array_operations.h"

/******************************************************************************************************************
Function Name: main
Purpose: This function acts as the entry point of the program. It guides the user through populating a 2D array,
         and then offers options for manipulating the array, such as reversing, randomizing, sorting, and printing.
         The user can choose these operations repeatedly until they decide to exit.
Function in: None
Function out: Returns an integer value (0 for normal termination)
Version: 1.0
Author: Hamza El Sousi
*******************************************************************************************************************/

int main() {
    int n, m, choice, inputResult;

    /* Array Size Validation */
    printf("Enter the row size of 2D array:\n");
    while (scanf("%d", &n) != 1 || n <= 0 || n > MAX_INPUT_SIZE) {
        printf("ERROR: Invalid input. Please enter a valid row size:\n");
        while (getchar() != '\n'); /* Clear input buffer */
    }

    printf("Enter the column size of 2D array:\n");
    while (scanf("%d", &m) != 1 || m <= 0 || m > MAX_INPUT_SIZE || m != n) {
        if (m != n) {
            printf("ERROR: Array must be a square matrix. Please enter equal row and column sizes:\n");
        } else {
            printf("ERROR: Invalid input. Please enter a valid column size:\n");
        }
        while (getchar() != '\n'); /* Clear input buffer */
    }

    /* Allocate memory for the 2D array */
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    /* Numeric input Validation */
    printf("Enter %d numbers (space separated):\n", n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            while (scanf("%d", &arr[i][j]) != 1) {
                printf("ERROR: Invalid input. Please re-enter number at row %d, column %d:\n", i + 1, j + 1);
                while (getchar() != '\n'); /* Clear input buffer */
            }
        }
    }

    /* Print the array after it has been populated */
    print_array(arr, n, m);

    do {
        printf("Choose an operation:\n");
        printf("(0) : exit\n");
        printf("(1) : reverse array\n");
        printf("(2) : randomize array\n");
        printf("(3) : sort array\n");
        printf("(4) : print array\n");
        inputResult = scanf("%d", &choice);

        if (inputResult != 1) {
            printf("ERROR: Invalid input. Please choose a number for operation:\n");
            while (getchar() != '\n'); /* Clear input buffer */
            continue;
        }

        switch (choice) {
            case 0:
                break;
            case 1:
                reverse_array(arr, n, m);
                print_array(arr, n, m);
                break;
            case 2:
                randomize_array(arr, n, m);
                print_array(arr, n, m);
                break;
            case 3:
                sort_array(arr, n, m);
                print_array(arr, n, m);
                break;
            case 4:
                print_array(arr, n, m);
                break;
            default:
                printf("Invalid choice. Please choose a valid operation 0 - 4:\n");
        }
    } while (choice != 0);

    /* Free the allocated memory for the 2D array */
    for (int i = 0; i < n; ++i) {
        free(arr[i]);
    }
    free(arr);

    printf("Thank you for using the program!\n");
    return 0;
}
