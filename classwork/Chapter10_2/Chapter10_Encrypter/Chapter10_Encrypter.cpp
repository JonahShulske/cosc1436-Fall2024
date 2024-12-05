/* Jonah Shulske
 * Chapter 10 - Encrypter Files
 * 12/4/24
 */ 

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string GetFileName(const char* message)
{
    std::cout << message;

    string fileName;
    getline(cin, fileName);

    return fileName;
}

void Encrypt(fstream& input, fstream& output, char key)
{
    /* Caesar Cipher(Additive Cipher) - Not secure, but good enough as an example
     * Value 'x' + key = 'y' as a cipher 
     */ 

    while (!input.eof())
    {
        // Character input
        char ch;
        input.get(ch);

        // Reserts error state of a stream
        if (input.fail())
            input.clear();

        // Encryption
        ch += key;

        // Write out
        output.put(ch);
    };

}

void Decrypt(fstream& input, fstream& output, char key)
{
    /* Caesar Cipher(Additive Cipher) - Not secure, but good enough as an example
     * Value 'x' + key = 'y' as a cipher
     */

    while (!input.eof())
    {
        // Character input
        char ch;
        input.get(ch);

        // Reserts error state of a stream
        if (input.fail())
            input.clear();

        // Decryption
        ch -= key;

        // Write out
        output.put(ch);
    };

}

void GetInputFile(fstream& input)
{
    /* Error checking functions
     * .fail() -> true if failed, otherwise false for last file operation ----- Checks 2 different states. Recoverable
     * .bad() -> true if failed, otherwise false for last file operation  ----- State by itself, states if catastrophic issue
     * .good() -> true if last file operation succeeded or false otherwise
     * .is_open()
     */
    /*if (!inputFile.fail());
        return;*/

    do
    {
        string inputFileName = GetFileName("Enter name/directory of input file: ");

        input.open(inputFileName, ios_base::in);

        if (input.is_open())
            return;

        std::cout << "Error opening file" << endl;
    } while (true);
}

void GetOutputFile(fstream& output)
{
    do
    {
        string outputFileName = GetFileName("Enter name/directory of output file: ");

        output.open(outputFileName, ios_base::out | ios_base::binary | ios_base::trunc);

        if (output.is_open())
            return;

        std::cout << "Error opening file" << endl;

    } while (true);
}

enum Direction
{
    EncryptMode,
    DecryptMode
};

Direction GetDirection()
{
    std::cout << "(E)ncrypt or (D)ecrypt? ";

    char input;
    cin >> input;

    do
    {
        switch (input)
        {
            case 'E':
            case 'e': return Direction::EncryptMode; break;

            case 'D':
            case 'd': return Direction::DecryptMode; break;

            default: std::cout << "Bad input" << endl;
        }
    } while (true);
}

int main()
{
    fstream inputFile;
    GetInputFile(inputFile);

    fstream outputFile;
    GetOutputFile(outputFile);

    Direction mode = GetDirection();
    switch (mode)
    {
        case Direction::EncryptMode: Encrypt(inputFile, outputFile, 56); break;
        case Direction::DecryptMode: Decrypt(inputFile, outputFile, 56); break;
    }
   
    Encrypt(inputFile, outputFile, 56);
}
