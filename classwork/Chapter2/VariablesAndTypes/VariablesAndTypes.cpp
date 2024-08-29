// VariablesAndTypes
// Jonah Shulske
// Fall 2024
// 8/26/24

#include <iostream>


int main() //Entry Point to program
{
    // << called "Stream Operators"  cout << value
    /*Syntax starts off with Capital S (Single Statement) - Does Something, always have value. Capital E (Single Expression) - Calculate Value, never have value. S|E means Statement or Expression.
    S * (Zero or More Statements). E+ (One or More Expressions).
    T (Type). [s] means Optional.*/ 

    std::cout << "Hello World" << std::endl;
    std::cout << "Hello" << " " << "World" << std::endl;
    std::cout << "Hello";
    std::cout << " ";
    std::cout << "World" << std::endl;
   
    /* \n is "Escape Sequence". Only valid in string literals. Adds special meaning to language. All start with a Slash. Adds new line. Each ::cout should end with an \n. 
     * \t is a horizontal tab. Replaces it with spaces. 
     * \" adds double quotes to string literal.*/

    std::cout << "Hello \tWorld\n";

    std::cout << "Hello \"Jonah\"\n";

    /*File Paths
     \\ Will print out \ */ 
    std::cout << "C:\\Windows\\Temp\n";
    // std::cout << R"C:\Windows\Temp"; is used on newer versions of C++ to skip escape sequences. Not available for us.

    /* Variables - Named memory location to store data. 
     * Declaration - Tells compiler a variable exists. 
     * Scope - Lifetime of a variable/identifier. Point of declaration to end of the block. 
     * Assignment Expression 
     * May declare multiple variables in one line. */

    int length;
    length = 0;
    int releaseYear = 2005;
    int rating, stars;
    rating = 4;
    stars = 5;

    std::cout << length << "\n";
    std::cout << releaseYear << "\n";
    std::cout << "We rate this movie " << rating << " out of " << stars << " stars! \n";




