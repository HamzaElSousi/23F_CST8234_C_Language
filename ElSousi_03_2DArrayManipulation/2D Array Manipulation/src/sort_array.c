/*******************************************************************************************************************
* File: sort_array.c
* Author: Hamza El Sousi
* Student ID: 040-982-818
* Course: CST8234 C Language
* Lab section: 302
* Lab Professor: Natalie Gluzman, Prableen singh
* Due date: Oct. 22, 2023
* Submission date: TBD
* Professors: Surbhi Bahri, Harleen Kaur
* List of sources: array_operations.h
* Purpose: This source file contains the implementation of the `sort_array` function, which is used to sort the elements
*          in a given square 2D array in ascending order. The function rearranges the elements within the array in a way
*          that the resulting array is sorted.
*******************************************************************************************************************/

/******************************************************************************************************************
Function Name: sort_array
Purpose: Sorts the elements in a given square 2D array in ascending order.
Function in:
    - arr: A pointer to a square 2D array containing integers.
    - rows: The number of rows in the array.
    - cols: The number of columns in the array (equal to the number of rows for a square array).
Function out: None (The input array is modified in place).
Version: 1.0
Author: Hamza El Sousi

EXAMPLE:
    If arr is a 3x3 square array containing the following elements:
    9 4 7
    2 5 1
    6 8 3
    After calling sort_array(arr, 3, 3), the elements will be sorted in ascending order:
    1 2 3
    4 5 6
    7 8 9
***************************************************************************************************************/

#include "array_operations.h"

void sort_array(int *arr[], int rows, int cols) {
    // Flatten the 2D array into a 1D array for sorting
    int flattened[rows * cols];
    int k = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            flattened[k++] = arr[i][j];
        }
    }

    //  sorting algorithm here (e.g., bubble sort)
    for (int i = 0; i < rows * cols - 1; ++i) {
        for (int j = 0; j < rows * cols - i - 1; ++j) {
            if (flattened[j] > flattened[j + 1]) {
                int temp = flattened[j];
                flattened[j] = flattened[j + 1];
                flattened[j + 1] = temp;
            }
        }
    }

    // Fill the sorted values back into the 2D array
    k = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = flattened[k++];
        }
    }
}
