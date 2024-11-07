/* Chapter 8 - Pointers
 * Jonah Shulske
 * 11/4/24 + 11/6/24
 */

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

/* Pointers are ALWAYS a memory address. Always either 4 or 8 bytes long. Value is always an int value. 
 * Pointers Always have 2 data points: Integral value of a pointer is always a memory address, the other value is the actual value stored in the memory (dereferenced)
 * Pointers can point to anything that's stored in memory. Can access raw memory
 * Local variable is just a pointer that's being controlled by the call stack and has a name 
 * Memory address - In Windows, code runs from 0 to the very very max (technically 128TB, but nobody has that much) Just an int value
 * 2^10 (1,024) of each memory size to get to the next.
 * Always initialize a pointer before calling it
 */

/* localDouble = 7 bytes
 * localInt = 3 bytes
 * ptrDouble = &localDouble
 * 
 */

/* 1 byte = 8 bits = 256 | 1 kilobyte = 1,024 bytes |  1 megabyte = 1,024 kb 
 * 1 gigabyte = 1,024 mb | 1 terabyte = 1,024 gb    |  1 penabyte = 1,024 tb
 * 1 exabyte  =  1,024 pb = Largest possible data size currently
*/

void StackDemo()
{
    double localDouble = 45.6;

    // Declare a pointer to a double
    // address-of :: &variable
    // Type of expression is T* where T is the type of the variable
    double* ptrDouble = &localDouble; // Pointer to a value in this memory. Still a local variable. Value remains on CallStack.

    // You can read and write to a pointer value at a memory address
    *ptrDouble = 89.7;

    /* double* != double
     * ptrDouble = 90.6;
     */

    // Type coercion doesn't behave the same with pointers. Pointers require an exact match
    int localInt = 56;
    localDouble = localInt;
   // ptrDouble = &localInt; Needs to be the exact same. Do not use type coercion with pointers; Not allowed

    /* Dereference a pointer
     * dereference-op :: *E
     * Type of expression is T where E is T*. Dereference operator takes a point off the pointer.
     */
    std::cout << ptrDouble << "\n" << *ptrDouble << endl;
    std::cout << (*ptrDouble == localDouble) << endl;
}

void EmptyDemo()
{
    float payRate =123.50;
    
    float* ptrPayRate = nullptr; // C++ reccomended

    //Always initialize (non-preferred approach)
    /*float* ptrPayRate = NULL;*/

    //Always verify pointers before dereferencing
    /*if (ptrPayRate != NULL) Not reccomended*/
    /*if (ptrPayRate != nullptr)
    {
        cout << *ptrPayRate;
        cout << endl;
    }
       */
    //std::cout << payRate << " = ";
    

}

struct Employee
{
    int ID;
    string Name;
};

void DynamicMemoryDemo()
{
    const int MaxEmployees = 100;
    Employee* employees[MaxEmployees] = {0};
    int id = 1000;

    int numberOfEmployees = 0;
    for (int index = 0; index < MaxEmployees; ++index)
    {
        string name;
        std::cout << "Enter Employee name or leave empty to quit: ";
        getline(cin, name);

        if (name == "")
            break;

        // Add to array
        // new-op :: new T; returns T*
        Employee* employee = new Employee;
        //(*employee).ID = ++id; is ugly
        employee->ID = ++id;
        employee->Name = name;
        employees[index] = employee;
        /*++numberOfEmployees;*/
    }

    // Print out employees

    for (int index = 0; index < MaxEmployees; ++index)
    {
        // If done, then abort
        if (employees[index] == nullptr)
            break;

        std::cout << "[" << employees[index]->ID << "] " << employees[index]->Name << endl;
    }

    // Ensure that any memory allocated by 'new' is cleaned up using delete
    // delete-op ::= delete E;

    for (int index = 0; index < MaxEmployees; ++index)
    {
        if (employees[index] == nullptr)
            break;

        // Deletes the memory
        Employee* employee = employees[index];
        delete employees;
        employees[index] = nullptr;  // Always reset to null to avoid issues
        //delete employees[index]; // Will do nothing if the pointer is already set to null
        //employee->ID = 20; // Going to fail

        //delete &index; // Bad things will happen
    };
}

//void DynamicMemoryDemo()
//{
//    const int MaxEmployees = 100;
//    Employee employees[MaxEmployees];
//    int id = 1000;
//
//    int numberOfEmployees = 0;
//    for (int index = 0; index < MaxEmployees; ++index)
//    {
//        string name;
//        std::cout << "Enter Employee name or leave empty to quit: ";
//        getline(cin, name);
//
//        if (name == "")
//            break;
//
//        // add to array
//        employees[index].ID = ++id;
//        employees[index].Name = name;
//        ++numberOfEmployees;
//    }
//
//    // Print out employees
//
//    for (int index = 0; index < MaxEmployees; ++index)
//    {
//        std::cout << "[" << employees[index].ID << "] " << employees[index].Name << endl;
//    }
//}

int main()
{
    /*StackDemo();
    EmptyDemo();*/
    DynamicMemoryDemo();
    
    /*while (true)
    {
        DynamicMemoryDemo();

        char choice;
        std::cout << "Keep Going? (Y/N): ";
        cin >> choice;
        if (choice == 'N' || choice == 'n')
            break;
    };*/
}
