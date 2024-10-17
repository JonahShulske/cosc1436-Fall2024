/* Jonah Shulske
 * 10/16/24
 * Forced "demo"
*/

#include <iostream>
#include <string>

using namespace std;

// N! (Multiply every number from 1 to N number)
int Factorial( int number )
{
    int result = 1;
    for (int index = 0; index < number; ++index)
        result = (index + 1);

    return result;
}

/*int PhoneNumber()
{

    int areaCode;
    int prefix;
    int lineNumber;

    std::cout << "Please Enter Area Code: ";
    cin >> areaCode;

    while (areaCode < 100 || areaCode > 999)
    {

        std::cout << "Error: Area Code must have only three digits." << endl;
        std::cout << "Please Enter Area Code: ";
        cin >> areaCode;

    };

    std::cout << "Please Enter Prefix: ";
    cin >> prefix;

    while (prefix < 100 || prefix > 999)
    {

        std::cout << "Error: Prefix must have only three digits." << endl;
        std::cout << "Please Enter Prefix: ";
        cin >> prefix;

    };

    std::cout << "Please Enter Line Number: ";
    cin >> lineNumber;

    while (lineNumber < 1000 || prefix > 9999)
    {

        std::cout << "Error: Line Number must have only four digits." << endl;
        std::cout << "Please Enter Line Number: ";
        cin >> lineNumber;

    };


    cout << "(" << areaCode << ")" << prefix << "-" << lineNumber << endl;

    return areaCode;
    return prefix;
    return lineNumber;
} */

int FactorialTwo(int number)
{
    if(number <= 1)
    {
        return 1;
    }
    return number * FactorialTwo(number - 1);
}

void PreFixPostFixDemo()
{
    int value;
    std::cout << "Enter a value: ";
    cin >> value;

    /* prefix inc : = ++X => X = X + 1
     * postfix inc := X++ => X = X - 1
     * prefix dec := --X => X = X + 1; T
     * postfix dec := X-- => X = X -1; T
    */
    std::cout << value++ << endl;
    std::cout << ++value << endl; 
    std::cout << value-- << endl; 
    std::cout << --value << endl;

}
void DisplayTruthTable()
{
    
    std::cout << " A " << " B " << " && " << " || " <<  endl;

    // Conditional ::= Eb ? Et : Ef
    std::cout << false << false << (false && false ? "true" : "false") << (false || false ? "true" : "false") << endl;
    std::cout << false << true << (false && true ? "true" : "false") << (false || true ? "true" : "false") << endl;
    std::cout << true << false << (true && false ? "true" : "false") << (true || false ? "true" : "false") << endl;
    std::cout << true << true << (true && true ? "true" : "false") << (true || true ? "true" : "false") << endl;

}

bool isDigit(char value)
{

    switch (value)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': return true;
    };
    return false;
}

bool isLetter(char value)
{
    if ((value >= 'A' && value <= 'Z') || (value >= 'a' && value <= 'z'))
        return true;
    else 
        return false;
}

string GetCharacterClass( char value )
{
    /* Identify Char
     * a...z = letter
     * 0...9 = number
     * $ = symbol
    */

    if (isDigit(value))
        return "Digit";
    else if (isLetter(value))
        return "Letter";
    else
        return "Symbol";

}
void SwitchDemo()
{
    do
    {
        char input;
        std::cout << "Enter a character: ";
        cin >> input;

        std::cout << GetCharacterClass(input) << endl;

    }while (true);


}



int main()
{
    /*PhoneNumber();*/

   /* PreFixPostFixDemo();*/

    /*std::cout << Factorial(3) << " " << Factorial2(3) << endl;
    std::cout << Factorial(5) << " " << Factorial2(1) << endl;
    std::cout << Factorial(1) << " " << Factorial2(5) << endl;
   */

   /* DisplayTruthTable();*/

    SwitchDemo();
}