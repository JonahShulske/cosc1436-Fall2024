/* Jonah Shulske
 * Chapter 10 - Files
 * 12/2/24
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/* Stream - Series of bytes. cin (Input stream, read only. Bytes already ready) and cout (designed to be written to, Write Only/Output) are both streams
 * Work basically the same, no matter which stream you work with.  
 * ostream - Writing stream only, doesn't support reading
 * istream - Reading stream only, doesn't support writing
 * iostream - Supports both, but doesn't mean it'll actually work.
 * Streams are infinite, they're just a series of bytes with no end. It'll keep reading and writing if any data is around
 * String Stream - Stream backed by a stream. Good for formatting.
 */

/* Files - Always deal with outside resources
 * fstream - Represents a file. Can read and write to it by default, but difficult to do both
 * Things can go wrong, even if code is correct
 */


void WriteFileDemo()
{
    fstream outFile;

    // Open a file for reading and/or writing. What file and what for
    //  C:\\temp\\log.txt   Windows isn't case sensitive
    //  /usr/temp/log       UNIX is case sensitive
    // ios_base :: <enum> (in or out)
    outFile.open("log.txt", ios_base::out | ios_base::app); // Opening a file for writing

    string line;
    std::cout << "Enter the file contents: ";
    while (true)
    {
        getline(cin, line);

        if (line == "Q" || line == "q")
            break;

        // Write to file
        outFile << line << endl;
    }

    /* trunc - Wipes data and will replace it with new input(default)
     * app - append - Opens files, go to end, and add onto what's already there
     * ate - Append by default, however, program can change where it's writing and stomp over what's already there
     * Refered to as "Flags"
     */
}

void ReadFileDemo()
{
    fstream inFile;

    inFile.open("log.txt", ios_base::in);  // Opening file for reading

    while (!inFile.eof())
    {
        string line;
        getline(inFile, line);

        std::cout << line << endl;

    }
}

void Display(fstream& output, string const& message)
{
    output << message;
    std::cout << message;
}

void LogOutputDemo()
{
    fstream logFile;
    logFile.open("Output.txt", ios_base::out | ios_base::app);

    Display(logFile, "Enter your name: \n");
    string Name;
    getline(cin, Name);

    stringstream msg; 

    msg << "Hello, " << Name << endl;
    Display(logFile, msg.str());

    /*Display(logFile, "Hello: ");
    Display(logFile, Name);
    Display(logFile, "\n");*/

   /* std::cout << "Hello: " << Name << endl;*/
}

int main()
{
    /*WriteFileDemo();
    ReadFileDemo();*/

    LogOutputDemo();
}

