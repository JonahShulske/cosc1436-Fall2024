/* Jonah Shulske
 * Lab5
 * COSC-1436 Fall 2024
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum MenuCommand
{
    MC_List = 1,
    MC_Add,
    MC_Delete,
    MC_Clear,
    MC_Quit
};

struct Node
{
    int Value = 0;

    Node* Next = nullptr;
};

struct LinkedList
{
    Node* Head;
};

Node* AddFunction(Node* Head)
{
    Node* userNode = new Node;

    std::cout << "Enter a value: ";
    cin >> userNode->Value;

    if (Head == nullptr)
        Head = userNode;

    else
    {
        Node* endNode = Head;
        while (endNode != nullptr && endNode->Next != nullptr)
            endNode = endNode->Next;

        endNode->Next = userNode;
    }

    return Head;
}

void ListFunction(Node* Head)
{
    Node* endNode = Head;
    while (endNode != nullptr && endNode->Next != nullptr)
    {
        endNode = endNode->Next;
        std::cout << endNode;
    };
}

void DeleteFunction(Node* Head)
{
    Node* Previous = nullptr;
    Node* endNode = Head;

    std::cout << "Enter value to delete: ";
    cin >> endNode->Value;

    while (endNode != nullptr)
    {
        Previous = endNode;
        endNode = endNode->Next;

        if (endNode != nullptr && endNode->Next != nullptr)
            Head = Head->Next;
    };
}


MenuCommand DisplayMenu()
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

void HandleMenu(MenuCommand menuCommand, Node*& Head)
{
    switch (menuCommand)
    {
        case MenuCommand::MC_Add: AddFunction(Head); break;
        case MenuCommand::MC_List: ListFunction(Head); break;
        case MenuCommand::MC_Delete: DeleteFunction(Head); break;
        /*case MenuCommand::MC_Clear: ClearFunction(); break;
        case MenuCommand::MC_Quit: QuitFunction(); break;*/
    };
}

int main()
{
    Node* Head = nullptr;
   
    while (true)
    {
        MenuCommand menuCommand = DisplayMenu();
        HandleMenu(menuCommand, Head);
    }
    /*AddFunction(Head);
    ListFunction(Head);*/
}