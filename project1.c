
/* project1.c
 * Teal Hoffman
 * EE 160
 * 10/27/2024
 *
 * NOTE TO USER
 * ------------
 * This is version 5 of project 1!
 * There are 2 other files that go along with this one: secant.c and myfunc.c
 * The header files are secantv5.h and myfuncv5.h
 * Future iterations can include more/better error handling (fgets and sscanf, etc.)
 *
 **************************************************************************************************************
 * 
 * PURPOSE
 * -------
 * The purpose of this project is to implement the secant method to solve for the roots of a 5th 
 *     degree polynomial.
 *     The coefficients of the polynomial (a, b, c, d, e, f) will be defined by the user in the form of: 
 *     a + bx + cx^2 + dx^3 + ex^4 + fx^5
 * 
 * ERROR HANDLING 
 * --------------
 * This source code for project1.c does not contain any error handling/messages (please see secant.c)
 * 
 * (USER) INPUT
 * ------------
 * a: (double) The coefficient 'a' for the polynomial a + bx + cx^2 + dx^3 + ex^4 + fx^5
 * b: (double) The coefficient 'b' for the polynomial a + bx + cx^2 + dx^3 + ex^4 + fx^5
 * c: (double) The coefficient 'c' for the polynomial a + bx + cx^2 + dx^3 + ex^4 + fx^5
 * d: (double) The coefficient 'd' for the polynomial a + bx + cx^2 + dx^3 + ex^4 + fx^5
 * e: (double) The coefficient 'e' for the polynomial a + bx + cx^2 + dx^3 + ex^4 + fx^5
 * f: (double) The coefficient 'f' for the polynomial a + bx + cx^2 + dx^3 + ex^4 + fx^5
 * xmin: (double) The minimum x value which will be the starting value of the table 
 * xmax: (double) The maximum x value which will be the ending value of the table
 * steps: (double) The amount of steps/intervals the table will have of x values from start to end
 * choice: (character) Allows the user to decide if they would like to change the search range of the table 
 * 
 * OUTPUT
 * ------
 * After the user inputs the coefficients, the program will show the full polynomial equation
 * The xmin and xmax the user inputed ("You entered...")
 * A table with the x-value, y-value, and whether or not there was a sign change to return the x-root
 * Total sign changes located on table
 * The program will ask if the user wants to change the search range of the table and it will
 *     terminate if the user inputs 'n' or 'N' 
 *
 * VERSION HISTORY 
 * ---------------
 * Version 1: 
 *     File Name(s): projectv1.c
 *     One source code... This version included the function for the secant method and the function
 *     to calculate the polynomial. Instead of having the user input coefficients (a, b, c, d, e, f)
 *     the polynomial was "hard-coded" with a polynomial we had previously solved for and know the roots of.
 *     The "hard-coded" polynomial will be f(x)=x^2-10x+21
 * Version 2: 
 *     File Name(s): projectv2.c
 *     Allowed the user to input the coefficients (a, b, c), but it was just for the polynomial a+bx+cx^2
 * Version 3: 
 *     File Name(s): projectv3.c
 *     Allowed the user to input the coefficients (a, b, c, d, e, f), 
 *     for the polynomial a+bx+cx^2+dx^3+ex^4+fx^5
 * Version 3_b:
 *     File Name(s): projectv3_b.c
 *     After realizing the main function was too long, this version was made to put the secant method 
 *     loop in the secant function. Logic errors for amount of sign changes were also made in this version.
 * Version 4: 
 *     File Name(s): projectv4.c secantv4.c secantv4v.h 
 *     The source code that was all in one file was separated into a secantv4.c file 
 *     (that includes a )
 * Version 5: 
 *     File Name(s): projectv5.c secantv5.c myfuncv5.c secantv5.h myfuncv5.h
 *     The same source code of this file but without the comments.
 *     Used source code from version 3_b to complete this version.
 * NOTE: This final version (project1.c) uses the header files secant.h and myfunc.h 
 *     Rearranged some of the variables to allow comments 
 *
 * PSEUDOCODE
 * ----------
 * 1)  Declare the varaibles 'a' 'b' 'c' 'd' 'e' 'f' as doubles 
 * 2)  Declare 'xmin' and 'xmax' as doubles
 * 3)  Declare 'x' as double 
 * 4)  Declare 'interval' as double
 * 5)  Declare 'old_y' and 'current_y' as double 
 * 6)  Declare 'x0' and 'x1' as doubles 
 * 7)  Declare 'x_root' as double
 * 8)  Declare 'steps' as integer 
 * 9)  Declare 'n' as integer 
 * 10) Declare 'choice' as character
 * 11) Declare 'done' as integer and define it as FALSE 
 * 12) Ask the user to input the coefficient values (a b c d e f) 
 * 13) Take the input and store as 'a' 'b' 'c' 'd' 'e' 'f' in that order
 * 14) Show the user what they inputed and how their polynomial looks 
 * 15) While not done 
 * 16)     Ask user for the minimum and maximum values for x 
 * 17)     Take input and store as 'xmin' and 'xmax' in that order
 * 18)     Show the user what they inputed as xmin and xmax
 * 19)     Ask user to enter how many steps they'd like to get from their xmin to xmax
 * 20)     Take input and store as 'steps'
 * 21)     Define and calculate the interval from amount of steps inputed
 * 22)     Print the table headers  
 * 23)     Initialize x to whatever the user input as the minimum
 * 24)     Initialize the first y-value for the first x value that goes into the polynomial function
 * 25)     While x is less than or equal to xmax 
 * 26)         Set the current y-value calculation within the loop
 * 27)         If the old_y multiplied by the current_y is less than 0
 * 28)             Define x0 as the previous x-value (x - increment) in the table 
 * 29)             Define x1 as the current x-value (x) in the table 
 * 30)             Define x_root by calling the secant function 
 * 31)             Print the x-value, y-value, AND the root located (returned from the secant function) 
 * 32)             Add 'n' everytime the loop goes through the secant function and x_root is returned
 * 33)         else
 * 34)             print just the current x-value and y-value in the loop
 * 35)         Define the old_y as the current_y 
 * 36)         Add an interval for the loop by adding 'x' to 'interval'
 * 37)     Print the total sign changes detected 
 * 38)     Ask user if they would like to change the search range for the table 
 * 39)     Take input and store as 'choice'
 * 40)     Print a newline character
 * 41)     if user's choice is 'n' or 'N' 
 * 42)         Update value of 'done' to TRUE (terminate the program) 
 * 43)     else
 * 44)         Update value of 'done' to FALSE (return the user to ask for xmin and xmax)
 *
 **************************************************************************************************************
 */

