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
    MC_Add = 1,
    MC_Longest,
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
    int numberSeries[100] = {0};
    int initialValue;

    InitializeArray(numberSeries, 100, 0);

    for (int index = 0; index < 100; ++index)
    {
        std::cout << "Enter a value: ";
        numberSeries[100] = initialValue;

        while (numberSeries[index] < 0)
        {
            std::cout << "Error: Values must be greater than or equal to 0" << endl;
            std::cout << "Enter a value: ";
            numberSeries[initialValue];
        };

        if (numberSeries[index] == 0)
            break;
    }

}

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

void LargestNumber()
{
    int numberSeries[100];

    InitializeArray(numberSeries, 100, 0);

    for (int index = 0; index < 100; ++index)
        std::cout << numberSeries[100] << " ";
}
//
//int MeanNumber()
//{
//
//}
//
//int SmallestNumber()
//{
//
//}
//
//int InsertNumber()
//{
//
//}
//
//int ViewNumbers()
//{
//
//}

//void DisplayMenu(MenuCommand menuCommand)
//{
//    std::cout << "Main Menu" << endl;
//    std::cout << left << setw(15) << setfill('-') << "" << setfill(' ') << endl;
//    std::cout << "A) dd " << endl;
//    std::cout << "L) argest " << endl;
//    std::cout << "M) ean " << endl;
//    std::cout << "S) mallest " << endl;
//    std::cout << "I) nsert " << endl;
//    std::cout << "V) iew " << endl;
//    std::cout << "Q) uit " << endl;
//    std::cout << "Enter Menu Choice: ";
//
//    do
//    {
//        char input;
//        cin >> input;
//
//        switch (input)
//        {
//            case 'A':
//            case 'a': menuCommand = MenuCommand::MC_Add; break;
//
//            case 'L':
//            case 'l': menuCommand = MenuCommand::MC_Longest; break;
//
//            case 'M':
//            case 'm': menuCommand = MenuCommand::MC_Mean; break;
//
//            case 'S':
//            case 's': menuCommand = MenuCommand::MC_Smallest; break;
//
//            case 'I':
//            case 'i': menuCommand = MenuCommand::MC_Insert; break;
//
//            case 'V':
//            case 'v': menuCommand = MenuCommand::MC_View; break;
//
//            case 'Q':
//            case 'q': menuCommand = MenuCommand::MC_Quit; break;
//            
//            default: std::cout << "ERROR: Bad Input" << endl; break;
//        };
//    } while (menuCommand == 0);
//
//    cin.ignore();
//}



int main()
{
    
    /*MenuCommand menuCommand;*/
    InitializeArray(numberSeries, 101, 0);
    SeriesArray();
    LargestNumber();
    /*DisplayMenu(menuCommand);*/
}