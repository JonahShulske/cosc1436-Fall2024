/* Lab2
 * Jonah Shulske
 * COSC-1436 Fall 2024
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>


//struct Bank
//{
//    // Loan Amount
//    int loanAmount;
//
//    // Interest Rate
//    double interestRate;
//
//    // Payment Amount
//    double paymentAmount;
//
//};

using namespace std;

int main()
{
    double loanAmount;

    std::cout << "Please Enter Loan Amount ($1-$1,000): ";
    cin >> loanAmount;

    while (loanAmount < 1 || loanAmount > 1000)
    {

       if (loanAmount < 1 || loanAmount > 1000)
       {
          std::cout << "ERROR: Loan Amount must be between $1-$1,000" << endl;
          std::cout << "Please Enter Loan Amount ($1-$1,000): ";
          cin >> loanAmount;
       }

    };

    double interestRate;

    std::cout << "Please Enter Desired Interest Rate: (1.0%-100.0%): ";
    cin >> interestRate;

    while (interestRate < 1.0 || interestRate > 100.0)
    {

        if (interestRate > 100.0 || interestRate < 1.0)
        {
            std::cout << "ERROR: Interest Rate must be between 1.0%-100.0%" << endl;
            std::cout << "Please Enter Desired Interest Rate: (1.0%-100.0%): ";
            cin >> interestRate;
        }
    };

    interestRate = (interestRate / 100);

    double paymentAmount;
    std::cout << "Please Enter Monthly Payment Amount ($0 - $" << loanAmount << "): ";
    cin >> paymentAmount;


    while (paymentAmount < 0 || paymentAmount > loanAmount)
    {

        if (paymentAmount < 0 || paymentAmount > loanAmount)
        {
            std::cout << "ERROR: Payment must be between $0 - $" << loanAmount << endl;
            std::cout << "Please Enter Monthly Payment Amount ($0 - $" << loanAmount << "): ";
            cin >> paymentAmount;
        }
    };


    std::cout << loanAmount << endl;
    std::cout << interestRate << endl;
    std::cout << paymentAmount << endl;

    std::cout << left << setw(6) << "Month" << setw(8) << "Balance" << setw(8) << "Payment" << setw(9) << "Interest" << setw(11) << "New Balance" << endl;
    std::cout << setw(42) << setfill('-') << "" << setfill(' ') << endl;
    std::cout << setw(6) << "1" << setw(8) << "$" << loanAmount << setw(8) << "$0.00" << setw(9) << "$0.00" << setw(11) << "$" << loanAmount << endl;

    double newBalance = (loanAmount - paymentAmount) + ((loanAmount - paymentAmount) * interestRate);
    double interestPayment = (loanAmount - paymentAmount) * interestRate;

    for (int monthIndex = 1; monthIndex < 11; ++monthIndex)
    {
        /*while (monthIndex < 12)
        {
            
        };*/

        newBalance = (loanAmount - paymentAmount) + ((loanAmount - paymentAmount) * interestRate);
        double statementBalance = newBalance;

        std::cout << setw(6) << monthIndex + 1 << setw(8) << "$" << statementBalance << setw(8) << "$" << paymentAmount << setw(9) << "$" << interestPayment << setw(11) << "$" << newBalance << endl;

    };

    /*std::cout << setw(6) << "1" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "2" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "3" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "4" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "5" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "6" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "7" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "8" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "9" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "10" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "11" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "12" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "13" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    */
}   