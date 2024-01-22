/*******************************************************************************************************************
* File: randomize_array.c
* Author: Hamza El Sousi
* Student ID: 040-982-818
* Course: CST8234 C Language
* Lab section: 302
* Lab Professor: Natalie Gluzman, Prableen singh
* Due date: Oct. 22, 2023
* Submission date: TBD
* Professors: Surbhi Bahri, Harleen Kaur
* List of sources: array_operations.h
* Purpose: This source file contains the implementation of the `randomize_array` function, which is used to randomize
*          the order of elements in a given square 2D array. The function shuffles the elements randomly, providing a
*          different outcome each time it's called.
*******************************************************************************************************************/


/******************************************************************************************************************
Function Name: randomize_array
Purpose: Randomizes the order of elements in a given square 2D array.
Function in:
    - arr: A pointer to a square 2D array containing integers.
    - rows: The number of rows in the array.
    - cols: The number of columns in the array (equal to the number of rows for a square array).
Function out: None (The input array is modified in place).
Version: 1.0
Author: Hamza El Sousi

EXAMPLE:
    If arr is a 3x3 square array containing the following elements:
    1 2 3
    4 5 6
    7 8 9
    After calling randomize_array(arr, 3, 3), the elements will be randomly shuffled within the array.
    Note: The actual outcome can vary due to randomization.
***************************************************************************************************************/

#include "array_operations.h"
#include <stdlib.h>
#include <time.h> 


/*randomize_array: Shuffles the elements within the 2D array*/
void randomize_array(int *arr[], int rows, int cols) {
    srand(time(NULL)); /* Seed random number generator with time() to generate unique randomization as time changes */
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int x = rand() % rows;
            int y = rand() % cols;
            int temp = arr[i][j];
            arr[i][j] = arr[x][y];
            arr[x][y] = temp;
        }
    }
}

