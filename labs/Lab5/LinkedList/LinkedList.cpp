/* Jonah Shulske
 * Lab5
 * COSC-1436 Fall 2024
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

enum MenuCommand
{
    MC_List,
    MC_Add,
    MC_Delete,
    MC_Clear,
    MC_Quit
};
//
//struct Node
//{
//    int value = 0;
//    int Current;
//
//    Node* Next = nullptr;
//};

struct LinkedList
{
    int Current = 0;
    LinkedList* Next = nullptr;
};

LinkedList* AddFunction(LinkedList* Head)
{
    LinkedList* List = new LinkedList;

    for (int index = 0; index < 3; ++index)
    {
        std::cout << "Enter a value: ";
        cin >> List->Current;
    }

    List->Next = Head;
    Head = List;

    return Head;
}

void ListFunction(LinkedList* Head)
{
    for (Head; Head = Head->Next;)
    {
        std::cout << Head->Current << endl;
    }
}

//LinkedList* AddFunction()
//{
//    LinkedList* Head = nullptr;
//    int Current = 0;
//
//    for (int index = 0; index < 3; ++index)
//    {
//        std::cout << "Enter a value: ";
//        cin >> Current;
//    }
//
//    LinkedList* List = new LinkedList;
//    List->Head;
//    List->Current = Current;
//    while (List != nullptr && List->Next != nullptr)
//        List->Next;
//    return Current;
//}

//LinkedList* ListFunction()
//{
//
//}

void DisplayMenu(MenuCommand menuCommand)
{
   
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
}

void HandleMenu(MenuCommand menuCommand)
{
    LinkedList* Head = nullptr;
    switch (menuCommand)
    {
        case MenuCommand::MC_Add: AddFunction(Head); break;
        case MenuCommand::MC_List: ListFunction(Head); break;
        /*case MenuCommand::MC_Delete: DeleteFunction(); break;
        case MenuCommand::MC_Clear: ClearFunction(); break;
        case MenuCommand::MC_Quit: QuitFunction(); break;*/
    };
}

int main()
{
    LinkedList* Head = nullptr;
    MenuCommand menuCommand = (MenuCommand)0;
    DisplayMenu(menuCommand);
    HandleMenu(menuCommand);
    /*AddFunction(Head);
    ListFunction(Head);*/
}