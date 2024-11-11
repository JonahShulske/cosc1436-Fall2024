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

void SeriesArray()
{
    const int maxNumberAmount = 100;
    int numberSeriesArray[maxNumberAmount];

    int count = 0;
    for (int index = 0; index < maxNumberAmount; ++index)
    {
        std::cout << "Enter a value: ";
        cin >> numberSeriesArray[index];

        while (numberSeriesArray[index] < 0)
        {
            std::cout << "ERROR: Value must be greater than or equal to 0" << endl;
            std::cout << "Enter a value: ";
            cin >> numberSeriesArray[index];
        }

        if (numberSeriesArray[index] <= 0)
            break;

        ++count;
    };
}

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
//        };
//    } while (menuCommand == 0);
//
//    cin.ignore();
//}

int main()
{
    SeriesArray();
    /*DisplayMenu();*/
}