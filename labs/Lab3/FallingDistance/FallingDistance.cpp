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
//    int value;
//    std::cout << message;
//    cin >> value;
//
//    return value;
//}

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
}

double DistanceMeters()
{
    int fallTime;
    double fallDistanceMeters = ((9.8 * sqrt(fallTime) / 2));
    /*double fallDistanceFeet = (fallDistanceMeters * 3.28084);*/

    /*std::cout << fallTime << endl;*/

    /*if (done = true)
        std::cout << fallDistanceMeters << endl;
    else
        std::cout << fallDistanceFeet << endl;*/

    cout << fixed << setprecision(2) << fallDistanceMeters << endl;
    return fallDistanceMeters;
   /* return fallDistanceFeet;*/
}

double DistanceFeet()
{
    double fallDistanceMeters = DistanceMeters();
    double fallDistanceFeet = (fallDistanceMeters * 3.28084);

    cout << fixed << setprecision(2) << fallDistanceFeet << endl;

    return fallDistanceFeet;
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

char MetersOrFeet()
{
    char measuringUnit;
    bool done = false;
    while (!done)
    {
        char measuringUnit;

        std::cout << "Do you want to calculate in Meters or Feet? (M/F): ";
        cin >> measuringUnit;
        
        switch (measuringUnit)
        {
            case 'M':
            case 'm': measuringUnit = true; done = true; break;

            case 'F':
            case 'f': measuringUnit = false; done = true; break;

            default:
            {
                std::cout << "ERROR: Enter (M/F) characters only" << endl;
            }

        }
        return measuringUnit;
    };

}



int main()
{
    
    //int fallTime = ReadInt("Enter Fall Time in Seconds (1-60): ", 1, 60);
    int fallTime = FallTimePrompt();
    char measuringUnit = MetersOrFeet();
    double fallDistanceMeters = DistanceMeters();
    double fallDistanceFeet = DistanceFeet();
    
    std::cout << left << setw(7) << "Seconds " << setw(8) << " Distance" << endl;
    std::cout << left << setw(20) << setfill('=') << "" << setfill(' ') << endl;

    /*if (measuringUnit == 'M' || measuringUnit == 'm')*/
    //{
        for (int secondsIndex = 0; secondsIndex < fallTime; ++secondsIndex)
        {
            std::cout << setw(9) << secondsIndex + 1 << setw(8) << fallDistanceMeters << endl;
        }
    //}
   /* else if (measuringUnit == 'F' || measuringUnit == 'f')
    {
        for (int secondsIndex = 0; secondsIndex < fallTime; ++secondsIndex)
        {
            std::cout << setw(9) << secondsIndex + 1 << setw(8) << fallDistanceFeet << endl;
        }
    }*/
   /* Table();*/
}
