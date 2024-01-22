/*******************************************************************************************************************
* Name: Hamza El Sousi
* Student ID: 040-982-818
* Course: CST8234 C Language
* Lab section: 302
* Lab Professor: Natalie Gluzman
* Due date:  Sept 21, 2023
* Submmision date: Sept 16, 2023
* Professor: Surbhi Bahri, Harleen Kaur
* List of sources: N/A 
* Purpose : This program determines if 2 given numbers are amicable 
* Amicable num pairs to validate from terminal (220 , 284) && (1184 , 1210)
*******************************************************************************************************************/

#include <stdio.h>

/******************************************************************************************************************
Function Name: sumOfDivisors
Purpose: Function to calculate the sum of proper divisors of a number.
Function in: The input number for which we want to find the sum of divisors 'num'
Function out: The sum of proper divisors of the input number 'sum' 
Version: 2
Author: Hamza El Sousi

Proper divisors of a number are positive integers that evenly divide the number, excluding the number itself.
In this function, we iterate from 1 to num/2 and check if each number in this range is a divisor of 'num'. If it is, we add it to the 'sum' variable.

EXAMPLE: if num = 12:
    - Divisors: 1, 2, 3, 4, 6
    - Sum of proper divisors: 1 + 2 + 3 + 4 + 6 = 16
***************************************************************************************************************/
short int sumOfDivisors(short int num) {
    short int sum = 0;  /* Start with 1 since every number is divisible by 1*/
    short int i = 0; /* declaring i to use in loop */
    for (i = 1; i <= num / 2; i++)  /*All proper divisors must be less than half of the given number 'num'*/{
        if (num % i == 0) /*check if divisors 'i' equally divides num*/{
            sum += i;
        }
    }/*returns sum of proper divisors to compare in main*/
    return sum;
}

/****************************************************************************************************************
Function Name: main
Purpose: Main func is entry  point to the program to determine if numbers are amicable
Function in: N/A 
Function out: N/A
Version: 2
Author: Hamza El Sousi
***************************************************************************************************************/
 int main() {
    /*  Integer variables declaration*/
    short int num1, num2, sum1, sum2;

    /*print method/func to prompt user*/ 
    printf("Enter the two numbers: ");
    /*Scanner method/func to take two inputs*/
    scanf("%hd %hd", &num1, &num2);
 
     sum1 = sumOfDivisors(num1);
     sum2 = sumOfDivisors(num2);

    /*Amicable numbers flow control/decision structure*/ 
    if (sum1 == num2 && sum2 == num1) {
        printf("Entered numbers are amicable.\n");
    } else {
        printf("Entered numbers are not amicable. Try again.\n");
    }
    /*main function ends successfuly with return 0*/
    return 0;
}
