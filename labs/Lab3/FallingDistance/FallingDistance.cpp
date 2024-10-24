/* FallingDistance
 * Jonah Shulske
 * COSC-1436 Fall 2024
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

/// @brief Prompts user for Fall Time
int FallTimePrompt()
{
    int fallTime;

    std::cout << "Enter Fall Time in Seconds (1-60): ";
    cin >> fallTime;
    
    while (fallTime < 1 || fallTime > 60)
    {
        std::cout << "ERROR: Fall Time must be between 1-60 seconds." << endl;
        std::cout << "Enter Fall Time in Seconds (1-60): ";
        cin >> fallTime;
    };

    return fallTime;
    std::cout << fallTime;
}

//int ReadInt(string message, int minValue, int maxValue)
//{
//    int value;
//    do 
//    {
//        std::cout << message;
//        cin >> value;
//
//        if (value < minValue || value > maxValue)
//        {
//            std::cout << "ERROR: Value must be between " << minValue << "-" << maxValue << endl;
//        }
//
//    } while (value < minValue || value > maxValue);
//    return value;
//}

//int ReadInt(string message)
//{
//    std::cout << message;
//    int value;
//    cin >> value;
//    return value;
//}

double FallTimeCalculation()
{
    int fallTime;
    double fallTimeMeters = ((9.8 * sqrt(fallTime) / 0.5));

    std::cout << fallTime << endl;
    std::cout << fallTimeMeters << endl;

    return fallTimeMeters;
}

void MetersOrFeet()
{
    bool done = false;
    while (!done)
    {
        char Meters;
        char Feet;

        std::cout << "Do you want to calculate in Meters or Feet? (M/F): ";
        cin >> Meters;
        cin >> Feet;

        switch (Meters, Feet)
        {
            case 'F': Feet = true; done = true; break;
            case 'f': Feet = true; done = true; break;

            case 'M': Meters = true; done = true; break;
            case 'm': Meters = true; done = true; break;

            default:
            {
                std::cout << "ERROR: Enter (M/F) characters only" << endl;
            }

        }

    };
    cin.ignore();

}

//void Table()
//{
//    int fallTime;
//    FallTimeCalculation();
//    std::cout << left << setw(7) << "Seconds" << setw(8) << "Distance" << endl;
//    std::cout << left << setw(20) << setfill('=') << "" << setfill(' ') << endl;
//    for (int secondsIndex = 1; secondsIndex < fallTime, ++secondsIndex;)
//    {
//        while (secondsIndex < fallTime)
//        {
//            std::cout << setw(7) << secondsIndex + 1 << setw(8) << endl;
//
//        };
//    }
//}


int main()
{
    FallTimePrompt();
    FallTimeCalculation();
    MetersOrFeet();
    /*Table();*/
}
