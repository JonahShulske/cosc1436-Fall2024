/* Jonah Shulske
 * Chapter 9, Strings
 * 11/18/24 + 11/20/24
 */

// If #include header file name starts with a C, it's defined by C
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cctype> // Char type functions from C. C++ doesn't have character functions
//#include <cwctype> // Wide character types. Don't generally need to put this
//#include <cwchar>

using namespace std;

/* EBCDIC 'A' - Used by IBM
 * ASCI - American Standard Character Interface for Exchange - Defined the idea of a character. Character takes up 1bt 0-255. Limited to 7 bits, but 7th bit isn't used. 0-128.
 * Character set - Mapping of numbers to characters/symbols. Numbering scheme. ASCI - 65 maps to 'A'. 97 - maps to 'a'. 51/57 - maps to '0'. 656667 (ABC)
 * Formal Standard = ANSI - 1bt, 0-255. What C++ stores characters with.
 * MBSC - Multibyte Character Set. 1-4bts. 4bts can store 4B characters. First 255 were ANSI characters. Maps and supports programming in almost any language. Requires compiler option. char8_t
 * C++ uses char type for characters. Hello would take up 5bts in ANSI, and 5-20bts in MBSC. Would have to read first char and determine if it's an MBSC.
 * Code page - Number that says for character ' ', this is the byte sequence it takes. Mapping of characters to their byte equivalent, and each code page could have a different mapping.
 * UNICODE - 2 bytes. Hello is 10 bytes. Localization problem solved. Back to typing the ANSI way, but with 2bt characters. For 30+ years, everything is UNICODE now. Maps all ANSI characters to UNICODE. wchar_t (wide char) 2-4 bytes if programming for whole world. char if USA Enlgish only
 * UTF-8, UTF-16 (UNICODE), UTF-32 (4bts), not supported by Windows.
 * Standard for C++ is char16_t
 * GCC uses char32_t
 */

bool IsIdentifier(char input)
{
    return isalnum(input) || input == '_';
}


bool IsIntegral(string const& value)
{
   /* for (int index = 0; index < value.length(); ++index)
        value[index];*/

    for (char ch : value)
        if (!isdigit(ch))
            return false;

    return true;
}

bool IsValidIdentifier(string const& value)
{
    for (char ch: value)
        if (!isalnum(ch) && ch != '_')
            return false;

    return true;
}

void StringDemo()
{
    while (true)
    {
        string input;
        std::cout << "Emter a value: ";
        cin >> input;

        std::cout << "Integer = " << IsIntegral(input) << endl;
        std::cout << "Identifier = " << IsValidIdentifier(input) << endl;
    }
}

void CharDemo()
{
    while (true)
    {
        char input;
        std::cout << "Enter a character: ";
        cin >> input;

        //// Classification ::= int func (int). C didn't have boolean, had to use an int
        //std::cout << setw(4) << "Alpha" << setw(4)endl;
        //std::cout << setw(50) << setfill('-') << "" << endl;
        //std::cout << setfill(' ');

        // isalpha - true if letter, false otherwise
        // isdigit - true if digit, false otherwise
        std::cout << "Alpha = " << (isalpha(input) ? 'Y' : 'N') << endl;
        std::cout << "Digit = " << (isdigit(input) ? 'Y' : 'N') << endl;
        std::cout << "Letter/Digit " << (isalnum(input) ? 'Y' : 'N') << endl;
        std::cout << "lower = " << (islower(input) ? 'Y' : 'N') << endl;
        std::cout << "UPPER= " << (isupper(input) ? 'Y' : 'N') << endl;
        std::cout << "Space = " << (isspace(input) ? 'Y' : 'N') << endl;
        std::cout << "Id = " << (IsIdentifier(input) ? 'Y' : 'N') << endl;

        //Conversion ::=int func (int)
        std::cout << "Lower = " << tolower(input) << endl;
        std::cout << "Upper = " << toupper(input) << endl;
    };
}

void WideCharDemo() // UNICODE version
{
    while (true)
    {
        wchar_t input;
        std::cout << "Enter a character: ";
        wcin >> input; // wcin is wide char version of cin

        //// Classification ::= int func (int). C didn't have boolean, had to use an int
        //std::cout << setw(4) << "Alpha" << setw(4)endl;
        //std::cout << setw(50) << setfill('-') << "" << endl;
        //std::cout << setfill(' ');

        // isalpha - true if letter, false otherwise
        // isdigit - true if digit, false otherwise
        std::cout << "Alpha = " << (iswalpha(input) ? 'Y' : 'N') << endl;
        std::cout << "Digit = " << (iswdigit(input) ? 'Y' : 'N') << endl;
        std::cout << "Letter/Digit " << (iswalnum(input) ? 'Y' : 'N') << endl;
        std::cout << "lower = " << (iswlower(input) ? 'Y' : 'N') << endl;
        std::cout << "UPPER= " << (iswupper(input) ? 'Y' : 'N') << endl;
        std::cout << "Space = " << (iswspace(input) ? 'Y' : 'N') << endl;
        /*std::cout << "Id = " << (IsIdentifier(input) ? 'Y' : 'N') << endl;*/

        //Conversion ::=int func (int). Doesn't work in every language
        std::cout << "Lower = " << towlower(input) << endl;
        std::cout << "Upper = " << towupper(input) << endl;
    };
}

