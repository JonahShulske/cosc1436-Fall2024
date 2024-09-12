/* Expressions Chapter 3
 * Jonah Shulske
 * COSC-1436 Fall 2024
 * 9/9/24
 */

#include <iostream>
#include <string>
#include <cmath> // C Math Functions
#include <iomanip> // Formatted output

// Include the std namespace so we don't have to use it on everything.
using namespace std;

int main()
{
    ///* Getting user's input
    // * Never trust the user
    // * Stream - Series of data
    // */
    //std::string name;
    //std::cout << "Enter your name: ";

    ///* std::cin >> v
    // * Inserts value up to first whitespace into variable. Doesn't work with spaced strings
    // */
    //// std::cin >> name;
    //std::getline(std::cin, name);

    //std::cout << "Hello, " << name << std::endl;

    //int hours;
    //std::cout << "How many hours did you work this week? ";
    //std::cin >> hours;

    //double payRate;
    //std::cout << "How much do you make per hour? ";
    //std::cin >> payRate;
    //std::cout << "You earned: " << (hours * payRate) << " this week" << std::endl;

    //// Multi-value input, values are whitespace separated.
    //int x, y;
    //std::cout << "Enter the X, Y values of a point: ";
    //std::cin >> x >> y;

    ///* Associatives
    //* Majority of operators are left associative, = is right associative. PEMDAS is still in this.
    //*/

    ///* Type Coercion - Compiler changes the type of expression.
    //  No impact on runtime code generation (Always safe)
    //  Only impacts current expression.
    //  Type hierarchy: larger of two operand types (Top: double, float, unsigned long, long, unsigned int, int, char/short/unsigned short (converted to int) :Bottom)
    //   double = int * double, Compiler will force these to be the same type by treating the int like a double
    // * double = double * double (Type Coercion)
    // * double = double
    // * double + float * int => Results in a double. Precedence rules don't apply, just find the largest type.
    // * Assignment doesn't matter, types determined on each side of operator
    // * double = int * float
    //*/
    //double result = hours * payRate;

    ///* Overflow and Underflow
    //* Overflow - When you try to store a value in a type, and the value is too large for the type. Underflow - Value is too small for type.
    //*
    //*/
    //short smallValue = 32767 + 1; //Overflow, as max for short is 32767
    //std::cout << smallValue << std::endl;

    //short largeValue = -32768 - 1; //Underflow, as min for short is - 32678
    //std::cout << largeValue << std::endl;

    //float floatValue = 1e38 + 1e2;
    //std::cout << floatValue << std::endl;

    ///* Typecasting - Converting an expression to another type explicitly(Rare, unless working with older types of code, C, or something that you can't edit easily.)
    // * static_cast<T>(E) is preferred style. Must be allowable
    // * (type)expression is a C style cast. Little more open in what it'll allow, but is less reliable. Also less visible when looking through code.
    // */
    //int totalSales = 50000;
    //int departments = 8;

    //double averageSalesPerDepartment = static_cast<double>(totalSales) / departments;
    //// int truncatedValue = floatValue; // Cannot convert float to int. Won't throw an error, but will give warning. Was allowed in early C days.
    //int truncatedValue2 = static_cast<int>(floatValue);

    //double averageDepartmentSales = totalSales / (double)departments;

    ///* std::string someString = "Hello";
    //int someStringNumber = static_cast<int>(someString); IMPOSSIBLE. Returns compiler error.
    // */

    ///* Math Functions (C++ has no math functions. Must use C stype. #include <cmath>
    // * pow(x, y) => x to the y power. Should be an intiger without decimals.
    // * sqrt(x) => square root of x
    // * exp(x) => Exponential
    // * log(x) => log of x, log(exp(x)) = x;
    // * sin(x), cos(x), tan(x), cot(x), sec(x), csc(x)
    // * abs(x) => Positive value of x. Used to eliminate numbers.
    // * ceil(x) => Smallest possible int value >x
    // * floor(x) => largest possible int value <= 
    // * trunc(xValue) => Truncates value. Rounds towards 0, no matter if the decimal is larger than 5.
    // * round(xValue) => Rounds to nearest value
    // */

    //double xValue = 45.6;
    //double mathResult;

    //std::cout << pow(xValue, 2) << std::endl;
    //std::cout << sqrt(xValue);
    //std::cout << exp(2); // e nth power, e = 2.718
    //std::cout << log(5.4); // root of e
    //std::cout << abs(-45); // Positive X = 45
    //std::cout << ceil(xValue);
    //std::cout << floor(xValue);
    //std::cout << trunc(xValue);
    //std::cout << round(xValue);

    ///* Formatted Output #include <iomanip>
    // */
    //std::cout << 4.657373776573 << std::endl;
    //std::cout << 5.67e3 << std::endl;

    /* Create a table
     * Manipulator | Behavior | Persist
     * ----------------------------------
     * setw(i) | Pads the value to i | No
     * left | Left justifies | Yes
     * right | Right justifies (default) | Yes
     * fixed | Forces fixed point notation | Yes
     * setprecision(i) | Sets precision of floats to total digits if not, and decimals if fixed| Yes
     * setfill(c) | Chracter to pad with | Yes
     */
    cout << left << setw(8) << "Student" << setw(6) << "Grade " << "Letter " << endl;
    cout << setw(20) << setfill('-') << "" << setfill(' ') << endl;
    cout << fixed << setprecision(2);
    cout << setw(8) << "Bob" << setw(6) << 95.67  << setw(6) << "A" << endl;
    cout << setw(8) << "Sue" << setw(6) << 98.543 << setw(6) << "A" << endl;
    cout << setw(8) << "Jim" << setw(6) << 84.567 << setw(6) << "B" << endl;
    cout << setw(8) << "Jan" << setw(6) << 78.987 << setw(6) << "C" << endl;



}