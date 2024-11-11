 /* myfunc.c
 * Teal Hoffman
 * EE 160
 * 10/27/2024
 * This is version 5 of project 1!
 *
 * NOTE TO USER
 * ------------
 * This is version 5 of project 1!
 * There are 2 other files that go along with this one: project1.c and secant.c
 * The header files are secantv5.h and myfuncv5.h
 * Future iterations can include more/better error handling (fgets and sscanf, etc.)
 *
 **************************************************************************************************************
 * 
 * PURPOSE
 * -------
 * The purpose of this code is to take the inputs 'input' 'a' 'b' 'c' 'd' 'e' 'f' and return the calculated
 *     polynomial
 * 
 * ERROR HANDLING 
 * --------------
 * This source code for myfunc.c does not contain any error handling/messages (please see secant.c)
 * 
 * INPUT 
 * -----
 * Calls main function (project1.c) to get 'input' 'a' 'b' 'c' 'd' 'e' 'f' in that order, as doubles 
 * 
 * OUTPUT 
 * ------
 * After calling project1.c it outputs the y-value that will go in the table  
 * Outputs the calculation of the polynomial to the secant function as well 
 * 
 * VERSION HISTORY
 * ---------------
 * Versions 1, 2, 3, 3_b, 4: 
 *     Not yet made 
 * Version 5: 
 *     Used version 3_b to split into a seperate myfunc.c function returns the polynomial calculation 
 * 
 * PSEUDOCODE
 * ----------
 * 1) Declare the functions for calculating the polynomial with 'input' 'a' 'b' 'c' 'd' 'e' 'f' as doubles in that order 
 * 2)     Return the calculated polynomial with the inputs 'input' 'a' 'b' 'c' 'd' 'e' 'f'
 * 
 **************************************************************************************************************
 */

// Header files 
#include "secant.h"
#include "myfunc.h"

// 1) Declare the functions for calculating the polynomial with 'input' 'a' 'b' 'c' 'd' 'e' 'f' as doubles in that order 
double myfunc(double input, double a, double b, double c, double d, double e, double f) {
    // 2) Return the calculated polynomial with the inputs 'input' 'a' 'b' 'c' 'd' 'e' 'f'
    return a + b*input + c*pow(input,2) + d*pow(input,3) + e*pow(input,4) + f*pow(input,5);
}
