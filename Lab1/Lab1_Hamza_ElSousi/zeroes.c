/**********************************************************************************************************************
* Name: Hamza El Sousi
* Student ID: 040-982-818
* Course: CST8234 C Language
* Lab section: 302
* Lab Professor: Natalie Gluzman
* Due date:  Sept 21, 2023
* Submmision date: Sept 16, 2023
* Professor: Surbhi Bahri, Harleen Kaur
* List of sources: N/A 
* Purpose : This program determines if there are 3 consecutive zeros in a number.  
***********************************************************************************************************************/
#include <stdio.h>

/***********************************************************************************************************************
Function Name: main
Purpose: main method and entry point to zeroes program
Function in: takes a given number from scanf
Function out: Evaluates the input and prints YES if 3 consecutive zeros are found OR NO if less than 3 consecutive zeros.
Version: 2
Author: Hamza El Sousi
***********************************************************************************************************************/
#include <stdio.h>

int main() {
    long num; /* Using long to handle large numbers */
    int consecutiveZeros = 0;

    /*print statement to prompt user*/
    printf("Enter a number: ");
    /*Scanner method/func to take one long numeric input using '%ld' and pointing to num's address*/
    scanf("%ld", &num);

    while (num > 0) {
        /*storing 'num % 10' in 'PrevDigit'*/
        int prevDigit = num % 10;
        if (prevDigit == 0) {
            consecutiveZeros++;
            /*Counts if equals to three which refers to amount of 0s encounterd*/
            if (consecutiveZeros == 3) {
                printf("YES\n");
                return 0;
            }
        } else {
            /*Reset the count if a non-zero digit is encountered*/
            consecutiveZeros = 0;         }
         /* Move to the next digit from right to left of the number*/
        num /= 10; 
    }

    printf("NO\n");
    /* main function ends succsessfuly with return 0*/
    return 0;
}