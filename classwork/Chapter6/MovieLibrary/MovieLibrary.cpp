/* 
 * Movie Library (Chapter 6 Version). Modular Programming
 * Jonah Shulske
 * 10/7/24 + 10/9/24
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
    MC_AddMovie = 1,
    MC_EditMovie,
    MC_DeleteMovie,
    MC_ViewMovie,
};


/* Function Definition - Defines a function and what it does
 * Declaration ::= declares the existence of something and what it is. Used by compiler to recognize use of identifier. No effect on runtime. Must be declared before usage. Used in compiler
 * Definition ::= what it does.  (var defined) (for linker). Used in linker
 * Function Names are verbs representing actions. If you can't make a verb name for a function, you don't need it as a function. 
 * Casing: PascalCasing or camelCasing
 * Every function should have a function headder. 
*/

/*  Global Variables - Do not use unless specifically stated to do as such.
 * 
 */

// void - Means there is no type.
/* _strcmpi(str1, str2) two strings case insensitive for comparision.Creates an int that needs to be translated.
 *  <0 left < right
 *   0 left = right
 *  0> left > right
 */
/* Parameter - Data used inside function
 * parameter-list ::= parameter { , parameter }*
 * parameter ::= T [ id ]
 * Argument - Expression passed to function 
 */

// Global Variables - Don't do this
MenuCommand g_menuCommand = (MenuCommand)0;
Movie g_movie;


void AddMovie()
{
    std::cout << "AddMovie";

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

    g_movie = movie;
}



void EditMovie()
{
    std::cout << "EditMovie";
}

void DeleteMovie()
{
    std::cout << "DeleteMovie";
}

void ViewMovie( Movie movie)
{
    std::cout << "ViewMovie";

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

/// Displays main menu
void DisplayMenu(MenuCommand menuCommand)
{
    ////// Show Menu
    std::cout << "Movie Library" << endl;
    std::cout << "---------------" << endl;
    std::cout << "A)dd Movie" << endl;
    std::cout << "E)dit Movie" << endl;
    std::cout << "D)elete Movie" << endl;
    std::cout << "V)iew Movie" << endl;
    std::cout << "Enter Input: ";

   // MenuCommand menuCommand = (MenuCommand)0;

    do
    {
        char input;
        cin >> input;

        switch (input)
        {
            case 'A':
            case 'a': menuCommand = MenuCommand::MC_AddMovie; break;

            case 'E':
            case 'e': menuCommand = MenuCommand::MC_EditMovie; break;

            case 'D':
            case 'd': menuCommand = MenuCommand::MC_DeleteMovie; break;

            case 'V':
            case 'v': menuCommand = MenuCommand::MC_ViewMovie; break;

            default:  std::cout << "ERROR: Bad input" << endl; break;
        }
    } while (menuCommand == 0);

    cin.ignore();

    // HACK : Don't do this
    g_menuCommand = menuCommand;
}




/// Handles menu selection
/// @param menuCommand The command to handle
void HandleMenu(MenuCommand menuCommand)
{
    switch (menuCommand)
    {
        case MenuCommand::MC_AddMovie: AddMovie(); break;
        case MenuCommand::MC_EditMovie: EditMovie(); break;
        case MenuCommand::MC_DeleteMovie: DeleteMovie(); break;
        case MenuCommand::MC_ViewMovie: ViewMovie(g_movie); break;
    }
}


int main()
{
    do
    {
    // Function Call ::= id ();
    ///// Show Menu
        DisplayMenu(g_menuCommand);

        // Handle Menu Command
        HandleMenu(g_menuCommand);
    } while (true);
}
