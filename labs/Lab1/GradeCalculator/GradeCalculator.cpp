/* Lab 1
 * Jonah Shulske
 * COSC-1436 Fall 2024 
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std; //Only using std:: for when printing lines that the user will be able to see.

int main()
{
    string userName;
    std::cout << "Please enter your name: ";
    getline(cin, userName);

    double labGrade1, labGrade2, labGrade3, labGrade4;
    double examGrade1, examGrade2, examGrade3;      //Creating main grade expressions for user to input
    double partiGrade, finalExam;

    std::cout << "Please enter Lab Grade #1: ";
    cin >> labGrade1;
    std::cout << "Please enter Lab Grade #2: ";
    cin >> labGrade2;                               //Prompting user for Lab Grades
    std::cout << "Please enter Lab Grade #3: ";
    cin >> labGrade3;
    std::cout << "Please enter Lab Grade #4: ";
    cin >> labGrade4;

    cout << "\n";

    std::cout << "Please enter Exam Grade #1: ";
    cin >> examGrade1;
    std::cout << "Please enter Exam Grade #2: ";    //Prompting user for Exam Grades
    cin >> examGrade2;
    std::cout << "Please enter Exam Grade #3: ";
    cin >> examGrade3;

    cout << "\n";

    std::cout << "Please enter Participation Grade: ";     //Prompting user for Participation Grade
    cin >> partiGrade;

    cout << "\n";

    std::cout << "Please enter Final Exam Grade: ";    //Prompting user for Final Exam Grade
    cin >> finalExam;

    cout << "\n";

    double labAverage;
    std::cout << userName << ", " << "your lab grades are: " << endl;
    labAverage = ((labGrade1 + labGrade2 + labGrade3 + labGrade4) / 4);     //Calculation for Lab Grade Average
    std::cout << "Lab #1 Grade: " << labGrade1 << "\n" << "Lab #2 Grade: " << labGrade2 << endl;
    std::cout << "Lab #3 Grade: " << labGrade3 << "\n" << "Lab #4 Grade: " << labGrade4 << endl;

    cout << "\n";

    double examAverage;
    std::cout << userName << ", " << "your exam grades are: " << endl;
    examAverage = ((examGrade1 + examGrade2 + examGrade3) / 3);     //Calculation for Exam Grade Average
    std::cout << "Exam #1 Grade: " << examGrade1 << "\n" << "Exam #2 Grade: " << examGrade2 << endl;
    std::cout << "Exam #3 Grade: " << examGrade3 << endl;

    cout << "\n";

    std::cout << userName << ", " << "your other grades are: " << endl;
    std::cout << "Participation Grade: " << partiGrade << endl;     //Printing the user's other grades
    std::cout << "Final Exam Grade: " << finalExam << endl;

    cout << "\n";

    double labAverageWei, examAverageWei, partiGradeWei, finalExamWei;
    labAverageWei = (labAverage * 0.65);
    examAverageWei = (examAverage * 0.20);      //Calculation for weights on grades
    partiGradeWei = (partiGrade * 0.05);
    finalExamWei = (finalExam * 0.10);

    double classAverage = (labAverageWei + examAverageWei + partiGradeWei + finalExamWei);    //Calculation for Class Average grade
    cout << fixed << setprecision(2);
    std::cout << "Lab Average (65%): " << labAverage << "%" << endl;
    std::cout << "Exam Average (20%): " << examAverage << "%" << endl;
    std::cout << "Participation (5%): " << partiGrade << "%" << endl;
    std::cout << "Final Exam (10%): " << finalExam << "%" << endl;
    std::cout << "Class Average: " << classAverage << "%" << endl;

}