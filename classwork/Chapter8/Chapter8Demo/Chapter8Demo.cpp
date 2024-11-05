/* Chapter 8 - Pointers
 * Jonah Shulske
 * 11/4/24
 */

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

/* Pointers are ALWAYS a memory address. Always either 4 or 8 bytes long. Value is always an int value. 
 * Pointers Always have 2 data points: Value is always a memory address, value they reference (in memory)
 * Pointers can point to anything that's stored in memory. Can access raw memory
 * Local variable is just a pointer that's being controlled by the call stack and has a name 
 * Memory address - In Windows, code runs from 0 to the very very max (technically 128TB, but nobody has that much) Just an int value
 * 2^10 (1,024) of each memory size to get to the next.
 */

void StackDemo()
{
    double localDouble = 45.6;

    // Declare a pointer to a double
    double* ptrDouble; // Pointer to a value in this memory
}

int main()
{
    StackDemo();
}
