/******************************************************************************************************************
* File: array_operations.h
* Author: Hamza El Sousi
* Student ID: 040-982-818
* Course: CST8234 C Language
* Lab section: 302
* Lab Professor: Natalie Gluzman, Prableen singh
* Due date: Oct. 22, 2023
* Submission date: TBD
* Professors: Surbhi Bahri, Harleen Kaur
* List of sources: [List the actual sources or references you used]
* Purpose: This header file contains function prototypes for working with square 2D arrays. The functions defined here
*          allow operations such as reversing, randomizing, sorting, and printing square 2D arrays.
*******************************************************************************************************************/
#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_INPUT_SIZE 100 /*Max inputs for array size*/

/* Function prototypes for 2D arrays */ 
void reverse_array(int *arr[], int rows, int cols);
void randomize_array(int *arr[], int rows, int cols);
void sort_array(int *arr[], int rows, int cols);
void print_array(int *arr[], int rows, int cols);


#endif
