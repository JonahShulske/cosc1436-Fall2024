/* Jonah Shulske
 * COSC-1436
 * Fall 2024 */

// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

// - Single Line Comment, ignores everything to end of line
/* Muli Line Comment
 * Ignores everything until the next */
// If there is a special meaning to the language, the term will be blue. Keyword.
// If there is a turquoise, magenta/orange, or light blue, it's another type of keyword.
// " " Double Quotes are used for strings.
// Semi-Colon, Commas, etc. Are used for syntax.
// C++ compiles its code, so it runs from top to bottom. You are also able to put blanks in 2 lines of code, it shouldn't throw an eror.
/* Indents, spaces, and blanks are mostly just for readablity.Try to use a consistant style of code when writing.
 * Indent when writing a new block of code. Language is also case-sensitive. Cannot use arbitrary casing.
 */ 

#include <iostream>

int main()
{
    std::string name;
    std::cout << "Enter Name: ";
    std::cin >> name;

    std::cout << "Hello, " << name << "!" << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

