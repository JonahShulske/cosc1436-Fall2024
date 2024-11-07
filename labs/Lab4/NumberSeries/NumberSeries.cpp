/* NumberSeries
 * Jonah Shulske
 * COSC-1436 Fall 2024
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

void SeriesArray()
{
    const int maxNumberAmount = 100;
    int numberSeriesArray[maxNumberAmount];

    for (int index = 0; index > maxNumberAmount; ++index)
    {
        int numberSeries;
        std::cout << "Enter a value: ";
        cin >> numberSeries;

        if (numberSeries <= 0)
            break;
    }
}

int main()
{
    SeriesArray();

   
}