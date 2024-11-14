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

void SeriesArray()
{
    const int maxSize = 100;
    int numberSeries[100];
    InitializeArray(numberSeries, 100, 0);

    for (int index = 0; index < maxSize; ++index)
    {
        std::cout << "Enter a value: ";
        cin >> numberSeries[index];

        while (numberSeries[index] < 0)
        {
            std::cout << "Error: Values must be greater than or equal to 0" << endl;
            std::cout << "Enter a value: ";
            cin >> numberSeries[index];
        };

        if (numberSeries[index] == 0)
            break;
    }

    for (int index = 0; index < maxSize; ++index)
        std::cout << numberSeries[index] << " ";
       
    cout << endl;
}

void LargestNumber()
{

    cout << "TEST";
    /*int numberSeries[100];

    InitializeArray(numberSeries, 100, 0);

    for (int index = 0; index < 100; ++index)
        std::cout << numberSeries[index] << " ";*/
}
//
//void MeanNumber()
//{
//
//}
//
//void SmallestNumber()
//{
//
//}
//
//void InsertNumber()
//{
//
//}
//
//void ViewNumbers()
//{
//
//}

void HandleMovie(MenuCommand menuCommand)
{
    switch (menuCommand)
    {
        case MenuCommand::MC_Largest: LargestNumber(); break;
        /*case MenuCommand::MC_Add: Add(); break;
        case MenuCommand::MC_Mean: MeanNumber(); break;
        case MenuCommand::MC_Smallest: SmallestNumber(); break;
        case MenuCommand::MC_Insert: InsertNumber(); break;
        case MenuCommand::MC_View: ViewNumber(); break;
        case MenuCommand::MC_Quit: QuitFunction(); break;*/
    };
}


void DisplayMenu(MenuCommand menuCommand)
{
    char input;
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
    cin >> input;

    do
    {
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
};



//void SeriesArray(int values[], int maxSize, int initialValue)
//{
//    for (int index = 0; index < maxSize; ++index)
//    {
//        std::cout << "Enter a value: ";
//        values[index] = initialValue;
//
//        while (values[index] < 0)
//        {
//            std::cout << "ERROR: Value must be greater than or equal to 0" << endl;
//            std::cout << "Enter a value: ";
//            values[index] = initialValue;
//        }
//
//        if (values[index] == 0)
//            break;
//    }
//}




int main()
{
    MenuCommand menuCommand = MenuCommand(0);
    /*MenuCommand menuCommand;*/
    /*InitializeArray(numberSeries, 101, 0);*/
    SeriesArray();
   /* LargestNumber();*/
    DisplayMenu(menuCommand);
    HandleMovie(menuCommand);
}
