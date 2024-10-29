/* Chapter 7 - Pass By Reference
 * 10/23/24 + 10/28/24
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

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
void GradeArrayDemo()
{
    const int maxGrades = 20;
    int grades[maxGrades];
    double dummyValue2 = -1;
    int dummyValue = 0;

    int estimatedMaxArraySize = sizeof(grades) / sizeof(int); // Size of array / size of element. Only works if used on array declared in same function. Unreliable. Doesn't work at runtime
        
    int count = 0;
    for (int index = 0; index < maxGrades; ++index/*, ++count*/)
    {
        std::cout << "Enter a grade: ";
        cin >> grades[index];
        /*grades[index] = 100;*/
        if (grades[index] <= 0)
            break;

        ++count;
    };

    for (int index = 0; index < count; ++index)
    {
        std::cout << grades[index] << endl;

    };

    int indexToChange;
    do 
    {
        std::cout << "Enter the index of the grade to change: ";
        cin >> indexToChange;

    } while (indexToChange < 0 || indexToChange >= maxGrades);

    int newGrade;
    std::cout << "Enter the new grade: ";
    cin >> newGrade;

    grades[indexToChange] = newGrade;
}

void InitArrayDemo() 
{
    const int MaxRates = 100;
    double payRates[MaxRates] = {0}; // Zero Initialized - Tells compiler to generate code to assign value 0 to each of the array's elements.

    /*for (int index = 0; index < MaxRates; ++index)
    {
        payRates[index] = 0;
    };*/
}

int main()
{
    double gradeAverages[100];
    GradeArrayDemo();
    InitArrayDemo();
    



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
