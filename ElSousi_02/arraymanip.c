/*******************************************************************************************************************
* Name: Hamza El Sousi
* Student ID: 040-982-818
* Course: CST8234 C Language
* Lab section: 302
* Lab Professor: Natalie Gluzman
* Due date: Oct. 8, 2023
* Submmision date: TBD
* Professor: Surbhi Bahri, Harleen Kaur
* List of sources: <stdio.h> and <stdlib.h>
* Purpose : This program takes numeric inputs from the user and forms an array which can be proccessed with three 
*           different Array Manipulation operations such as Array reversing, randomizing, and sorting.
*******************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* To implement dynamic seed*/

#define MAX_INPUT_SIZE 100 /*Max inputs for array size*/


/******************************************************************************************************************
Functions Prototypes :
Purpose: Declare the signatures of functions that will be used later in the program. This ensures the compiler knows 
         about these functions ahead of their implementations, allowing for forward referencing. This is especially 
         useful if the actual function implementations appear after the `main` function or are defined in other source 
         files.
Function in: 
         - `int arr[]`: An array of integers that will be passed to each function.
         - `int n`: The size or length of the array, which informs the functions how many elements to process.

Function out: 
         - Each function prototype does not indicate a return value because they return `void` (i.e., they don't return 
           any value). However, they manipulate the array in various ways (reversing, randomizing, sorting) or print 
           its content.

Version: 1.0
Author: Hamza El Sousi

EXAMPLE:
         Given an array `{5, 3, 8, 1, 7}` of size 5:
         - `reverse_array` will produce `{7, 1, 8, 3, 5}`
         - `randomize_array` could produce `{3, 8, 5, 7, 1}` or any other random arrangement.
         - `sort_array` will produce `{1, 3, 5, 7, 8}`
         - `print_array` will display the array content in a format like `{5, 3, 8, 1, 7}`
***************************************************************************************************************/
/* Function prototypes */
void reverse_array(int arr[], int n);
void randomize_array(int arr[], int n);
void sort_array(int arr[], int n);
void print_array(int arr[], int n);


/******************************************************************************************************************
Function Name: main
Purpose: Acts as the entry point of the program, guiding the user through populating an array and then offering
         array manipulation options such as reversing, randomizing, and sorting. The user can choose any operation 
         repeatedly until they decide to exit.
Function in: None
Function out: Returns an integer value. (0 for normal termination)
Version: 1.0
Author: Hamza El Sousi

EXAMPLE:
     User is prompted to enter:
     1. Length of array.
     2. Elements of the array.
     3. Choice of operation (reversing, randomizing, or sorting) or exit.

    The operations are executed on the user's array based on their choice, 
    and the modified array is displayed after each operation.
***************************************************************************************************************/
int main() {
    int arr[MAX_INPUT_SIZE];
    int n, choice, inputResult;
    
    /*Array Size Validation*/
    printf("Enter the length:\n");
    while (scanf("%d", &n) != 1 || n <= 0 || n > MAX_INPUT_SIZE) {
        printf("ERROR: Invalid input. Please enter a valid length:\n");
        while (getchar() != '\n');  /* Clear input buffer */ 
    }

    /*Numeric input Validation*/
    printf("Enter %d numbers (space separated):\n", n);
    for (int i = 0; i < n; ++i) {
        while (scanf("%d", &arr[i]) != 1) {
            printf("ERROR: Invalid input. Please re-enter number %d:\n", i+1);
            while (getchar() != '\n');  /* Clear input buffern*/
        }
    }

    /* Print the array after it has been populated */
    print_array(arr, n);
    do {
        printf("Choose an operation:\n");
        printf("(0) : exit\n");
        printf("(1) : reverse array\n");
        printf("(2) : randomize array\n");
        printf("(3) : sort array\n");
        inputResult = scanf("%d", &choice);

        if (inputResult != 1) {
            printf("ERROR: Invalid input. Please choose a number for operation:\n");
            while (getchar() != '\n');  /* Clear input buffer*/ 
            continue;
        }

        switch (choice) {
            case 0:
                break;
            case 1:
                reverse_array(arr, n);
                print_array(arr, n);
                break;
            case 2:
                randomize_array(arr, n);
                print_array(arr, n);
                break;
            case 3:
                sort_array(arr, n);
                print_array(arr, n);
                break;
            default:
                printf("Invalid choice. Please choose a valid operation 0 - 3:\n");
        }
    } while (choice != 0);

    printf("Thank you for using the program!\n");
    return 0;
}

/******************************************************************************************************************
Function Name: reverse_array
Purpose: Reverses the order of elements in a given array.
Function in: An integer array 'arr' and its length 'n'.
Function out: None (But the array is modified in-place).
Version: 1.0
Author: Hamza El Sousi

EXAMPLE:
Before: { 1, 2, 3, 4, 5 }
After reverse_array(): { 5, 4, 3, 2, 1 }
***************************************************************************************************************/
void reverse_array(int arr[], int n) {
    for (int i = 0; i < n/2; ++i) {
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

/******************************************************************************************************************
Function Name: randomize_array
Purpose: Randomizes the order of elements in a given array.
Function in: An integer array 'arr' and its length 'n'.
Function out: None (But the array is modified in-place).
Version: 1.0
Author: Hamza El Sousi

EXAMPLE:
Before: { 1, 2, 3, 4, 5 }
Possible Outcome after randomize_array(): { 3, 1, 5, 2, 4 }
Note: The actual outcome can vary due to randomization.
***************************************************************************************************************/
void randomize_array(int arr[], int n) {
    srandom(time(NULL)); /*Seed random number generator with time() to generate unique randomization as time changes*/ 
    for (int i = 0; i < n; ++i) {
        int j = random() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/******************************************************************************************************************
Function Name: sort_array
Purpose: Sorts the given array in ascending order using the insertion sort algorithm.
Function in: An integer array 'arr' and its length 'n'.
Function out: None (But the array is modified in-place).
Version: 1.0
Author: Hamza El Sousi

EXAMPLE:
Before: { 5, 3, 1, 4, 2 }
After sort_array(): { 1, 2, 3, 4, 5 }
***************************************************************************************************************/
void sort_array(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/******************************************************************************************************************
Function Name: print_array
Purpose: Prints the elements of a given array enclosed within curly braces.
Function in: An integer array 'arr' and its length 'n'.
Function out: None (Just prints the array elements to the console in specified format).
Version: 1.0
Author: Hamza El Sousi

EXAMPLE:
For array: { 1, 2, 3, 4, 5 }
Output: { 1 2 3 4 5 }
***************************************************************************************************************/
void print_array(int arr[], int n) {
    printf("{ ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}
