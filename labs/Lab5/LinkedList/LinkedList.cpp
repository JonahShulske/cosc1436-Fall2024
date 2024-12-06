/* Jonah Shulske
 * Lab5
 * COSC-1436 Fall 2024
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum MenuCommand       // Main menu creation
{
    MC_List = 1,
    MC_Add,
    MC_Delete,
    MC_Clear,
    MC_Quit
};

struct Node // Node to be used for values/next
{
    int Value = 0;

    Node* Next = nullptr;
};

struct LinkedList  //Linked list to be used by program
{
    Node* Head = nullptr;
};

Node* AddFunction(Node* &Head)   // Function for adding values to Linked List
{
    cout << "\n";
    Node* userNode = new Node;

    std::cout << "Enter a value: ";
    cin >> userNode->Value;
    cout << "\n";

    if (Head == nullptr)
    {
        Head = userNode;
        return Head;
    }
    else
    {
        Node* endNode = Head;
        while (endNode != nullptr && endNode->Next != nullptr)
        {
            endNode = endNode->Next;
        }
        endNode->Next = userNode;
    }
    return Head;
}

void ListFunction(Node* Head)     // Function for viewing the list
{
    cout << "\n";
    Node* endNode = Head;

    if (endNode == nullptr)
    {
        std::cout << "There are no values to list. Select new option \n " << endl;
        return;
    }

    while (endNode != nullptr && endNode->Next != nullptr)
    {
        endNode = endNode->Next;
        std::cout << endNode->Value << " ";
        cout << "\n" << endl;
    };
}

void DeleteFunction(Node* &Head)     // Function for deleting values from list
{
    cout << "\n";
    int deleteValue;
    Node* Previous = nullptr;
    Node* endNode = Head;

    if (Head == nullptr)
    {
        std::cout << "There are no values to delete. Select new option \n " << endl;

        return;
    }

    std::cout << "Enter value to delete: ";
    cin >> deleteValue;

    while (endNode != nullptr)
    {
        if (endNode->Value == deleteValue)
        {
            if (Previous == nullptr)
            {
                Head = endNode->Next;
            } else
                Previous->Next = endNode->Next;

            delete endNode;
            std::cout << "Value has been removed \n " << endl;
            return;
        }

        Previous = endNode;
        endNode = endNode->Next;
    };
}

void ClearFunction(Node* &Head)     // Function for clearing the entire list
{
    cout << "\n";
    char input;
    std::cout << "Are you sure you want to clear all values> (Y/N): ";   // Confirming to user if they actually want to clear the list
    cin >> input;

    switch (input)
    {
        case 'Y':
        case 'y':
        {
            Node* endNode = Head;

            while (endNode != nullptr)
            {
                Node* Next = endNode->Next;
                delete endNode;
                endNode = Next;
            };

            Head = nullptr;
            std::cout << "All values have been cleared \n " << endl;
        }    break;

        case 'N':
        case 'n':
        {
            std::cout << "Cancelled clearing of Linked List \n " << endl;
        }    break;

        default: std::cout << "ERROR: Bad Input" << endl;
    };

}

void QuitFunction()  // Function for quitting the program itself
{
    cout << "\n";
    char input;
    std::cout << "Are you sure you want to quit? (Y/N): "; // Confirming user actually wants to quit the program
    cin >> input;

    switch (input)
    {
        case 'Y':
        case 'y':
        {
            std::cout << "Quitting Program" << endl;
            exit(0);
        }

        case 'N':
        case 'n':
        {
            std::cout << "Quitting Cancelled \n " << endl;
            break;
        }

        default: std::cout << "ERROR: Bad Input \n " << endl;
    }
}


MenuCommand DisplayMenu()    // Function to display the menu to the user
{
    MenuCommand menuCommand = MenuCommand(0);

    std::cout << "Main Menu" << endl;
    std::cout << left << setw(15) << setfill('-') << "" << setfill(' ') << endl;
    std::cout << "L) ist " << endl;
    std::cout << "A) dd" << endl;
    std::cout << "D) elete " << endl;
    std::cout << "C) lear " << endl;
    std::cout << "Q) uit " << endl;
    std::cout << "Enter Menu Choice: ";

    do
    {
        char input;
        cin >> input;

        switch (input)
        {
            case 'A':
            case 'a': menuCommand = MenuCommand::MC_Add; break;

            case 'L':
            case 'l': menuCommand = MenuCommand::MC_List; break;

            case 'D':
            case 'd': menuCommand = MenuCommand::MC_Delete; break;

            case 'C':
            case 'c': menuCommand = MenuCommand::MC_Clear; break;

            case 'Q':
            case 'q': menuCommand = MenuCommand::MC_Quit; break;

            default: std::cout << "ERROR: Bad Input" << endl;
        };
    } while (menuCommand == 0);

    cin.ignore();

    return menuCommand;
}

void HandleMenu(MenuCommand menuCommand, Node*& Head)   // Function to make sure each other functions will run
{
    switch (menuCommand)   // Makes sure the correct function runs
    {
        case MenuCommand::MC_Add: AddFunction(Head); break;
        case MenuCommand::MC_List: ListFunction(Head); break;
        case MenuCommand::MC_Delete: DeleteFunction(Head); break;
        case MenuCommand::MC_Clear: ClearFunction(Head); break;
        case MenuCommand::MC_Quit: QuitFunction(); break;
    };
}

int main()
{
    Node* Head = new Node();

    while (true)
    {
        MenuCommand menuCommand = DisplayMenu();
        HandleMenu(menuCommand, Head);
    };
}
