/* NumberSeries
 * Jonah Shulske
 * COSC-1436 Fall 2024
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

enum MenuCommand            // Creation of main menu
{
    MC_Add = 1,
    MC_Largest,
    MC_Mean,
    MC_Smallest,
    MC_Insert,
    MC_View,
    MC_Quit,
};


void InitializeArray(int values[], int size, int initialValue)  // Function to create array for user input
{
    for (int index = 0; index < size; ++index)
        values[index] = initialValue;
}

int SeriesArray(int values[], int maxSize)  // Function to allow for user input for this array
{
    InitializeArray(values, maxSize, 0);

    int count = 0;
    for (int index = 0; index < maxSize; ++index)
    {
        std::cout << "Enter a value: ";
        cin >> values[index];

        while (values[index] < 0)
        {
            std::cout << "Error: Values must be greater than or equal to 0" << endl;
            std::cout << "Enter a value: ";
            cin >> values[index];
        };

        if (values[index] == 0)
            break;

        count++;
    }

    return count;
}

void LargestNumber(int values[], int size)      // Function to find the largest number entered by user in the array
{

    if (size <= 0)
    {
        std::cout << "There are no values in the array" << endl;
        return;
    }

    int Largest = values[0];
    for (int index = 1; index < size; ++index)
    {
        if (values[index] > Largest)
            Largest = values[index];
    }

    std::cout << "The largest number is: " << Largest << endl;

}

int AddNumbers(int values[], int size)      // Function to add all of the user's entered numbers
{
    if (size <= 0)
    {
        std::cout << "There are no values in the array" << endl;
        return 0;
    }

    int sum = 0;

    for (int index = 0; index < size; ++index)
    {
        sum += values[index];
    }

    std::cout << "The sum of your numbers is: " << sum << endl;
    return sum;
}


int MeanNumber(int values[], int size)      // Function to find the mean of the user's entered numbers
{
    if (size <= 0)
    {
        std::cout << "There are no values in the array" << endl;
        return 0;
    }

    int sum = 0;
    for (int index = 0; index < size; ++index)
    {
        sum += values[index];
    }

    std::cout << "The mean of the numbers is : " << (sum / size) << endl;
    return sum / size;
}


void SmallestNumber(int values[], int size)  // Function to find the smallest entered number in the array
{
    if (size <= 0)
    {
        std::cout << "There are no values in the array" << endl;
        return;
    }

    int Smallest = values[0];
    for (int index = 1; index < size; ++index)
    {
        if (values[index] < Smallest)
            Smallest = values[index];
    }

    std::cout << "The smallest number is: " << Smallest << endl;
}

void InsertNumber(int values[], int &size, int maxSize)     // Function to allow user to insert a number into the array
{
    if (size >= maxSize)
    {
        std::cout << "The array is full" << endl;
        return;
    }

    int newValue;
    std::cout << "Enter the value to insert: ";
    cin >> newValue;

    while (newValue < 0)
    {
        std::cout << "Error: Values must be greater than or equal to 0" << endl;
        std::cout << "Enter a value: ";
        cin >> newValue;
    };

    values[size] = newValue;
    size++;

}

void ViewNumbers(int values[], int size)        // Function to display the numbers in the array to user
{
    if (size <= 0)
    {
        std::cout << "There are no values in this array" << endl;
        return;
    }

    std::cout << "The numbers in this array are: ";
    for (int index = 0; index < size; ++index)
    {
        std::cout << values[index] << " ";
    }

    cout << "\n";
}

void QuitFunction()  // Function for quitting the program itself
{
    cout << "\n";
    char input;
    std::cout << "Are you sure you want to quit? (Y/N): "; // Confirming user actually wants to quit the program
    cin >> input;

    switch (input)
    {
        case 'Y':
        case 'y':
        {
            std::cout << "Quitting Program..." << endl;
            exit(0);
        }

        case 'N':
        case 'n':
        {
            std::cout << "Quitting Cancelled \n " << endl;
            break;
        }

        default: std::cout << "ERROR: Bad Input \n " << endl;
    }
}

MenuCommand DisplayMenu()       // Function to display the menu to the user
{
    MenuCommand menuCommand = MenuCommand(0);

    std::cout << "Main Menu" << endl;
    std::cout << left << setw(15) << setfill('-') << "" << setfill(' ') << endl;
    std::cout << "A) dd " << endl;
    std::cout << "L) argest " << endl;
    std::cout << "M) ean " << endl;
    std::cout << "S) mallest " << endl;
    std::cout << "I) nsert " << endl;
    std::cout << "V) iew " << endl;
    std::cout << "Q) uit " << endl;
    std::cout << "Enter Menu Choice: ";

    do
    {
        char input;
        cin >> input;

        switch (input)
        {
            case 'A':
            case 'a': menuCommand = MenuCommand::MC_Add; break;

            case 'L':
            case 'l': menuCommand = MenuCommand::MC_Largest; break;

            case 'M':
            case 'm': menuCommand = MenuCommand::MC_Mean; break;

            case 'S':
            case 's': menuCommand = MenuCommand::MC_Smallest; break;

            case 'I':
            case 'i': menuCommand = MenuCommand::MC_Insert; break;

            case 'V':
            case 'v': menuCommand = MenuCommand::MC_View; break;

            case 'Q':
            case 'q': menuCommand = MenuCommand::MC_Quit; break;

            default: std::cout << "ERROR: Bad Input" << endl; break;
        };
    } while (menuCommand == 0);

    cin.ignore();

    return menuCommand;
}

void HandleMenu(MenuCommand menuCommand, int values[], int &size, int maxSize)      // Function to handle the menu options
{
    switch (menuCommand)
    {
        case MenuCommand::MC_Largest: LargestNumber(values, size); break;
        case MenuCommand::MC_Add: AddNumbers(values, size); break;
        case MenuCommand::MC_Mean: MeanNumber(values, size); break;
        case MenuCommand::MC_Smallest: SmallestNumber(values, size); break;
        case MenuCommand::MC_Insert: InsertNumber(values, size, maxSize); break;
        case MenuCommand::MC_View: ViewNumbers(values, size); break;
        case MenuCommand::MC_Quit: QuitFunction(); break;
    };
}




int main()
{
    const int maxSize = 100;
    int numberSeries[maxSize];
    InitializeArray(numberSeries, maxSize, 0);

    int size = SeriesArray(numberSeries, maxSize);

    while (true)
    {
        MenuCommand menuCommand = DisplayMenu();
        HandleMenu(menuCommand, numberSeries, size, maxSize);
    }
    return 0;
}
