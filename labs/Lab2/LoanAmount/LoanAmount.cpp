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
    int loanAmount;

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

    int paymentAmount;
    std::cout << "Please Enter Payment Amount ($1 - $" << loanAmount << "): ";
    cin >> paymentAmount;


    while (paymentAmount < 1 || paymentAmount > loanAmount)
    {

        if (paymentAmount < 1 || paymentAmount > loanAmount)
        {
            std::cout << "ERROR: Payment must be above $1, but below Loan Amount" << endl;
            std::cout << "Please Enter Payment Amount ($1 - $" << loanAmount << "): ";
            cin >> paymentAmount;
        }
    };

    double newBalance = (loanAmount - paymentAmount) + (loanAmount * interestRate);

    std::cout << loanAmount << endl;
    std::cout << interestRate << endl;
    std::cout << paymentAmount << endl;
    std::cout << newBalance;

   /* std::cout << left << setw(6) << "Month" << setw(8) << "Balance" << setw(8) << "Payment" << setw(9) << "Interest" << setw(11) << "New Balance" << endl;
    std::cout << setw(42) << setfill('-') << "" << setfill(' ') << endl;

    std::cout << setw(6) << "1" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "1" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "1" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "1" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "1" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "1" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "1" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "1" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "1" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "1" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "1" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "1" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    std::cout << setw(6) << "1" << setw(8) << loanAmount << setw(8) << "payment" << setw(9) << interestRate << setw(11) << "new balance" << endl;
    */
}   