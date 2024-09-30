/* Lab2
 * Jonah Shulske
 * COSC-1436 Fall 2024
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>


struct Bank
{
    // Loan Amount
    int loanAmount;

    // Interest Rate
    double interestRate;

    // Payment Amount
    double paymentAmount;

};

using namespace std;

int main()
{
    //int loanAmount;

    /*std::cout << "Please Enter Loan Amount ($1-$1,000): ";
    cin >> loanAmount;*/

    Bank bank;

    while (bank.loanAmount < 0 || bank.loanAmount > 1000)
    {
        std::cout << "Please Enter Loan Amount ($1-$1,000): ";
        cin >> bank.loanAmount;

        if (bank.loanAmount < 0 || bank.loanAmount > 1000)
        {
            std::cout << "ERROR: Loan Amount must be between $1-$1,000" << endl;
        }

    };

    /*if (loanAmount > 1000 || loanAmount < 0)
    {
        std::cout << "ERROR: Loan Amount must be between $1-$1,000" << endl;
        std::cout << "Please Enter Loan Amount ($1-$1,000): ";
        cin >> loanAmount;
    }*/

    //double interestRate;

    std::cout << "Please Enter Desired Interest Rate: (1.0%-100.0%): ";
    cin >> bank.interestRate;

    if (bank.interestRate > 100.0 || bank.interestRate < 1.0)
    {
        std::cout << "ERROR: Interest Rate must be between 1.0%-100.0%" << endl;
        std::cout << "Please Enter Desired Interest Rate: (1.0%-100.0%): ";
        cin >> bank.interestRate;
    }

    //int paymentAmount;
    std::cout << "Please Enter Payment Amount ($1 - Loan Amount $): ";
    cin >> bank.paymentAmount;

    bank.interestRate = (bank.interestRate / 100);

    if (bank.paymentAmount < 1 || bank.paymentAmount > bank.loanAmount)
    {
        std::cout << "ERROR: Payment must be above $1, but below Loan Amount" << endl;
        std::cout << "Please Enter Payment Amount ($1 - Loan Amount $): ";
        cin >> bank.paymentAmount;
    }

    double newBalance = (bank.loanAmount - bank.paymentAmount) + (bank.loanAmount * bank.interestRate);

    std::cout << bank.loanAmount << endl;
    std::cout << bank.interestRate << endl;
    std::cout << bank.paymentAmount << endl;
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