/* "C" Strings/Null Terminated Strings - Character array            |H|E|L|L|O|\0| Every string must end in 0 (null) This string takes up 6 bytes, as each character is 1 byte.
 * Don't have to pass around size.  
 * |H|E|L|L|O|\0| ---> |H|E|L|L|O|_|W|O|R|L|D|\0| Find the null and replace it. 
 * |H|E|L|L|O|_|W|O|R|L|D|\0| ----> |H|E|L|L|O|\0| Place null before what you want to ignore
 * C++ strings only work in C++
 * char* is C String
 * #include <cstring>
 * _s at the end means it's the "secure" version of an unsafe feature
 */
void CStringDemo()
{
   const char* name = "Bob"; //char* by itself won't work
   /*char nameArray[] = "Bob";*/

   const int maximumName = 101; // Always account for the null
   char buffer[maximumName] = {0}; // Blank array

   char firstName[maximumName] = {0};
   std::cout << "Enter your first name: ";
   cin >> firstName;

   //// Takes a string and determines character length and returns it. strlen(char*) size_t ::=
   //int length = strlen(buffer);
   //buffer[length++] = ' ';

   char lastName[maximumName] = {0};
   std::cout << "Enter your last name: ";
   cin >> lastName;

   char fullName[maximumName + maximumName] = {0};

   //// strcpy(char*, const char*) Target is always left string, since it's going to be overwritten. Not a safe function, but it works. Only use if string will NEVER be bigger than destination
   //strcpy(fullName, firstName); 

   //// strncpy(char*, const char, type) - Much safer. Allows you to have a ceiling on how many characters may be written
   strncpy_s(fullName, firstName, maximumName);

   //// strcat(char* , const char*) 
   strcat_s(fullName, " ");

   // Same as strcat, but with max character limit
   strncat_s(fullName, lastName, maximumName);

   /*std::cout << fullName << endl;*/

  ///* cin >> &buffer[length];*/
  // std::cout << buffer << endl;

   // Comparison
   /* strcmp(const char*, const char) int
    * <0    L < R
    * =0    L = R
    * >0    L > R
    */
   
   //// Not case insensitive
   //if (strcmp(firstName, lastName) == 0) //if (!strcmp(firstName, lastName))
   //    std::cout << lastName << endl;
   //else
   //    std::cout << fullName << endl;

   if (_stricmp(firstName, lastName) == 0)
       std::cout << lastName << endl;
   else
       std::cout << fullName << endl;

   // Find in string
   char productName[] = "Microsoft Windows 11";
   char operatingSystem[] = "Windows";

   // strstr(const char*, const char*) cc* - Return type depends on what you're searching for
   char* pPos = strstr(productName, operatingSystem);

   if (pPos != nullptr)
       std::cout << pPos << endl;
}

void NumberStringDemo()
{
    while (true)
    {
        char buffer[100] = {0};

        std::cout << "Enter a number: ";
        cin >> buffer;

        /*bool isNumber = IsIntegral()*/ // Can't use in C

        // Conversion
        // atoi(const char*) int :: Converts string to int. ANSI to Int
        // atol converts to long
        // atof converts to double (floating point)
        int value = atoi(buffer);

        std::cout << "Value as int = " << value << endl;
    };
}

void CPlusPlusStringDemo()
{
   /* char firstName[maximumName] = {0};*/
    string firstName;
    std::cout << "Enter your first name: ";
    cin >> firstName;

    /*char lastName[maximumName] = {0};*/
    string lastName;
    std::cout << "Enter your last name: ";
    cin >> lastName;

    /*char fullName[maximumName + maximumName] = {0};*/
    string fullName;

    
    /*strncpy_s(fullName, firstName, maximumName);*/
    fullName = firstName;
  /*  strcat_s(fullName, " ");*/
    fullName += " ";
    /*strncat_s(fullName, lastName, maximumName);*/
    /*fullName += lastName;*/
    fullName.append(lastName);      // str.append(const char*)

    string middleName;
    std::cout << "Enter middle name: ";
    cin >> middleName;

    // Insert middle name
    int index = fullName.find(" ");
    fullName.insert(index, middleName);     // str.insert(index, const char*)

    std::cout << fullName << endl;

    // Get last name
    string onlyLastName = fullName.substr(index + 1); // str.substr(index + [count])

    std::cout << onlyLastName;

    // Misc
    const char* pCString = fullName.c_str();    // Converts C++ string to a C string, pointer to underlying buffer. Not guaranteed, and returns a constant, so you can't modify it. Non-stable pointer
    int length = fullName.length();     // Length of string in characters
    bool isEmpty = fullName.empty();    // Is there a string?
    fullName.clear(); // Empties the string.    Easier to just do fullName = "";
}



int main()
{
    /*CharDemo();
    StringDemo();*/
    /*WideCharDemo();*/
    /*CStringDemo();*/
    /*NumberStringDemo();*/
    CPlusPlusStringDemo();
}
