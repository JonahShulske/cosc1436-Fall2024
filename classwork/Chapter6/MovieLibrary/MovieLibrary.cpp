/* 
 * Movie Library (Chapter 6 Version). Modular Programming
 * Jonah Shulske
 * 10/7/24
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/* Modular Programming - Breaking up program into multiple different modules / chunks, so that many can work on it at once.
 * Provides isolation from each section. Black Box - Don't know how or why it works, but it doesn't matter. It's also reuseable.
 * 
 * Subroutines - Wrapper term for functions and procedures
 * Functions - Module that calculates a value. Everything is referred to as a function in C++. Must call to execute.
 * Procedures - Module that does something
 */

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

    string Genre;

};

// Integral data type with named values
enum MenuCommand
{
    AddMovie = 1,
    EditMovie = 2,
    DeleteMovie = 3,
    ViewMovie = 4
};


/* Function Definition - Defines a function and what it does
 * Declaration ::= declares the existence of something and what it is. Used by compiler to recognize use of identifier. No effect on runtime. Must be declared before usage. Used in compiler
 * Definition ::= what it does.  (var defined) (for linker). Used in linker
 * Function Names are verbs representing actions. If you can't make a verb name for a function, you don't need it as a function. 
 * Casing: PascalCasing or camelCasing
 * Every function should have a function headder. 
*/
// void - Means there is no type.


/// Displays main menu
void DisplayMenu()
{
    ////// Show Menu
    std::cout << "Movie Library" << endl;
    std::cout << "---------------" << endl;
    std::cout << "A)dd Movie" << endl;
    std::cout << "E)dit Movie" << endl;
    std::cout << "D)elete Movie" << endl;
    std::cout << "V)iew Movie" << endl;
    std::cout << "Enter Input: ";
}

/// Handles menu selection
void HandleMenu()
{
    //HACK: Fix This
    MenuCommand menuCommand = (MenuCommand)0;
    switch (menuCommand)
    {

        case MenuCommand::AddMovie:
        case MenuCommand::EditMovie:
        case MenuCommand::DeleteMovie:
        case MenuCommand::ViewMovie: std::cout << "Not yet implimented" << endl; break;

    }
}


int main()
{
    // Function Call ::= id ();
    ///// Show Menu
    DisplayMenu();

    MenuCommand menuCommand = (MenuCommand)0;

    do 
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
    } while (menuCommand == 0);

    cin.ignore();

    // Handle Menu Command
    HandleMenu();
    /*switch (menuCommand)
    {

        case MenuCommand::AddMovie:
        case MenuCommand::EditMovie:
        case MenuCommand::DeleteMovie:
        case MenuCommand::ViewMovie: std::cout << "Not yet implimented" << endl;

    }*/


    ////// Add a new movie
    // Create a new movie
    Movie movie; // = {0};

       do
       {
           std::cout << "Enter a Title: ";
           getline(cin, movie.Title);

           if (movie.Title == "")
               std::cout << "ERROR: Title is Required" << endl;
       } while (movie.Title == "");

       // Get run length, at least 0 minutes
    do
    { 
        std::cout << "Enter run length in minutes: ";
        cin >> movie.runLength;


        if (movie.runLength < 0 || movie.runLength > 1440)
        {
            std::cout << "Error: Run length must be between 0 - 1440 minutes" << endl;
        }

    } while (movie.runLength < 0 || movie.runLength > 1440);


    // Get release year
    while (movie.releaseYear < 1900 || movie.releaseYear > 2100)
    {
        std::cout << "Enter movie release year (1900-2100): ";
        cin >> movie.releaseYear;

        if (movie.releaseYear < 1900 || movie.releaseYear > 2100)
        {
            std::cout << "ERROR: Movie release year must range from the years 1900-2100" << endl;

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

    
        switch (isClassic)
        {
            case 'Y': movie.isClassic = true; done = true; break; // Can remove this if wanted, to allow for fallthrough
            case 'y': movie.isClassic = true; done = true; break;

            case 'N': movie.isClassic = false; done = true; break; // Can remove this if wanted, to allow for fallthrough
            case 'n': movie.isClassic = false; done = true; break;

            default:;
            {
                std::cout << "ERROR: Enter (Y/N) characters only" << endl;
            }
        }
    };
    cin.ignore();


    //Get Genre(s)
    for (int genreIndex = 0; genreIndex < 5; ++genreIndex)
    {
        std::cout << "Enter Optional Genre " << (genreIndex + 1) << ": ";

        string genre;
        getline(cin, genre);
        
        if (genre == "")
        {
            break; // Exists loop unconditionally
            continue; // Loops only - Stops the current interation and loops again. 
            movie.Genre += genre + ", ";
        }
    };


    std::cout << "---------------" << endl;
    std::cout << movie.Title << " (" << movie.releaseYear << ")" << endl;
    std::cout << "Run Length in minutes: " << movie.runLength << endl;
    std::cout << "Is it a classic? " << (movie.isClassic ? "Yes" : "No") << endl;   // Shortest version. Eb ? Et : Ef.  Et and Ef must be the exact same type. No coercion.
    if (movie.Genre != "")
        std::cout << "Movie Genre(s): " << movie.Genre << endl;
    if (movie.Description != "")
        std::cout << movie.Description << endl;
    std::cout << "---------------" << endl;



}
