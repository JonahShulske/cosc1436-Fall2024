/* FallingDistance
 * Jonah Shulske
 * COSC-1436 Fall 2024
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

/// @brief Prompts user for Fall Time and retrives input
/// @param message Message displaying request for fallTime input
/// @return fallTime integral value entered by user
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

/// @brief Calculates Fall Distance in Meters
/// @param seconds Amount of seconds an object will be falling
/// @return Calculation of fallen meters per second
double DistanceMeters(int seconds)
{
    double fallDistanceMeters = (9.8 * pow(seconds, 2) / 2);

    return fallDistanceMeters;
}

/// @brief Calculates Fall Distance in Feet
/// @param seconds Amount of seconds an object will be falling
/// @return Calculation of fallen feet per second
double DistanceFeet(int seconds)
{
    double fallDistanceMeters = DistanceMeters(seconds);
    double fallDistanceFeet = (fallDistanceMeters * 3.28084);

    return fallDistanceFeet;
}

/// @brief Prompts user for a calculation in Meters or Feet
/// @return User's entry for measurment unit
bool MetersOrFeet()
{
    bool done = false;
    while (!done)
    {
        char measuringUnit;
        std::cout << "Do you want to calculate in Meters or Feet? (M/F): ";
        cin >> measuringUnit;
        
        switch (measuringUnit)
        {
            case 'M': measuringUnit = true; done = true; break;
            case 'm': measuringUnit = true; done = true; break;

            case 'F': measuringUnit = false; done = true; break;
            case 'f': measuringUnit = false; done = true; break;

            default:;
            {
                std::cout << "ERROR: Enter (M/F) characters only" << endl;
            }
            continue;
        }
        return measuringUnit;
    };
    cin.ignore();
}

/// @brief Displays table of all previous information collected
void DisplayTable()
{
    int fallTime = FallTimePrompt();
    bool metersOrFeet = MetersOrFeet();

    std::cout << left << setw(7) << "Seconds " << setw(8) << " Distance" << endl;
    std::cout << left << setw(20) << setfill('=') << "" << setfill(' ') << endl;

    if (metersOrFeet == true)
    {
        for (int secondsIndex = 1; secondsIndex <= fallTime; ++secondsIndex)
        {
            std::cout << setw(9) << secondsIndex << setw(2) << fixed << setprecision(2) << DistanceMeters(secondsIndex) << " m" << endl;

        }
    } else if (metersOrFeet == false)
    {
        for (int secondsIndex = 1; secondsIndex <= fallTime; ++secondsIndex)
        {
            std::cout << setw(9) << secondsIndex << setw(2) << fixed << setprecision(2) << DistanceFeet(secondsIndex) << " ft" << endl;
        }
    }
}

int main()
{
    DisplayTable();
}
