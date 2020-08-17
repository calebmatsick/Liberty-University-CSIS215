/*
  Test driver
*/

// Include statements
#include <iostream>
#include <string>
#include "BST.h"


int main() {

    // Creates a new tree structure
    BST<int, string> * tree = new BST<int, string>;

    // Inserts all of the needed elements in the tree - Tests insert and insertHelp
    tree->insert(77, "seventy-seven");
    tree->insert(70, "seventy");
    tree->insert(75, "seventy-five");
    tree->insert(66, "sixty-six");
    tree->insert(79, "seventy-nine");
    tree->insert(68, "sixty-eight");
    tree->insert(67, "sixty-seven");
    tree->insert(69, "sixty-nine");
    tree->insert(90, "ninety");
    tree->insert(85, "eighty-five");
    tree->insert(83, "eighty-three");
    tree->insert(87, "eighty-seven");
    tree->insert(65, "sixty-five");

    // Message to signify insert is being tested
    std::cout << "Testing insert method." << endl;
    // Outputs the size of the tree - Tests size
    std::cout << "The size of the created tree is " << tree->size() << " nodes." << endl << endl;

    // Prints the tree in a way it can be visualized - Test print and printHelp
    std::cout << "Testing changes to the print function." << endl;
    std::cout << "The structure of the created tree is:" << endl;
    tree->print();
    cout << endl;

    // Prints the tree in order - Test printInOrder and printInOrderHelp
    std::cout << "Testing method to print nodes in order." << endl;
    std::cout << "The In-order printing of the created tree is:" << endl;
    tree->printInOrder();
    cout << endl;

    // Prints the tree in reverse in order - Tests printReverse and printReverseHelp.
    std::cout << "Testing method to print nodes in reverse order." << endl;
    std::cout << "The reverse printing of the created tree is:" << endl;
    tree->printReverse();
    cout << endl;

    system("pause");
    return 0;
}