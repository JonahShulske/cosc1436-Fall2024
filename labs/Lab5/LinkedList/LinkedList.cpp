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

struct Node
{
    int value = 0;

    Node* Next = nullptr;
};

struct LinkedList
{
    Node* Head = nullptr;
};

void AddList()
{
    LinkedList Head, list;
    Node* current = list.Head;
    int Value;

    std::cout << "Enter value to add to list: ";
    cin >> Value;

    while (current != nullptr && current->Next != nullptr)
        current = current->Next;
}

//void DisplayMenu(MenuCommand menuCommand)
//{
//    char input;
//    std::cout << "Main Menu" << endl;
//    std::cout << left << setw(15) << setfill('-') << "" << setfill(' ') << endl;
//    std::cout << "L) ist " << endl;
//    std::cout << "A) dd" << endl;
//    std::cout << "D) elete " << endl;
//    std::cout << "C) lear " << endl;
//    std::cout << "Q) uit " << endl;
//    std::cout << "Enter Menu Choice: ";
//    cin >> input;
//
//    do
//    {
//        switch (input)
//        {
//            case 'A':
//            case 'a': menuCommand = MenuCommand::MC_Add; break;
//
//            case 'L':
//            case 'l': menuCommand = MenuCommand::MC_List; break;
//
//            case 'D':
//            case 'd': menuCommand = MenuCommand::MC_Delete; break;
//
//            case 'C':
//            case 'c': menuCommand = MenuCommand::MC_Clear; break;
//
//            case 'Q':
//            case 'q': menuCommand = MenuCommand::MC_Quit; break;
//
//            default: std::cout << "ERROR: Bad Input" << endl; break;
//        };
//    } while (menuCommand == 0);
//
//    cin.ignore();
//}

int main()
{
    /*MenuCommand menuCommand;
    DisplayMenu(menuCommand);*/
}