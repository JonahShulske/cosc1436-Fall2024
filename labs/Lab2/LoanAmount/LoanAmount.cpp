/* Lab2
 * Jonah Shulske
 * COSC-1436 Fall 2024
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    double loanAmount;

    std::cout << "Please Enter Loan Amount ($1-$1,000): ";
    cin >> loanAmount;

    if (loanAmount > 1000 || loanAmount < 0)
    {
        std::cout << "ERROR: Loan Amount must be between $1-$1,000" << endl;
        std::cout << "Please Enter Loan Amount ($1-$1,000): ";
        cin >> loanAmount;
    }

    double interestRate;

    std::cout << "Please Enter Desired Interest Rate: (1.0%-100.0%): ";
    cin >> interestRate;

    if (interestRate > 100.0 || interestRate < 1.0)
    {
        std::cout << "ERROR: Interest Rate must be between 1.0%-100.0%" << endl;
        std::cout << "Please Enter Desired Interest Rate: (1.0%-100.0%): ";
        cin >> interestRate;
    }

    double paymentAmount;
    std::cout << "Please Enter Payment Amount ($1 - Loan Amount $): ";
    cin >> paymentAmount;

    if (paymentAmount < 1 || paymentAmount > loanAmount)
    {
        std::cout << "ERROR: Payment must be above $1, but below Loan Amount" << endl;
        std::cout << "Please Enter Payment Amount ($1 - Loan Amount $): ";
        cin >> paymentAmount;
    }

    std::cout << loanAmount << endl;
    std::cout << interestRate << endl;
    std::cout << paymentAmount << endl;

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