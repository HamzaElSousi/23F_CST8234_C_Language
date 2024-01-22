/*******************************************************************************************************************
* File: print_array.c
* Name: Hamza El Sousi
* Student ID: 040-982-818
* Course: CST8234 C Language
* Lab section: 302
* Lab Professor: Natalie Gluzman, Prableen singh
* Due date: Oct. 22, 2023
* Submmision date: TBD
* Professor: Surbhi Bahri, Harleen Kaur
* List of sources: array_operations.h 
* Purpose : 
*******************************************************************************************************************/

/******************************************************************************************************************
Function Name: print_array
Purpose: Prints the elements of a given 2D array enclosed within curly braces.
Function in: 
    arr - The 2D array to be printed.
    rows - The number of rows in the array.
    cols - The number of columns in the array.
Function out: None (Just prints the array elements to the console in the specified format).
Version: 1.0
Author: Hamza El Sousi
***************************************************************************************************************/

#include "array_operations.h"
#include <stdio.h>

void print_array(int *arr[], int rows, int cols) {
    printf("\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}