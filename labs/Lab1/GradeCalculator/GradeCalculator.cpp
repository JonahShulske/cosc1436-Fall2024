/* Lab 1
* Jonah Shulske
* COSC-1436 Fall 2024 
*/

#include <iostream>
#include <string>

int main()
{
    std::string userName;
    std::cout << "Please enter your name: ";
    std::cin >> userName;
    std::cout << "Hello, " << userName << std::endl;

    double labGrade1, labGrade2, labGrade3, labGrade4;
    double examGrade1, examGrade2, examGrade3;

    std::cout << "Please enter Lab Grade #1: ";
    std::cin >> labGrade1;
    std::cout << "Please enter Lab Grade #2: ";
    std::cin >> labGrade2;                          //Prompting user for Lab Grades
    std::cout << "Please enter Lab Grade #3: ";
    std::cin >> labGrade3;
    std::cout << "Please enter Lab Grade #4: ";
    std::cin >> labGrade4;

    std::cout << "\n";

    std::cout << "Please enter Exam Grade #1: ";
    std::cin >> examGrade1;
    std::cout << "Please enter Exam Grade #2: ";    //Prompting user for Exam Grades
    std::cin >> examGrade2;
    std::cout << "Please enter Exam Grade #3: ";
    std::cin >> examGrade3;

    double labAverage;
    labAverage = ((labGrade1 + labGrade2 + labGrade3 + labGrade4) / 4);     //Calculation for Lab Grade Average
    std::cout << labAverage << std::endl;

    double examAverage;
    examAverage = ((examGrade1 + examGrade2 + examGrade3) / 3);     //Calculation for Exam Grade Average
    std::cout << examAverage;

    /*std::cout << labGrade1 << " " << labGrade2 << " " << labGrade3 << " " << labGrade4 << "\n";
    std::cout << examGrade1 << " " << examGrade2 << " " << examGrade3;*/


}