/* FallingDistance
 * Jonah Shulske
 * COSC-1436 Fall 2024
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int ReadInt(string message, int minValue, int maxValue)
{
    int value;
    do 
    {
        std::cout << message;
        cin >> value;

        if (value < minValue || value > maxValue)
        {
            std::cout << "ERROR: Value must be between " << minValue << "-" << maxValue << endl;
        }

    } while (value < minValue || value > maxValue);
    return value;
}

int ReadInt(string message)
{
    std::cout << message;
    int value;
    cin >> value;
    return value;
}

void FallTimeCalculation(string message)
{
    double fallTime = ReadInt(message);
    double fallTimeMeters = (0.5 * (9.8 * sqrt(fallTime)));

    std::cout << fallTime << endl;
    std::cout << fallTimeMeters << endl;
}

void Table(string message)
{
    std::cout << left << setw(7) << "Seconds" << setw(8) << "Distance" << endl;
    std::cout << left << setw(20) << setfill('=') << "" << setfill(' ') << endl;
    for (int secondsIndex; secondsIndex < ReadInt(message), ++secondsIndex)
    {
        std::cout << setw(7) << secondsIndex + 1 << 

    }
}

///// @brief Prompts user for Fall Time
//int FallTimePrompt(int fallTime)
//{
//    /*int fallTime;
//    fallTime = ReadInt("Enter Fall Time in Seconds (1-60): ", 1, 60);*/
//
//    std::cout << "Enter Fall Time in Seconds (1-60): ";
//    cin >> fallTime;
//    
//    while (fallTime < 1 || fallTime > 60)
//    {
//        std::cout << "ERROR: Fall Time must be between 1-60 seconds." << endl;
//        std::cout << "Enter Fall Time in Seconds (1-60): ";
//        cin >> fallTime;
//    };
//
//    return fallTime;
//    std::cout << fallTime;
//}

///// @brief Calculates Fall Time in Meters
//int MeterCalculation(int fallTime)     //      (1/2) * gt^2
//{
//
//    //double meterCalculation = (0.5 * (9.8 * sqrt(fallTime));
//    double meterCalculation = (0.5 * (9.8 * sqrt(fallTime)));
//    double fallDistanceMeters;
//
//    return meterCalculation;
//    cout << meterCalculation;
//    
//}

int main()
{
    int value = ReadInt("Enter Fall Time in Seconds (1-60): ", 1, 60);
    /*FallTimePrompt();
    MeterCalculation();
    */
}
