/* Expressions Chapter 3
 * Jonah Shulske
 * COSC-1436 Fall 2024
 * 9/9/24
 */

#include <iostream>
#include <string>

int main()
{
    /* Getting user's input
     * Never trust the user
     * Stream - Series of data
     */
    std::string name;
    std::cout << "Enter your name: ";

    /* std::cin >> v
     * Inserts value up to first whitespace into variable. Doesn't work with spaced strings
     */
    // std::cin >> name;
    std::getline(std::cin, name);

    std::cout << "Hello, " << name << std::endl;

    int hours;
    std::cout << "How many hours did you work this week? ";
    std::cin >> hours;

    double payRate;
    std::cout << "How much do you make per hour? ";
    std::cin >> payRate;
    std::cout << "You earned: " << (hours * payRate) << " this week" << std::endl;

    // Multi-value input, values are whitespace separated.
    int x, y;
    std::cout << "Enter the X, Y values of a point: ";
    std::cin >> x >> y;

    /* Associatives
    * Majority of operators are left associative, = is right associative. PEMDAS is still in this.
    */

    /* Type Coercion - Compiler changes the type of expression.
      No impact on runtime code generation (Always safe)
      Only impacts current expression.
      Type hierarchy: larger of two operand types (Top: double, float, unsigned long, long, unsigned int, int, char/short/unsigned short (converted to int) :Bottom)
       double = int * double, Compiler will force these to be the same type by treating the int like a double
     * double = double * double (Type Coercion)
     * double = double
     * double + float * int => Results in a double. Precedence rules don't apply, just find the largest type.
     * Assignment doesn't matter, types determined on each side of operator
     * double = int * float
    */
    double result = hours * payRate;

    /* Overflow and Underflow
    * Overflow - When you try to store a value in a type, and the value is too large for the type. Underflow - Value is too small for type.
    *
    */
    short smallValue = 32767 + 1; //Overflow, as max for short is 32767
    std::cout << smallValue << std::endl;

    short largeValue = -32768 - 1; //Underflow, as min for short is - 32678
    std::cout << largeValue << std::endl;

    float floatValue = 1e38 + 1e2;
    std::cout << floatValue << std::endl;


}