// The header files 
#include "secant.h"
#include "myfunc.h"

// Main Function 
int main() {

     // 1-11) Declare all variables 
     double a, b, c, d, e, f;     // The coefficients inputed by the user 
     double xmin, xmax;           // The start and end x-values 
     double x;                    // The x-value in the output table 
     double interval;             // Used to calculate the next x-value in the table given the amount of steps
     double old_y, current_y;     // Used to detect a sign change in the loop 
     double x0, x1;               // The values that will go to the secant function
     double x_root;               // The value returned from the secant function
     int steps;                   // The amount of steps the user wants 
     int n;                       // Used to determine how many times a root/sign change is detected 
     char choice;                 // Used to see whether or not the user wants to change the search range 
     int done = FALSE;            // Used for the loop to see if the user wants to change the search range
     
     // 12) Ask the user to input the coefficient values (a b c d e f) 
     // 13) Take the input and store as 'a' 'b' 'c' 'd' 'e' 'f' in that order  
     // 14) Show the user what they inputed and how their polynomial looks 
     printf("Enter the coefficients for a polynomial of the form: \n    a + bx + cx^2 + dx^3 + ex^4 + fx^5 \n");
     printf("Enter a b c d e f: ");
     scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
     printf("The function is: %.2lf + %.2lfx + %.2lfx^2 + %.2lfx^3 + %.2lfx^4 + %.2lfx^5 \n", a, b, c, d, e, f);

     // 15) The while not done loop to allow the user to change the search range for the table 
     while (!done) {

           // 16) Ask user for the minimum and maximum values for x 
           // 17) Take input and store as 'xmin' and 'xmax' in that order 
           // 18) Show the user what they inputed as xmin and xmax
           printf("Please enter a minimum number and a maximum number separated by a space:");
           scanf("%lf %lf", &xmin, &xmax);
           printf("You entered %3.1lf as the xmin and %3.1lf as xmax\n",xmin,xmax);

           // 19) Ask user to enter how many steps they'd like to get from their xmin to xmax
           // 20) Take input and store as 'steps'
           printf("Please enter an amount of steps you would like to take to get from %3.1lf to %3.1lf:", xmin, xmax);
           scanf(" %i", &steps);

           // 21) Define and calculate the interval from amount of steps inputed 
           interval = (xmax - xmin)/steps;

           // 22) Print the table headers  
           printf(" x-value  y-value    x-root   \n");
           printf(" =======  =======   ========  \n");

           // 23) Initialize x to whatever the user input as the minimum
           // 24) Initialize the first y-value for the first x value that goes into the polynomial function
           x = xmin; 
           old_y = myfunc(x, a, b, c, d, e, f);  

           // The table loop
           // 25) While x is less than or equal to xmax 
           while (x <= xmax) {
               // 26) Set the current y-value calculation within the loop
               current_y = myfunc(x, a, b, c, d, e, f);  

               // 27) If the old_y multiplied by the current_y is less than 0...
               // Logic: the product of two opposite signs are negative and a negative number is less than 0
               if (old_y*current_y < 0) {  

                    // 28) Define x0 as the previous x-value (x - increment) in the table 
                    // 29) Define x1 as the current x-value (x) in the table 
                    // 30) Define x_root by calling the secant function 
                    x0 = x - interval;
                    x1 = x;
                    x_root = secant(x1, x0, a, b, c, d, e, f);

                    // 31) Print the x-value, y-value, AND the root located (returned from the secant function) 
                    printf("%6.3lf    %6.3lf     <= the root located is: %-.3lf\n", x, current_y, x_root);

                    // 32) Add 'n' everytime the loop goes through the secant function and x_root is returned
                    n++;  
               }
               // 33) else
               //     34) print just the current x-value and y-value in the loop
               else {
                    printf("%6.3lf    %6.3lf     \n", x, current_y);
               }

               // 35) Define the old_y as the current_y 
               // 36) Add an interval for the loop by adding 'x' to 'interval' 
               old_y = current_y;  
               x = x + interval;
           }
           // 37) Print the total sign changes detected 
           printf("Total sign changes located on table is: %i \n", n);

           // 38) Ask user if they would like to change the search range for the table 
           // 39) Take input and store as 'choice'
           // 40) Print a newline character
           printf("Do you wish to change the search range for the table? (y/n): ");
           scanf(" %c", &choice);
           printf("\n");

           // 41) if user's choice is 'n' or 'N' 
           //     42) Update value of 'done' to TRUE (terminate the program) 
           // 43) else 
           //     44) Update value of 'done' to FALSE (return the user to ask for xmin and xmax)
           if (choice == 'n' || choice == 'N') {
                done = TRUE;
           }
           else  {
                done = FALSE;
           }
     }
     return 0;
}
