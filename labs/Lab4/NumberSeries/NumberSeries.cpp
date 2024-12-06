/* NumberSeries
 * Jonah Shulske
 * COSC-1436 Fall 2024
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

enum MenuCommand
{
    MC_Add,
    MC_Largest,
    MC_Mean,
    MC_Smallest,
    MC_Insert,
    MC_View,
    MC_Quit,
};


void InitializeArray(int values[], int size, int initialValue)
{
    for (int index = 0; index < size; ++index)
        values[index] = initialValue;
}

int SeriesArray(int values[], int maxSize)
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

void LargestNumber(int values[], int size)
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


int MeanNumber(int values[], int size)
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


void SmallestNumber(int values[], int size)
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

void InsertNumber(int values[], int &size, int maxSize)
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
//
//void ViewNumbers()
//{
//
//}

MenuCommand DisplayMenu()
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

void HandleMenu(MenuCommand menuCommand, int values[], int size)
{
    switch (menuCommand)
    {c
        case MenuCommand::MC_Largest: LargestNumber(values, size); break;
         //case MenuCommand::MC_Add: Add(); break;
         case MenuCommand::MC_Mean: MeanNumber(values, size); break;
         case MenuCommand::MC_Smallest: SmallestNumber(values, size); break;
         case MenuCommand::MC_Insert: InsertNumber(values, size, 100); break;
         /*case MenuCommand::MC_View: ViewNumber(); break;
         case MenuCommand::MC_Quit: QuitFunction(); break;*/
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
        HandleMenu(menuCommand, numberSeries, size);
    }
    return 0;
}
