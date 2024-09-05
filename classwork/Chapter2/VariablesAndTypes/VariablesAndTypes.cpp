// VariablesAndTypes
// Jonah Shulske
// Fall 2024
// 8/26/24 + 8/28/24 + 9/4/24

#include <iostream> //Needs to be a part of your code, or else string will not work. 


// Declares a point as an X and Y value.
struct Point
{
    // Declare local variables. - Fields
    int x;
    int y;

};

struct point2
{
    int x;
    int y;
};

int main() //Entry Point to program
{
    // << called "Stream Operators"  cout << value
    /*Syntax starts off with Capital S (Single Statement) - Does Something, always have value. Capital E (Single Expression) - Calculate Value, never have value. S|E means Statement or Expression.
    S * (Zero or More Statements). E+ (One or More Expressions).
    T (Type). [s] means Optional.*/

    std::cout << "Hello World" << std::endl;
    std::cout << "Hello" << " " << "World" << std::endl;
    std::cout << "Hello";
    std::cout << " ";
    std::cout << "World" << std::endl;

    /* \n is "Escape Sequence". Only valid in string literals. Adds special meaning to language. All start with a Slash. Adds new line. Each ::cout should end with an \n.
     * \t is a horizontal tab. Replaces it with spaces.
     * \" adds double quotes to string literal.*/

    std::cout << "Hello \tWorld\n";

    std::cout << "Hello \"Jonah\"\n";

    /*File Paths
     \\ Will print out \ */
    std::cout << "C:\\Windows\\Temp\n";
    // std::cout << R"C:\Windows\Temp"; is used on newer versions of C++ to skip escape sequences. Not available for us.

    /* Variables - Named memory location to store data. Has type, value, and a name. Can be read and edited. 
     * Literal - Has type, value, and can be only be read. Used for storing values all over your program. Magic values, communication to user, etc.
     * Declaration - Tells compiler a variable exists.
     * Scope - Lifetime of a variable/identifier. Point of declaration to end of the block.
     * Assignment Expression
     * May declare multiple variables in one line.
     * Styling - Name: nouns, Casing: Camel.
     * variable-delc ::= T id [ 'E' ] { ',' id [ '=' E ] }* ';'
     * id rules ::= starts underscore letters. Consists of letters, digits, underscore. Cannot be a keyword.
     */

    int length;
    length = 0;
    int releaseYear = 2005;
    int rating, stars;
    rating = 4, stars = 5;

    std::cout << length << "\n";
    std::cout << releaseYear << "\n";
    std::cout << "We rate this movie " << rating << " out of " << stars << " stars!\n";

    /* Identifiers
     * int _hours, _1stGrade; */
    int examGrade, hoursWorked; // Camel casing makes coding easier on the brain.
    examGrade = 4, hoursWorked = 12;

    /* Types - Defines what kind of data is stored, as well as its range and size. Used for program accuracy.
     * Primatives - Understood by language
     * | Type | Size | Range |
     * |- | - | - |
     * | short | 2 | +-32767 (integral) | Short is rarely used.
     * | int |   4   | +-2 Billion (default)
     * | long |  4   | +-2 Billion |  Used for large values, where applicable.
     * | Unsigned | * | 0-4 Billion. | No negative numbers can be used.
     */
    /* Floats
    * | float | 4 | E+-38 | precison: 5-7 | Not precise enough for even simple programming.
    * | double | 8 | E+-308 | precison: 12-15 (default) |
    */ 
    /* Text
    * | char | 1 | -128 to 127 | character | Only variable in which the compliler decides if it is signed or unsigned. Comes from original C code. Smallest intrigal value.
    * | std::string | * | text | Stores text
    * | bool | 1? | true or false | Takes up 1 bit, but uses up 1 byte.
    */ 
    short s = 1; // Has no modifier like int and long do.
    int i = 0;
    long l = 5L;
    unsigned int ui = 3U;
    unsigned long ul = 3L;
    float pie = 3.14159F; 
    double otherPi = 3.14159;
    double largeNumber = 10E100;
    char c = 'A'; 
    std::string name = "Jonah";
    bool isPassing = true; //true has no defined numerical value in C++. false has value of 0.
    int isOK = 1; // Very old style of coding before bool. Also used in standard C. Don't use this.
    int intSize = sizeof(int); // Compiler will assign value. 

    /* Asignment
    * asn_op ::= V = E
    * Must be type compatable (must be exact same type).
    * rvalue - Any expression that can appear on the right side of an assignment.
    * lvalue - Any expression that can appear on the left side of an assignment. (Only supported on a variable type).
    * E::= id
    * Associativity - Right 
    */ 
    int shapeLength = 10;
    int shapeWidth = 20;
    int shapeArea; 

    shapeArea = shapeLength; // Does not become a statement until ; is added. If no ;, then it is an expression.
    shapeWidth = 10;

    shapeArea = shapeLength = shapeWidth = 20;

    /* Arithmetic Operators
    * + - '*' '/' % (int modulus)
    * arith_op ::= Et op Et
    */
    shapeArea = shapeLength * shapeWidth;
    int remainder = 10 % 3; // 1 
    int result = 10 / 3; // 3 
    double dresult = 10.0 / 3.0; // 3.333

    //unary_op ::= + Et | - Et
    int positiveValue = 10;
    int negativeValue = -positiveValue;

    /* Scope
     * block-statment ::= { S* }
     */
    {
        int newVariable = 10;
    }

    //std:cout << newVariable; is a compiler error, bc the int wasn't declared within this block

    // Variables can be written and read. Literals can only be read, and not able to be written. 

    /* Strings
     * Not a primative.
     * Doesn't work outside of C++. Doesn't work with C either, as it's not a primative.
     * 
     */
    std::string message = "Hello";
    message = message + " World"; // Technically creates a new string, which will waste memory. Mostly for simple projects. Could use message += " World"; instead.
    message = message + " " + name;

    std::string empty; // Has no value assigned, as string already initializes with an empty assignment.
    empty = empty + "Hello";

    /* Combination Operators
     * V op= E likely to only be used with addition and multiplication easily.
     */
    empty += " World"; // += is known as Combination Operator. combo_op ::= arith.op = [ , ] ;
    
    /* C++ is strongly typed. 
     *Must recompile entire code if you want to change the type of something. Expressions typed at point of copulation.
     */

    int number = 10;
    // number = "20"; Works in weakly typed languages like JavaScript. Will give a Compiler Error in any strongly typed language

    /* Type Inferencing (C++11)
     * auto ::= 
     * The type 'auto' was used as a keyword during C++ coding made before 2011
     * Compiler figures it out
     * Only useable in variable decls and a few other places.
     * Must use initializer expression when declaring variable.
     */
    auto payRate = 45.6; // Don't use auto for variable declarations unless you know what you're doing. Can change the type with just one edit.
    // auto payRate = 45; Would turn it into an int instead of a double. 
    // double payRate = 45.6; 
    // payRate = "45.6"; 
    double averagePayRate = 40 / payRate;

    /* Area of a circle = pi*r^2
     * Literals are great, unless you need them everywhere. Constant expressions.
     * Const - Constant Expression - Expression that is calculated at compile time. Primitive. Can only be read, has type, value, and name. 4+5 * 8 = 44
     * Variables are better at being reused, but may be accidentally changed. 
     */
    const double pi = 3.14159;
    double radius = 10;
    double area = pi * radius * radius;
    area = pi * radius * radius;

    /* Structure - Group of related data points. Comes from C
     * Prompt user for a point
     * Cannot use structs with cout
     * Struct variables are undefined
     */
    //int x, y;
    Point pt = {0}; // Zero initializes fields pt.x = 0; pt.y = 0;  member_access ::= E.E
    std::cout << "Enter X value: \n";
    pt.x = 5;
    std::cout << "Enter Y value: \n";
    pt.y = 10;

    std::cout << "(" << pt.x << ", " << pt.y << ")";
    // Strict assignment is value assignment, all fields are copied.
    Point pt2 = pt;
   

}

