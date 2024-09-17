/* Movie Library
 * Jonah Shulske
 * 9/16/24
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


    ////// Display movie details
    cout << "----------" << endl;
    std::cout << movie.Title << endl;

}