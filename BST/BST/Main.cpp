#include "BST.h"

void menu();
char getSelection();

int main()
{
	BST my_tree;
	char selection;
	while (true)
	{
		menu();
		selection = getSelection();
		if (selection == 'i' || selection == 'I')
		{
			try {
				int val;
				std::cout << "Value to insert in the Tree:  ";
				std::cin >> val;
				my_tree.insert(val);
				std::cin.ignore();
			} catch (std::bad_exception& e) {
				std::cerr << e.what() << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 'r' || selection == 'R')
		{
			try {
				int val;
				std::cout << "Value to remove from Tree:  ";
				std::cin >> val;
				my_tree.remove(val);
				std::cin.ignore();
			} catch (char msg[]) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			} catch (std::bad_exception& e) {
				std::cerr << e.what() << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 'c' || selection == 'C')
		{
			try {
				int val;
				std::cout << "Value to check for:  ";
				std::cin >> val;
				std::cout << val << ((my_tree.contains(val)) ? " was found!" : " was NOT found!") << std::endl;
				std::cin.ignore();
			} catch (char msg[]) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			} catch (std::bad_exception& e) {
				std::cerr << e.what() << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 's' || selection == 'S')
		{
			std::cout << "There are " << my_tree.size() << " nodes in the Tree.\n" << std::endl;
			std::cin.ignore();
		}
		else if (selection == 'p' || selection == 'P')
		{
			try {
				my_tree.printContents();
				std::cin.ignore();
			} catch (char msg[]) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 'h' || selection == 'H')
		{
			try {
				std::cout << "There are " << my_tree.height() << " levels of nodes in the Tree.\n" << std::endl;
				std::cin.ignore();
			} catch (char msg[]) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 'q' || selection == 'Q')
			break;
		else
			std::cout << "Please make a selection.\n\n" << std::endl;
	}
	std::cout << "Happy Coding!\n";
	return 0;
}

void menu()
{
	std::cout << "(I)nsert Element\n"
			  << "(R)emove Element\n"
			  << "(C)ontains Element\n"
			  << "(S)ize of Tree\n"
			  << "(P)rint Tree\n"
			  << "(H)eight of Tree\n"
			  << "(Q)uit\n" << std::endl;
}
char getSelection()
{
	char buffer[512];
	std::cout << "Selection:  ";
	std::cin.getline(buffer, 512);
	return buffer[0];
}