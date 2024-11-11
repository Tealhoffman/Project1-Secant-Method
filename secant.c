/* secant.c
 * Teal Hoffman
 * EE 160
 * 10/27/2024
 * 
 * NOTE TO USER
 * ------------
 * This is version 5 of project 1!
 * There are 2 other files that go along with this one: project1.c and myfunc.c
 * The header files are secantv5.h and myfuncv5.h
 * Future iterations can include more/better error handling (fgets and sscanf, etc.)
 *
 **************************************************************************************************************
 * 
 * PURPOSE
 * -------
 * The purpose of this code is to take x0 and x1 and return an x_root
 * 
 * ERROR HANDLING 
 * --------------
 * This source code contains two error handling messages 
 *     One of them is for a division by zero error
 *         If the absolute value of the denominator is close to zero then there will be an error message 
 *     The other error message is if the secant method does not converge to a x-value at a defined 'max_value'
 * 
 * INPUT 
 * -----
 * Calls main function (project1.c) to get 'x1' 'x0' 'a' 'b' 'c' 'd' 'e' 'f' in that order, as doubles 
 * Calls myfunc.c to get ('x1' OR 'x0') 'a' 'b' 'c' 'd' 'e' 'f'
 * 
 * OUTPUT 
 * ------
 * After calling myfunc.c it outputs the 'y1' and 'y0' values 
 * Outputs the 'x_root' to the main function (project1.c)
 * 
 * VERSION HISTORY
 * ---------------
 * Version 1-3/3_b: 
 *     Not yet made 
 * Version 4: 
 *     Only contains a secant function to calculate the next x-value (no loop) 
 * Version 5: 
 *     Used version 3_b to split into a seperate secant.c function that contains a loop to return 'x_root'
 * 
 * PSEUDOCODE
 * ----------
 * 1)  Declare function to calculate secant method and take in 'x1' 'x0' 'a' 'b' 'c' 'd' 'e' 'f' in that order, as doubles 
 * 2)  Declare 'y1' as double and defines it as the myfunc function to input the 'x1' 'a' 'b' 'c' 'd' 'e' 'f' values 
 * 3)  Declare 'y0' as double and defines it as the myfunc function to input the 'x0' 'a' 'b' 'c' 'd' 'e' 'f' values
 * 4)  Declare 'x_new' as double 
 * 5)  Declare 'epsilon' as double and define it to be 0.0001
 * 6)  Declare 'max_value' as an integer to be 25000  
 * 7)  Declare 'i' as an integer and define it to be 0 (Initialize the loop)
 * 8)  If the absolute value of (y1-y0) is less than epsilon
 * 9)      Print an error message to tell user the denominator is close to zero 
 * 10)     return the x1 value to the main function 
 * 11) While i is less than or equal to the 'max_value'
 * 12)     Declare 'x_new' using the secant method 
 * 13)     If the absolute value of the y-value from the myfunc function with an input of 'x_new' is less than epsilon (close to zero)
 * 14)         return the 'x_new' value to the main function 
 * 15)     Update guesses for next iteration
 * 16)     Declare 'x0' as 'x1'
 * 17)     Declare 'y0' as 'y1'
 * 18)     Declare 'y1' as the y-value that will be calculated with the myfunc function
 * 19)     Increase the increment by 1
 * 20) If 'i' equals the 'max_value'
 * 21)     Tell the user the secant method did not find a converging x-value
 * 22)     Return the 'x1' value  
 * 
 **************************************************************************************************************
 */

// Header files 
#include "secant.h"
#include "myfunc.h"

// 1) Declare function to calculate secant method and take in 'x1' 'x0' 'a' 'b' 'c' 'd' 'e' 'f' in that order, as doubles 
double secant(double x1, double x0, double a, double b, double c, double d, double e, double f) {

    // 2-7) Declare all variables 
    double y1 = myfunc(x1, a, b, c, d, e, f);    // Calls myfunc.c
    double y0 = myfunc(x0, a, b, c, d, e, f);    // Calls myfunc.c 
    double x_new;                                // Used to update the value in the loop 
    double epsilon = 0.0001;                     // Used as a number to be close to zero  
    int max_value = 25000;                       // So secant method does not go in an infinite loop 
    int i = 0;                                   // Used to update the increments of the loop

    // Division by zero (see textbook section 3.1, p.g. 85)
    // 8) If the absolute value of (y1-y0) is less than epsilon
    //     9)  Print an error message to tell user the denominator is close to zero 
    //     10) Return the x1 value 
    if (fabs(y1-y0) < epsilon) {
        printf("***Error: Denominator of secant method is close to zero");
        return x1;
    }

    // Secant method loop
    // 11) While i is less than or equal to the 'max_value'
    while (i <= max_value) {
         // 12) Declare 'x_new' using the secant method 
         x_new = x1 - y1 * ((x1 - x0)/(y1 - y0));

         // 13) If the absolute value of the y-value from the myfunc function with an input of 'x_new' is less than epsilon (close to zero)
         if (fabs(myfunc(x_new, a, b, c, d, e, f)) < epsilon) {  // Check if root is found
              // 14) return the 'x_new' value to the main function 
              return x_new;
         }

         // 15) Update guesses for next iteration
         // 16) Declare 'x0' as 'x1'
         // 17) Declare 'y0' as 'y1'
         // 18) Declare 'y1' as the y-value that will be calculated with the myfunc function
         x0 = x1;
         y0 = y1;
         x1 = x_new;
         y1 = myfunc(x_new, a, b, c, d, e, f);

         // 19) Increase the increment by 1
         i++;

    }

    // 20) If 'i' equals the 'max_value'
    //     21) Tell the user the secant method did not find a converging x-value
    //     22) Return the 'x1' value  
    if (i == max_value) {
         printf("In %i iterations, the secant method did not find a converging x-value\n", max_value);
         return x1;
    }