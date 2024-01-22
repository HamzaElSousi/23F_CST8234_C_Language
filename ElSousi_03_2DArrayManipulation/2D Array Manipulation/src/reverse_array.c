/*******************************************************************************************************************
* File: reverse_array.c
* Author: Hamza El Sousi
* Student ID: 040-982-818
* Course: CST8234 C Language
* Lab section: 302
* Lab Professor: Natalie Gluzman, Prableen singh
* Due date: Oct. 22, 2023
* Submission date: TBD
* Professors: Surbhi Bahri, Harleen Kaur
* List of sources: array_operations.h
* Purpose: This source file contains the implementation of the `reverse_array` function, which is used to reverse the
*          order of elements in a given square 2D array. The function reverses both rows and columns, effectively
*          flipping the entire array.
*******************************************************************************************************************/

/******************************************************************************************************************
Function Name: reverse_array
Purpose: Reverses the order of elements in a given square 2D array, effectively flipping it.
Function in:
    - arr: A pointer to a square 2D array containing integers.
    - rows: The number of rows in the array.
    - cols: The number of columns in the array (equal to the number of rows for a square array).
Function out: None (The input array is modified in place).
Author: Hamza El Sousi

EXAMPLE:
    If arr is a 3x3 square array containing the following elements:
    1 2 3
    4 5 6
    7 8 9
    After calling reverse_array(arr, 3, 3), arr will contain:
    9 8 7
    6 5 4
    3 2 1
***************************************************************************************************************/

#include "array_operations.h"
#include <stdio.h>

void reverse_array(int *arr[], int rows, int cols) {
    // Reverse rows
    for (int i = 0; i < rows / 2; ++i) {
        for (int j = 0; j < cols; ++j) {
            int temp = arr[i][j];
            arr[i][j] = arr[rows - i - 1][j];
            arr[rows - i - 1][j] = temp;
        }
    }

    // Reverse columns
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols / 2; ++j) {
            int temp = arr[i][j];
            arr[i][j] = arr[i][cols - j - 1];
            arr[i][cols - j - 1] = temp;
        }
    }
}
