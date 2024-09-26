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

    // At least 0 minutes, Less than 1440
    int runLength;

    // Optional
    string Description;

    // At least 1900, Before 2100
    int releaseYear;

    bool isClassic;

};

// Integral data type with named values
enum MenuCommand
{
    //MC_Begin, // Common in operating systems and/or old style coding.
    AddMovie = 1,        // const int MenuCommand::MC_AddMovie = 0;
    EditMovie = 2, 
    DeleteMovie = 3,
    ViewMovie = 4
    //MC_End    // Common in operating systems and/or old style coding.
};

//enum TestEnum
//{
//    AddMovie
//};

//TestEnum testValue = TestEnum::TE_AddMovie;

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

    /* 
     * X++ Prefix incriment - Stores off original value of variable, and returns X++ as original value, and returns X back as value of expression plus 1. (X = 10)     cout << X++ << X    returns: 10 11
     * ++X Postfix incriment - Incriment X by 1, and then returns X as value of original value + 1, returns ++X as value +1.   cout << ++X << X    returns: 12 12
     * X-- Prefix decrease - Stores off original value of variable, and returns X-- as original value, and returns X back as value of expression minus 1
     * --X Postfix decrease - Decrease X by 1, and then returns X as value of original value - 1, returns --X as value -1
    */



    ////// Show Menu
    std::cout << "Movie Library" << endl;
    std::cout << "---------------" << endl;
    std::cout << "A)dd Movie" << endl;
    std::cout << "E)dit Movie" << endl;
    std::cout << "D)elete Movie" << endl;
    std::cout << "V)iew Movie" << endl;
    std::cout << "Enter Input: ";



     //// Get input
    /* While Loop       while (Eb) = > S;
     * Pretest, S executes 0 or more times
     */
    MenuCommand menuCommand = (MenuCommand)0;
    /*bool done = false;
    while (!done)*/
    // while (menuCommand == 0);  CREATES INFINITE LOOP

    while (menuCommand == 0)
    {
        char input;
        cin >> input;

        switch (input)
        {
            case 'A':
            case 'a': menuCommand = MenuCommand::AddMovie; break;

            case 'E':
            case 'e': menuCommand = MenuCommand::EditMovie; break;

            case 'D':
            case 'd': menuCommand = MenuCommand::DeleteMovie; break;

            case 'V':
            case 'v': menuCommand = MenuCommand::ViewMovie; break;

            default:  std::cout << "ERROR: Bad input" << endl; break;
        }
    };
    cin.ignore();

    // int shouldntWork = MenuCommand::MC_AddMovie;
    // menuCommand = (MenuCommand)1;

    // Handle Menu Command
    switch (menuCommand)
    {

        case MenuCommand::AddMovie:
        case MenuCommand::EditMovie:
        case MenuCommand::DeleteMovie:
        case MenuCommand::ViewMovie: std::cout << "Not yet implimented" << endl;

    }


    ////// Add a new movie
    // Create a new movie
    Movie movie; // = {0};

    //   if (movie.Title == "")
    //{
    //    std::cout << "ERROR: Title is Required" << endl; // Executed 0 or 1 time
    //    std::cout << "Enter a Title: ";
    //    getline(cin, movie.Title);
    //};

    // Get required title
       while (movie.Title == "")
       {
           std::cout << "Enter a Title: ";
           getline(cin, movie.Title);

           if (movie.Title == "")
               std::cout << "ERROR: Title is Required" << endl;
       };

       movie.runLength = -1;
    while (movie.runLength < 0 || movie.runLength > 1440)
    { // Get run length, at least 0 minutes
        std::cout << "Enter run length in minutes: ";
        cin >> movie.runLength;


        if (movie.runLength < 0 || movie.runLength > 1440)
        {
            std::cout << "Error: Run length must be between 0 - 1440 minutes" << endl;

            /*std::cout << "Enter run length in minutes: ";
            cin >> movie.runLength;*/
        }

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
        ///
    };


        // Get release year
    while (movie.releaseYear < 1900 || movie.releaseYear > 2100)
    {
        std::cout << "Enter movie release year (1900-2100): ";
        cin >> movie.releaseYear;

        if (movie.releaseYear < 1900 || movie.releaseYear > 2100)
        {
            std::cout << "ERROR: Movie release year must range from the years 1900-2100" << endl;

           /* std::cout << "Enter movie release year (1900-2100) ";
            cin >> movie.releaseYear;*/

        }
    };

    // Get the optional description
    std::cout << "Enter the optional description: ";
    cin.ignore();
    getline(cin, movie.Description);

    // Get Is Classic
    bool done = false;
    while (!done)
    {
        char isClassic;
        std::cout << "Is this a classic? (Y/N) ";
        cin >> isClassic;

          /* Switch(Select) Statemet - Replacement for if - elseif, where same expression compared to multiple values.
          * 1. Must compared a single expression to one or more constant values with equality.
          * 2. Switch expression must be an integral type. Cannot use double, string, boolean, etc.
          * 3. Each case label must be a compile time constant expression.
          * 4. Each case label must be unique.
          */

        switch (isClassic)
        {
            case 'Y': movie.isClassic = true; done = true; break; // Can remove this if wanted, to allow for fallthrough
            case 'y': movie.isClassic = true; done = true; break;

            case 'N': movie.isClassic = false; done = true; break; // Can remove this if wanted, to allow for fallthrough
            case 'n': movie.isClassic = false; done = true; break;

            default:;
            {
                std::cout << "ERROR: Enter (Y/N) characters only" << endl;

                /*std::cout << "Is this a classic? (Y/N) ";
                cin >> isClassic;*/
            }
        }
    };

    std::cout << "---------------" << endl;
    std::cout << movie.Title << " (" << movie.releaseYear << ")" << endl;
    std::cout << "Run Length in minutes: " << movie.runLength << endl;
    std::cout << "Is it a classic? " << (movie.isClassic ? "Yes" : "No") << endl;   // Shortest version. Eb ? Et : Ef.  Et and Ef must be the exact same type. No coercion.
    if (movie.Description != "")
        std::cout << movie.Description << endl;
    std::cout << "---------------" << endl;


    
     /* switch_stmt ::= switch (E) 
     * {
     *    case_stmt;
     * }
     * 
     * case_stmt ::= case Ecc : s;
     * 
     */

    /*if (isClassic == 'Y' || isClassic == 'y')
        movie.isClassic = true;
    else if (isClassic == 'N' || isClassic == 'n')
        movie.isClassic = false;
    else
    {
        std::cout << "ERROR: Enter (Y/N) characters only" << endl;

        std::cout << "Is this a classic? (Y/N) ";
        cin >> isClassic;
    }*/


    ////// Display movie details
    
    // L O N G  V E R S I O N
   /* if (movie.isClassic)
        std::cout << "Is it a Classic? Yes" << endl;
    else
        std::cout << "Is it a Classic? No" << endl;*/
    /*string classicIndicator;
    if (movie.isClassic)
        classicIndicator = "Yes";
    else
        classicIndicator = "No";

    // Better, but still L O N G
    if (movie.isClassic)
        std::cout << "Is it a Classic? " << classicIndicator << endl;
    else
        std::cout << "Is it a Classic? " << classicIndicator << endl;
    */

    // Shorter form, using conditional operator => Eb ? Et : Ef
    /* string classicIndicator = movie.isClassic ? "Yes": "No";
       std::cout << "Is it a classic? " << classicIndicator << endl;
     */



}