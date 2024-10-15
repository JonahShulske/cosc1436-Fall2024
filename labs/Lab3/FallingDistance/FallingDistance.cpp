/* FallingDistance
 * Jonah Shulske
 * COSC-1436 Fall 2024
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

//int ReadInt(string message, int minValue, int maxValue)
//{
//    int input;
//    do 
//    {
//        std::cout << message;
//        cin >> input;
//
//        if (input < minValue || input > maxValue)
//        {
//            std::cout << "ERROR: Value must be between " << minValue << " - " << maxValue << endl;
//        }
//
//    } while (minValue < 1 || maxValue > 60);
//    return input;
//}

/// @brief Prompts user for Fall Time
void FallTimePrompt()
{
    /*int fallTime;
    fallTime = ReadInt("Enter Fall Time in Seconds (1-60): ", 1, 60);*/

    int fallTime;
    std::cout << "Enter Fall Time in Seconds (1-60): ";
    cin >> fallTime;
    
    while (fallTime < 1 || fallTime > 60)
    {
        std::cout << "ERROR: Fall Time must be between 1-60 seconds." << endl;
        std::cout << "Enter Fall Time in Seconds (1-60): ";
        cin >> fallTime;
    };

    std::cout << fallTime;
}

/// @brief Calculates Fall Time in Meters
void MeterCalculation()     //      (1/2) * gt^2
{

    //double meterCalculation = (0.5 * (9.8 * sqrt(fallTime));
    double meterCalculation = (0.5 * sqrt(9.8 * fallTime));
    double fallDistanceMeters;

    cout << meterCalculation;

}

int main()
{
    FallTimePrompt()
    MeterCalculation()
}
