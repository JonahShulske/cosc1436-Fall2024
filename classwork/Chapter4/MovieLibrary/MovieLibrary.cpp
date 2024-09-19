/* Movie Library
 * Jonah Shulske
 * 9/16/24 + 9/18/24
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Movie
{
    // Movie: Title, Actors, Run Length, Description, Genre(s), Director(s), Release Year, MPPA Rating
     
    // Required
    string Title;

    // At least 0 minutes
    int runLength;

    // Optional
    string Description;

    // At least 1900
    int releaseYear;

    bool isClassic;


};

int main()
{
  ///* Relational Operators: relational_up::=     < <= > >= == !=
  // * rel_expr::= Et relop_ Et => boolean
  // */

  //  // int left, right;
  //  string left, right;
  //  std::cout << "Enter a left and right value: ";
  //  cin >> left >> right;

  ///* Mangle the values 
  // * Do not use == equality floating point values, to avoid rounding errors
  // * Except when comparing floating point value to an integral  (f == 45)
  // */

  //  // left = (left * 21) / 21;
  //  // right = (right * 15) / 15; 
  //  // bool areEqual = left = right == 20;
  //  // bool areEqual = left = 20 = right;

  //  /* Tring Comparison for Case Insensitive
  //   * _strcmpi(string1, string2) String Comparison Insensitive
  //   * When using C++ strings, specifiy value as expr.cstr()
  //   * left < right | <0
  //   * left == right | 0
  //   * left > right | <0
  //   */
  // 
  //  cout << left << " ciequal " << right << " = " << _strcmpi(left.c_str(), right.c_str()) << endl;
  //  cout << left << " < " << right << " = " << (left < right) << endl;
  //  cout << left << " <= " << right << " = " << (left <= right) << endl;
  //  cout << left << " > " << right << " = " << (left > right) << endl;
  //  cout << left << " >= " << right << " = " << (left >= right) << endl;
  //  cout << left << " == " << right << " = " << (left == right) << endl;
  //  cout << left << " != " << right << " = " << (left != right) << endl;
  //  cout << endl;


    /* Decision Making - If Statement
     * if-stmt::=
     * elses::stmt=else
     * logical_op::&& AND (Binary operator) Both must be true for && to return true. If one is false, then && returns false
     * logical_op::|| OR  (Binary operator) One or the other can be true/false, and it will return true/false.
     * !Eb will give the opposite of whichever the operator returns
     */

    ////// Add a new movie
    // Create a new movie
    Movie movie; // = {0};

    // Get required title
    std::cout << "Enter a Title: ";
    getline(cin, movie.Title);

    if (movie.Title == "")
    {
        std::cout << "ERROR: Title is Required" << endl; // Executed 0 or 1 time
        std::cout << "Enter a Title: ";
        getline(cin, movie.Title);
    };


    // Get run length, at least 0 minutes
    std::cout << "Enter run length in minutes: ";
    cin >> movie.runLength;

    //if (movie.runLength <= 0)
    //{

    //    // Look at additional things...

    //    if (movie.runLength < 0) 
    //    {
    //        std::cout << "ERROR: Run Length must be at least 0 minutes" << endl;

    //        std::cout << "Enter run length in minutes: ";
    //        cin >> movie.runLength;
    //    }
    //} else  if (movie.runLength >= 1440)
    //{
    //    std::cout << "ERROR: Run Length cannot be over one day long" << endl;

    //    std::cout << "Enter run length in minutes: ";
    //    cin >> movie.runLength;
    //}

    if (movie.runLength < 0 || movie.runLength > 1440)
    {
        std::cout << "Error: Run length must be between 0 - 1440 minutes" << endl;

        std::cout << "Enter run length in minutes: ";
        cin >> movie.runLength;
    }

    // Get release year
    std::cout << "Enter movie release year (1900-2100): ";
    cin >> movie.releaseYear;

    if (movie.releaseYear < 1900 || movie.releaseYear > 2100)
    {
        std::cout << "ERROR: Movie release year must range from the years 1900-2100" << endl;

        std::cout << "Enter movie release year (1900-2100) ";
        cin >> movie.releaseYear;
    }

    /*if (movie.releaseYear < 1900)
    {
        std::cout << "ERROR: movie release year must be after the year 1900" << endl;

        std::cout << "Enter movie release year (1900+): ";
        cin >> movie.releaseYear;
    }*/


    // Get the optional description
    std::cout << "Enter the optional description: ";
    cin.ignore();
    getline(cin, movie.Description);

    // Get Is Classic
    char isClassic;
    std::cout << "Is this a classic? (Y/N) ";
    cin >> isClassic;


    //if (isClassic == 'Y')
    //    movie.isClassic = true;
    //else if (isClassic == 'y')
    //    movie.isClassic = true;
    //else if (isClassic == 'N')
    //    movie.isClassic = false;
    //else if (isClassic == 'n')
    //    movie.isClassic = false;

    if (isClassic == 'Y' || isClassic == 'y')
        movie.isClassic = true;
    else if (isClassic == 'N' || isClassic == 'n')
        movie.isClassic = false;
    else
    {
        std::cout << "ERROR: Enter (Y/N) characters only" << endl;

        std::cout << "Is this a classic? (Y/N) ";
        cin >> isClassic;
    }

    ///*if (isClassic == 'Y')
    //    movie.isClassic = true;
    //if (isClassic == 'y')
    //    movie.isClassic = true;
    //if (isClassic == 'N')
    //    movie.isClassic = false;
    //if (isClassic == 'n')
    //    movie.isClassic = false;*/

    ////// Display movie details

    std::cout << "---------------" << endl;
    std::cout << movie.Title << " (" << movie.releaseYear << ")" << endl;
    std::cout << "Run Length in minutes: " << movie.runLength << endl;
    if (movie.isClassic)
        std::cout << "Is it a Classic? Yes" << endl;
    else
        std::cout << "Is it a Classic? No" << endl;
    if (movie.Description != "")
        std::cout << movie.Description << endl;
    std::cout << "---------------" << endl;
}