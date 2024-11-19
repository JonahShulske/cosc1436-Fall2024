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

/*          ptr to T        |             ptr(p=v           |           Deret(*p=v)
 *             T*                           RW                              RW
 *           T const *                      RW                              RW
 *           const T*                       RW                              RW
 *           T * const                      R                               R
 *         T const * const                  R                               R
 *         const T * const                  R                               R
 */

/* Linked List - Series of value nodes. Replicates an array. Needs to be allocated 
 * struct Node
 * {
 *   int value;
 *   Node* Next;
 * }
 * 
 * Node* root = nullptr;
 * root = new node = > 5;
 * pNode = new node = > 8; 
 * 
 * root -> Next = current -> next; Deletes current
 */

/* Foo (int* ptr) (O x 100)
{
    Foo &Value;         (104)

    ptrH;
    ptr = ptr + 1;

}*/

/* 
 * arr[4] -> ar[I];
 * *(arr + 4) *(arr + I) ;
 */

/*
 * int arr[10] = {4, 5, 6}
 * int index = 1
 * ++(arr[index]),
 * arr [index++] = 5     If inside bracket, it's an int, manipulating whatever's inside. If outside brackets, manipulating whatever's outside.
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

// Pointers can be passed as parameters
//void DisplayIntArray(int arr[], int size)
void DisplayIntArray(int* arr, int size)
{
    for (int index = 0; index < 100; ++index)
        std::cout << arr[index] << " ";
    cout << endl;
}

void ArrayPointerDemo()
{
    int value[100];

    // Array variables are pointers
    int* ptrValue = value;
    

    /* Pointer Arithmetc - Addition and Subtraction Only
     * Value is always multiplied by sizeof(T), so you're referencing a whole element 
     * arr[index = arr + index = (sizeof(T) * index)
     * arr[index] = *(arr + index)
    */
    for (int index = 0; index < 0; ++index)
    {
        /*(ptrValue + (sizeof(int) * index)) = index + 1;*/
        *(ptrValue + index) = index + 1;
    }

   

    /*for (int index = 0; index < 100; ++index)
        value[index] = index + 1;*/

    DisplayIntArray(ptrValue, 100);

    int localVariable = 100;
    DisplayIntArray(&localVariable, 1);
}

void NewArrayDemo()
{
    //double arr[100];

    // Dynamically allocate array at runtime
    int size;
    std::cout << "How many elements: ";
    cin >> size;

    // Array declaration doesn't work at runtime
    // new T -> T*     /// new T[size] -> T*
    // Size must be integral and > 0
    // Make sure you delete this when finished
    double* arr = new double[size];

    // Arrays and pointers are interchangable, so nothing else changes
    for (int index = 0; index < size; ++index)
    {
        std::cout << "Enter a value: ";
        cin >> arr[index];

        if (arr[index] == 0)
            break;
    }
    // Cleanup
    //delete arr; // Incorrect way. Delete only cleans up a single value
    delete[] arr; // Required for arrays
}

void NewArrayDemo2()
{
    while (true)
    {
        NewArrayDemo();

        std::cout << "Keep going? (Y/N): ";

        char choice;
        cin >> choice;

        if (choice == 'N' || choice == 'n')
            break;
    };
}

// Employee is pass by reference, any changes to employee are visile to caller
void InitializeEmployeeByRef(int& employee)
{
    std::cout << "Enter Employee ID: ";
    cin >> employee;
}

// Employee is pass by value (memory address), any changes to employee are visible to caller
void InitializeEmployeeByPointer(int* employee)
{
    if (employee) //employee != nullptr || employee != NULL
    {
        employee++;

       std::cout << "Enter Employee ID: ";
            cin >> *employee;
    }
    
}

void PassByRefVsPointerDemo()
{
    // Employee employee
    int employeeID;

    // Pass by reference - Must pass a variable
    InitializeEmployeeByRef(employeeID);

    // Pass by value - Must pass address of variable
    InitializeEmployeeByPointer(&employeeID);

    //InitializeEmployeeByPointer(nullptr); // Will crash program
}

Employee* CreateEmployee()
{
    Employee* ptrEmployee = new Employee();

    return ptrEmployee;
}

int* FindElement(int values[], int size, int desiredValue)
{
    // Return address of matching element, if any
    for (int index = 0; index < size; ++index)
    {
        if (values[index] == desiredValue)
            return &values[index];
    };

    return nullptr;
}

double g_SomeVariable = 9.18175;

double* GetConstant()
{
    return &g_SomeVariable;
}
// Never do something like this. Can crash program or corrupt memory
//double* DontDoThis()
//{
//    double someValue = 1.2914;
//
//    return &someValue;
//}

void PointerReturnDemo()
{
    /* Pointer as return type. New instance from function
     * RAII - Resource Acquisition is Initialization. If a funcition returns a pointer to you, you are responsible for its lifetime. 
    */
    Employee* pNewEmployee = CreateEmployee();
    delete pNewEmployee;

    // Pointer is to memory that the caller owns
    int values[100] = {0};
    values[50] = 20;
    int* pMatch = FindElement(values, 100, 20);

    // Pointer to global object
    double* pConstant = GetConstant();

    //// Don't do this
    //DontDoThis();
}

// Message is a refrerence to a constant string
// Reference for perf reasons
// const string& message
int ReadInt(string const& message) // For backwards compatibility reasons, const can follow or preceed a type, and it'll work the same.
{
    // Constant, can't modify
    // message = "Bruh; Will not work

    std::cout << message;

    int value;
    cin >> value;

    return value;
}

void ConstantPointersDemo()
{
    /*string message = "Enter a number: ";*/
    int value = ReadInt("Enter a number: ");

    // non-const vs const
    int nonConstValue = 10;
    const int constValue = 20;

    // non-const are readable/writeable
    nonConstValue = 20;

    // const are read only
    /*constValue = 30;*/

    // Pointer can be dereferenced to read/write
    int* pNonConst = &nonConstValue;
    *pNonConst = 40;

    //// Cannot assign a const int pointer to a non-const int pointer. Can add const to someting, cannot take const from something
    //*pNonConst = &constValue;
    //*pNonConst = 50;

    // non-const to const is allowed. Can add const to someting, cannot take const from something
    int const* pConst = &constValue;
    pConst = &nonConstValue;

    nonConstValue = (int)45.6; // C style cast
    nonConstValue = static_cast<int>(45.6); // C++ cast

    // const_cast<T> casts T to eithe const T or T depending on what it is
    pConst = const_cast<int*>(&nonConstValue);
    pNonConst = const_cast<int*>(&constValue);
    *pNonConst = 50;
}

int main()
{
    /*ArrayPointerDemo();*/
    /*StackDemo();
    EmptyDemo();*/
    /*DynamicMemoryDemo();*/
    /*NewArrayDemo();
    NewArrayDemo2();*/
    ConstantPointersDemo();
    
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
