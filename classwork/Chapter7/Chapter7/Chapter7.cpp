/* Chapter 7 - Pass By Reference
 * 10/23/24 + 10/28/24 + 10/30/24 + 11/4/24
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
// Maximum size of array is (Size - 1)

 /* 
  * Parameter Kind                               |     Arg       |   ID
  *  Input (pass by value)                       |     Any       | (T id)                 Foo(id) Foo(10)
  *  Output                                      |     ---       | ret type               x = foo()
  *  Input Output (pass by reference)            |               | T& id
  */

//struct Point
//{
//    int x;
//    int y;
//};
//
//struct Rectangle 
//{
//    Point topLeft;
//    Point bottomRight;
//};
//
//void Display(Point point)
//{
//    std::cout << "(" << point.x << "," << point.y << ")";
//}
//
//void Display(Rectangle rect)
//{
//    //std::cout << "(" << rect.topLeft.x << "," << rect.topLeft.y << ")";
//    std::cout << "(";
//    Display(rect.topLeft);
//    std::cout << " ";
//    Display(rect.bottomRight);
//    std::cout << ")" << endl;
//}
//
//void Translate(Rectangle& rect, int offsetX, int offsetY)
//{
//    rect.topLeft.x += offsetX;
//    rect.bottomRight.x += offsetX;
//
//    rect.topLeft.y += offsetY;
//    rect.bottomRight.y += offsetY;
//}
//
//void TestPassByReference()
//{
//    Rectangle rc;
//    rc.topLeft.x = 10;
//    rc.topLeft.y = 20;
//
//    rc.bottomRight.x = 100;
//    rc.bottomRight.y = 75;
//    Display(rc);
//
//    Translate(rc, 5, 10);
//    Display(rc);
//}
//void GradeArrayDemo()
//{
//    const int maxGrades = 20;
//    int grades[maxGrades];
//    double dummyValue2 = -1;
//    int dummyValue = 0;
//
//    int estimatedMaxArraySize = sizeof(grades) / sizeof(int); // Size of array / size of element. Only works if used on array declared in same function. Unreliable. Doesn't work at runtime
//        
//    int count = 0;
//    for (int index = 0; index < maxGrades; ++index/*, ++count*/)
//    {
//        std::cout << "Enter a grade: ";
//        cin >> grades[index];
//        /*grades[index] = 100;*/
//        if (grades[index] <= 0)
//            break;
//
//        ++count;
//    };
//
//    for (int index = 0; index < count; ++index)
//    {
//        std::cout << grades[index] << endl;
//
//    };
//
//    int indexToChange;
//    do 
//    {
//        std::cout << "Enter the index of the grade to change: ";
//        cin >> indexToChange;
//
//    } while (indexToChange < 0 || indexToChange >= maxGrades);
//
//    int newGrade;
//    std::cout << "Enter the new grade: ";
//    cin >> newGrade;
//
//    grades[indexToChange] = newGrade;
//}
//
//void InitArrayDemo() 
//{
//    const int MaxRates = 100;
//    double payRates[MaxRates] = {0}; // Zero Initialized - Tells compiler to generate code to assign value 0 to each of the array's elements.
//
//    /*for (int index = 0; index < MaxRates; ++index)
//    {
//        payRates[index] = 0;
//    };*/
//    
//    /*char name[] = "Bob";*/ // Character array size of 4. Very very old C style code.
//
//    // Initialize days of month
//    // Parallel Arrays - Two arrays with the same value that will line up two sets of values with each other.
//    string monthNames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
//    /*monthNames[0] = "January";
//    monthNames[1] = "February";
//    monthNames[2] = "March";
//    monthNames[3] = "April";
//    monthNames[7] = "August";*/
//    /*int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};*/
//    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // One of the only times you don't need to initialize array size.
//
//    /*daysInMonth[0] = daysInMonth[2] = daysInMonth[4] = daysInMonth[6] = daysInMonth[7] = daysInMonth[9] = daysInMonth[11] = 31;
//    daysInMonth[1] = 28;
//    daysInMonth[3] = daysInMonth[5] = daysInMonth[8] = daysInMonth[10] = 30;*/
//
//    for (int index = 0; index < 12; ++index)
//    {
//        std::cout << monthNames[index] << " has " << daysInMonth[index] << " days " << endl;
//    }
//}
//

/* Function parameters 'T id[]'
 * Cannot put a value/size directly in a parameter. Must always be left off.
 * Size is always needed as paramater
 */
bool AreArraysEqual(int left[], int leftSize, int right[], int rightSize)    // This is called an open array. All array parameters in C++ are open arrays.
{
    if (leftSize != rightSize)
        return false;

    for (int index = 0; index < leftSize; ++index)
        if (left[index] != right[index])
            return false;
        else
            return true;
}

int CopyArray(int left[], int leftSize, int right[], int rightSize)
{
    int size = (leftSize < rightSize) ? leftSize : rightSize;
    for (int index = 0; index < size; ++index)
        left[index] = right[index];

    return size;
}

// Arrays cannot be a return type from function.
void InitializeArray(int values[], int size, int initialValue)
{
    for (int index = 0; index < size; ++index)
        values[index] = initialValue;
}

