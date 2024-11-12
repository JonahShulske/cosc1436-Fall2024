/* NumberSeries
 * Jonah Shulske
 * COSC-1436 Fall 2024
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

struct NumberSeries
{
    int inputValues;
};

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

//void SeriesArray()
//{
//    const int maxSize = 100;
//    NumberSeries* inputValue[maxSize];
//
//    for (int index = 0; index < maxSize; ++index)
//    {
//        int value;
//        std::cout << "Enter a value: ";
//        cin >> value;
//       /* cin >> inputValue[index];*/
//
//        while (value < 0)
//        {
//            std::cout << "ERROR: Value must be greater than or equal to 0" << endl;
//            std::cout << "Enter a value: ";
//            cin >> value;
//            /*cin >> inputValue[index];*/
//        };
//
//        if (value == 0)
//            break;
//        /*if (inputValue[index] == 0)
//            break;*/
//
//        NumberSeries* valueInput = new NumberSeries;
//        valueInput->inputValues = inputValue;
//        inputValue[index] = valueInput;
//    };
//}

void SeriesArray(int *value, int *size)
{
    int maxSize= 100;

    int* numberArray = new int[maxSize];

    for (int index = 0; index < maxSize; ++index)
    {
        std::cout << "Enter a value: ";
        cin >> numberArray[index];

        while (numberArray[index] < 0)
        {
            std::cout << "ERROR: Value must be greater than or equal to 0" << endl;
            std::cout << "Enter a value: ";
            cin >> numberArray[index];
        }

        if (numberArray[index] == 0)
            break;
    };
}

//void SeriesArray()
//{
//    const int maxSize = 100;
//    NumberSeries* numberSeriesArray[maxSize] = {0};
//
//    int count = 0;
//    for (int index = 0; index < maxSize; ++index)
//    {
//        int numberSeries;
//
//        std::cout << "Enter a value: ";
//        cin >> numberSeriesArray[index];
//
//        while (numberSeriesArray[index] < 0)
//        {
//            std::cout << "ERROR: Value must be greater than or equal to 0" << endl;
//            std::cout << "Enter a value: ";
//            cin >> numberSeriesArray[index];
//        }
//
//        numberSeriesArray[index] = numberSeries;
//
//        if (numberSeriesArray[index] <= 0)
//            break;
//
//        ++count;
//    };
//    for (int index = 0; index < maxSize; ++index)
//        cout << numberSeriesArray[index] << endl;
//}

int LargestNumber()
{
    int largestNumber;
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
    /*SeriesArray();*/
    /*DisplayMenu(menuCommand);*/
}