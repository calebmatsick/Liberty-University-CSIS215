// Include statements
#include <iostream>
#include <string>
#include <fstream>
#include "CountList.h"
#include "MovetoFrontList.h"
#include "TransposeList.h"


int main() {

	bool flag; // Flag for return from find

	/*
	  Beginning of Count Heuristic
	*/
	std::cout << " __________ Count Heuristic __________" << std::endl << std::endl;

	std::cout << " ~ Char Test ~ " << std::endl << std::endl;

	// Creates Count List object
	CountList<char> CountChar;

	// Adds initial chars
	CountChar.add('A');
	CountChar.add('B');
	CountChar.add('C');
	CountChar.add('D');
	CountChar.add('E');
	CountChar.add('F');
	CountChar.add('G');
	CountChar.add('H');

	// Enters in new chars using the find function
	char c;
	std::cout << "Enter: F D F G E G F A D F G E H I" << std::endl;
	for (int i = 0; i < 15; i++) {
		std::cin >> c;
		flag = CountChar.find(c);
	}

	// Displays the results
	std::cout << "Count Heuristic: Size of list: " << CountChar.size() << std::endl;
	std::cout << "Number of compares: " << CountChar.getCompares() << std::endl;
	std::cout << "The final order of the list is: " << std::endl;
	CountChar.printlist();

	CountChar.removeall();

	std::cout << std::endl << " ~ String Test ~" << std::endl << std::endl;

	// Creates object for string test
	CountList<std::string> CountString;

	// Opens test file
	std::ifstream countFile;
	countFile.open("test.txt", std::ios::in);

	// Reads in the words and adds them using find
	std::string countWord;
	while (countFile >> countWord) {
		CountString.find(countWord);
	}

	// Displays the results
	std::cout << "Count Heuristic: Size of list: " << CountString.size() << std::endl;
	std::cout << "Number of compares: " << CountString.getCompares() << std::endl;
	std::cout << "The first ten elements of the list is: " << std::endl;
	CountString.printlist(10);

	countFile.close();

	std::cout << std::endl << std::endl;

	/*
	  Beginning of Move to Front Heuristic
	*/
	std::cout << " __________ Move to Front Heuristic __________" << std::endl << std::endl;

	std::cout << " ~ Char Test ~ " << std::endl << std::endl;

	// Create new List object
	MovetoFrontList<char> MovetoFrontChar;

	// Add letters to the list
	MovetoFrontChar.add('A');
	MovetoFrontChar.add('B');
	MovetoFrontChar.add('C');
	MovetoFrontChar.add('D');
	MovetoFrontChar.add('E');
	MovetoFrontChar.add('F');
	MovetoFrontChar.add('G');
	MovetoFrontChar.add('H');

	// Allow the user to enter the next letters, calling find for each one
	std::cout << "Enter: F D F G E G F A D F G E H I" << std::endl;
	for (int i = 0; i < 15; i++) {
		std::cin >> c;
		flag = MovetoFrontChar.find(c);
	}

	// Displays results after letters have been added
	std::cout << "Move to Front Heuristic: Size of list: " << MovetoFrontChar.size() << std::endl;
	std::cout << "Number of compares: " << MovetoFrontChar.getCompares() << std::endl;
	std::cout << "The final order of the list are: " << std::endl;
	MovetoFrontChar.printlist();

	// Clears the list
	MovetoFrontChar.removeall();

	std::cout << std::endl << " ~ String Test ~" << std::endl << std::endl;

	// Creates new object for strings
	MovetoFrontList<std::string> MovetoFrontString;

	std::ifstream moveToFrontFile; // File for read in
	std::string moveToFrontWord; // Word for read in

	// Opens file
	moveToFrontFile.open("test.txt", std::ios::in);

	// Reads in and calls find for each word in the file
	while (moveToFrontFile >> moveToFrontWord) {
		MovetoFrontString.find(moveToFrontWord);
	}

	// Displays the results
	std::cout << "Move to Front Heuristic: Size of list: " << MovetoFrontString.size() << std::endl;
	std::cout << "Number of compares: " << MovetoFrontString.getCompares() << std::endl;
	std::cout << "The first ten elements of the list are: " << std::endl;
	MovetoFrontString.printlist(10);

	moveToFrontFile.close();

	std::cout << std::endl << std::endl;

	/*
	  Beginning of Transpose Heuristic
	*/
	std::cout << " __________ Transpose Heuristic __________" << std::endl << std::endl;

	std::cout << " ~ Char Test ~ " << std::endl << std::endl;

	// Create new List object
	TransposeList<char> TransposeChar;

	// Add letters to the list
	TransposeChar.add('A');
	TransposeChar.add('B');
	TransposeChar.add('C');
	TransposeChar.add('D');
	TransposeChar.add('E');
	TransposeChar.add('F');
	TransposeChar.add('G');
	TransposeChar.add('H');

	// Allow the user to enter the next letters, calling find for each one
	std::cout << "Enter: F D F G E G F A D F G E H I" << std::endl;
	for (int i = 0; i < 15; i++) {
		std::cin >> c;
		flag = TransposeChar.find(c);
	}

	// Displays results after letters have been added
	std::cout << "Transpose Heuristic: Size of list: " << TransposeChar.size() << std::endl;
	std::cout << "Number of compares: " << TransposeChar.getCompares() << std::endl;
	std::cout << "The final order of the list is: " << std::endl;
	TransposeChar.printlist();

	// Clears the list
	TransposeChar.removeall();

	std::cout << std::endl << " ~ String Test ~" << std::endl << std::endl;

	// Creates new object for strings
	TransposeList<std::string> TransposeString;

	std::ifstream transposeFile; // File for read in
	std::string transposeWord; // Word for read in

	// Opens file
	transposeFile.open("test.txt", std::ios::in);

	// Reads in and calls find for each word in the file
	while (transposeFile >> transposeWord) {
		TransposeString.find(transposeWord);
	}

	// Displays the results
	std::cout << "Transpose Heuristic: Size of list: " << TransposeString.size() << std::endl;
	std::cout << "Number of compares: " << TransposeString.getCompares() << std::endl;
	std::cout << "The first ten elements of the list are: " << std::endl;
	TransposeString.printlist(10);

	transposeFile.close();

	std::cout << std::endl << std::endl;

	system("pause");
	return 0;
}