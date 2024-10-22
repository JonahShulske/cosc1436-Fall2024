/* Jonah Shulske
 * 10/21/24
 * Fall 2024
*/


// Function overload  - 2 or more parameters have the same name, but different signatures.
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
/*
 *  Parameter Kind                              |     Arg       |   ID
 *  Input (pass by value)                       |     Any       | (T id)                 Foo(id) Foo(10)
 *  Output                                      |     ---       | ret type               x = foo()
 *  Input Output (pass by reference)            |               | T& id
 */

/// @brief  Reads an interger from console
/// @param message Message to display
/// @return Integral value provided by user
int ReadInt(string message)
{
    std::cout << message;

    int value;
    cin >> value;

    return value;
}

int ReadInt(string message, int minValue, int maxValue)
{
    //Overloading
    return ReadInt(message, minValue, INT32_MAX);
    /*int value;
    do
    {
        value = ReadInt(message);

        if (value < minValue || value > maxValue)
        {
            std::cout << "Value must be between " << minValue << "-" << maxValue << endl;
        }
    } while (value < minValue || value > maxValue);

        return value;*/
}

int ReadInt(string message, int minValue)
{
    int value;
    do
    {
        value = ReadInt(message);

        if (value < minValue)
        {
            std::cout << "Value must be at least " << minValue;
        }
    } while (value < minValue);

    return value;
}

struct Employee
{
    int Id;
    string Name;
    int YearsOfService;
    double PayRate;

};

void Display(Employee employee)
{
    std::cout << employee.Name << endl;
    std::cout << employee.Id << endl;
    std::cout << "Years of Service: " << employee.YearsOfService << endl;
    std::cout << "Pay Rate: " << employee.PayRate << endl;

    employee.YearsOfService *= 2;
}

void GivePayRaise(Employee& employee)
{
    /* If Years > 3, payRate + $5
     * If Years > 5, payRate + $10 
    */

    if (employee.YearsOfService > 3)
    {
        employee.PayRate += 5;
    }
    else if (employee.YearsOfService > 5)
    {
        employee.PayRate += 10;
    }

}

int main()
{
   /* int value = ReadInt("Enter a value between 1-10: ", 1, 10);

    int positive = ReadInt("Enter a positive number: ", 0);

    int anyValue = ReadInt("Enter a number: ");

    int test = ReadInt("A message", 10, 50);*/

    Employee employee;
    employee.Id = 10;
    employee.Name = "Jonah";
    employee.YearsOfService = 4;
    employee.PayRate = 13.5;

    Display(employee);
    GivePayRaise(employee);
    Display(employee);
}
