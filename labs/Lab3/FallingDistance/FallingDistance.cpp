/* FallingDistance
 * Jonah Shulske
 * COSC-1436 Fall 2024
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

void FallTimePrompt()
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

    std::cout << fallTime;
}

void MeterCalculation()     //      (1/2) * gt^2
{

    //double meterCalculation = (0.5 * (9.8 * sqrt(fallTime));
    double fallDistanceMeters;




}

int main()
{
    FallTimePrompt();
}