void UseArrayDemo()
{
    int array1[20] = {0};
    /* For loop for iteraring arrays
     * for (int index = 0; index < 20; ++index)
     *     std::cout << array1[index] << endl;
     */
    /* For range for iterating arrays
     *  Copies lements into temp variable like pass by value parameters
     *  Only works if array is declared in the same scope
     *  Can use T& to allow modifications to array element, like pass by reference parameters
     */
    
    // Pass by value doesn't work when it comes to arrays. Runtime can't copy array, so you can't pass arrays by value. Behaves like pass by reference
    InitializeArray(array1, 20, 2);

    //for (int& value : array1) // Allows you to modify element of array as a For Range loop
    //{
    //    value = value + 1;
    //}   
    /*for (int index = 0; index < 20; ++index)
    {
        array1[index] = (index + 1);
    }*/
    //int index2 = 0;
    //while (index2 < 20)
    //{
    //    array1[index2++] = index2 + 1;
    //  /*  array1[index2] = index2 + 1 ++index2;*/
    //}
    // 
    // For loop for iterating arrays (very long way)

    for (int value : array1) // For Range syntax. Don't use this if you need the index. Cannot modify, as this is only a copy of the array elements.
    {
        std::cout << value << endl;
    }

    int array2[20] = {0};
    int array3[29] = {0};

    // Compare arrays. Relational operators don't work correctly with arrays. Will always return false. You'll have to write code to get C++ to get it to work right.
    std::cout << (array2 == array3) << " " << AreArraysEqual(array2, 20, array3, 20) << endl;

    // Assignment. You cannot assign one array to another. Doesn't make any sense
    //array3 = array2; 
    CopyArray(array3, 20, array2, 20);
}

void DisplayArray(int values[], int size, int valueWidth, int maxCellsPerRow)
{
    for (int index = 0; index < size; ++index)
    {
        std::cout << setw(valueWidth) << values[index] << " ";

       /* if (index > 0 && index % maxCellsPerRow == 0)
            cout << endl;*/

        if ((index + 1) % maxCellsPerRow == 0)
            cout << endl;
    }

    cout << right << endl;

}

/* Multi - D table passed like single - D tables
 * All dimensions other than rows must be fixed at compile time
 * Only single dimensional arrays exist in C+, but an array can be inside another array. Arrays of Arrays are most common style seen in most languages, known as "Rectangular Arrays".
 * Jagged Arrays - Rows are still fixed, but each element is an array, and can be any size needed. Alternative method used in some languages. Very very difficult. C++ only supports it for strings. 
 */
void DisplayTable(int values[][10], int size)
{
    for (int row = 0; row < size; ++row)
        DisplayArray(values[row], 10, 5, 10);
        /*for (int column = 0; column < 10; ++column)*/

}
void TableDemo()
{
    
    // Tables are a 2D Array

    /*int values[] = {1, 2, 3, 4, 5};
    DisplayArray(values, 5, 10, 3);*/

   
    // [rows][columns] - Compile time size for all dimensions
    int multiplicationTable[5][10] = {{1, 2, 3, 4, 5,},
                                     {2, 4, 6, 8, 10}};
   

     /*Initialize variables*/

    // Column major ordering - Colums are enumerated, then rows. Destroys performance if this isn't the way your language compiles rectangular arrays. Don't do this
    /*for (int column = 0; column < 5; ++column)
        for (int row = 0; row < 10; ++row)
            multiplicationTable[row][column] = ((row + 1) * (column + 1));*/

    // Row major ordering - Rows are enumerated, then columns.
    for (int row = 0; row < 5; ++row)
        for (int column = 0; column < 10; ++column)
            multiplicationTable[row][column] = ((row + 1) * (column + 1));

    DisplayTable(multiplicationTable, 5);

    ////Display Table
    //for (int row = 0; row < 5; ++row)
    //{
    //    for (int column = 0; column < 10; ++column)
    //        std::cout << setw(5) << multiplicationTable[row][column];
    //    cout << endl;
    //};
}

  

int main()
{
    double gradeAverages[100];
   /* GradeArrayDemo();
    InitArrayDemo();*/
   /* UseArrayDemo();*/
    TableDemo();



    /* Array - set of related data
     * Used when you need to store more than one value of a type. Indiviual values called elements. Index starts at 0
     * Syntax known as "Array access operator"
     * Elements are same type
     */

   

    //const int MaxStudents = 100;
    //string students[MaxStudents]; // Must have int value and be compile time complicit

    //// Store roster of students
    //// When using for loop, use = 0 to < N
    //for (int index = 0; index < MaxStudents; ++index)
    //{
    //    string student;
    //    std::cout << "Enter student name: ";
    //    getline(cin, student);
    //    if (student == "")
    //        break;

    //    /* Student index at 0, first element
    //     * students sub 0
    //     */
    //    students[index] = student;
    //};

    //// Print roster
    //for (int index = 0; index < MaxStudents; ++index)
    //{
    //    if (students[index] != "")
    //        std::cout << students[index] << endl;
    //};

}
