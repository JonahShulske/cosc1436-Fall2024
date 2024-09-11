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
    std::getline(std::cin, userName);
    //std::cin >> userName;
   // std::cout << "Hello, " << userName << std::endl;

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

    std::cout << "\n";

    std::cout << userName << std::endl;

    std::cout << "\n";

    double labAverage;
    labAverage = ((labGrade1 + labGrade2 + labGrade3 + labGrade4) / 4);     //Calculation for Lab Grade Average
    std::cout << "Lab #1 Grade: " << labGrade1 << "\n" << "Lab #2 Grade: " << labGrade2 << std::endl;
    std::cout << "Lab #3 Grade: " << labGrade3 << "\n" << "Lab #4 Grade: " << labGrade4 << std::endl;
    std::cout << "Your average lab grade is: "<< labAverage << std::endl;

    std::cout << "\n";

    double examAverage;
    examAverage = ((examGrade1 + examGrade2 + examGrade3) / 3);     //Calculation for Exam Grade Average
    std::cout << "Exam #1 Grade: " << examGrade1 << "\n" << "Exam #2 Grade: " << examGrade2 << std::endl;
    std::cout << "Exam #3 Grade: " << examGrade3 << std::endl;
    std::cout << "Your average exam grade is: " << examAverage;

    /*std::cout << labGrade1 << " " << labGrade2 << " " << labGrade3 << " " << labGrade4 << "\n";
    std::cout << examGrade1 << " " << examGrade2 << " " << examGrade3;*/


}