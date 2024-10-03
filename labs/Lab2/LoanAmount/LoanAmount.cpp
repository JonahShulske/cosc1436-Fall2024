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

    std::cout << "Please Enter Loan Amount ($1-$1,000): ";          // Prompting user for desired loan amount
    cin >> loanAmount;

    while (loanAmount < 1 || loanAmount > 1000)
    {

       if (loanAmount < 1 || loanAmount > 1000)                    // Confirming user entered correct data
       {
          std::cout << "ERROR: Loan Amount must be between $1-$1,000" << endl;
          std::cout << "Please Enter Loan Amount ($1-$1,000): ";        
          cin >> loanAmount;
       }

    };

    double interestRate;

    std::cout << "Please Enter Desired Interest Rate: (1.0%-100.0%): ";         // Obtaining user's interest rate on loan.
    cin >> interestRate;

    while (interestRate < 1.0 || interestRate > 100.0)
    {

        if (interestRate > 100.0 || interestRate < 1.0)                         // Checking for correct input
        {
            std::cout << "ERROR: Interest Rate must be between 1.0%-100.0%" << endl;
            std::cout << "Please Enter Desired Interest Rate: (1.0%-100.0%): ";
            cin >> interestRate;
        }
    };

    interestRate = (interestRate / 100);

    double paymentAmount;
    std::cout << "Please Enter Monthly Payment Amount ($0 - $" << loanAmount << "): ";      // User input for monthly loan payment.
    cin >> paymentAmount;


    while (paymentAmount < 0 || paymentAmount > loanAmount)
    {

        if (paymentAmount < 0 || paymentAmount > loanAmount)                                // Input validation for payment amount.
        {
            std::cout << "ERROR: Payment must be between $0 - $" << loanAmount << endl;
            std::cout << "Please Enter Monthly Payment Amount ($0 - $" << loanAmount << "): ";
            cin >> paymentAmount;
        }
    };

    cout << "\n";

    cout << fixed << setprecision(2);
    std::cout << left << setw(6) << "Month" << setw(11) << "Balance" << setw(13) << "Payment" << setw(11) << "Interest" << setw(17) << "New Balance" << endl;                   // Building table for information display
    std::cout << setw(58) << setfill('-') << "" << setfill(' ') << endl;                                                                                                        
    std::cout << setw(6) << "1" << "$ " << setw(9) << loanAmount << "$ " << setw(11) << (paymentAmount * 0) << "$ " << setw(9) << (interestRate * 0) << "$ " << setw(9) << loanAmount << endl;      // Table layout only for month 1

    double newBalance;
    double statementBalance = loanAmount;
    double totalPaid = 0;
    double totalInterest = 0;

    for (int monthIndex = 1; monthIndex < 12; ++monthIndex)
    {
        newBalance = (statementBalance - paymentAmount) + ((statementBalance - paymentAmount) * interestRate); // Calculation for how the user's statement balance is totaled.

        double interestPayment = (statementBalance - paymentAmount) * interestRate; // Calculation for how the interest is accrued.

        cout << fixed << setprecision(2);
        std::cout << setw(6) << monthIndex + 1 << "$ " << setw(9) << statementBalance << "$ " << setw(11) << paymentAmount << "$ " << setw(9) << interestPayment << "$ " << setw(9) << newBalance << endl;  // Table layout for months 2-12


        statementBalance = newBalance;

        totalPaid += paymentAmount;
        totalInterest += interestPayment;
         
        if (statementBalance < paymentAmount)       // Once the statement balance falls under the original payment amount, automatically make it the new payment for that month.
        {
            paymentAmount = statementBalance;
            interestPayment = 0;
        }
    };

    std::cout << left << setw(17) << "Total" << "$ " << setw(11) << totalPaid << "$ " << setw(11) << totalInterest;     // Formatting total paid and interest paid sections.
}   