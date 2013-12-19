// #include "ArrayList.h"
#include "TArrayList.h"
#include <string>

void menu();
char getSelection();

int main()
{
	// GOBALS
	List<int>* my_list = new ArrayList<int>(); /* New Instantiation */
	char selection;
	while (true)
	{
		menu();
		selection = getSelection();

		if (selection == 'a' || selection == 'A')
		{
			int val;
			std::cout << "Value to append:  ";
			std::cin >> val;
			my_list->append(val);
			std::cin.ignore();
		}
		else if (selection == 'p' || selection == 'P')
		{
			int val;
			std::cout << "Value to prepend:  ";
			std::cin >> val;
			my_list->prepend(val);
			std::cin.ignore();
		}
		else if (selection == 'i' || selection == 'I')
		{
			try {
				int value;
				unsigned index;
				std::cout << "Value you would like to insert:  ";
				std::cin >> value;
				std::cout << "Index you'd like to store your value at:  ";
				std::cin >> index;
				my_list->insertAt(value, index);
				std::cin.ignore();
			} catch (std::bad_exception& e) {
				std::cerr << e.what() << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 'd' || selection == 'D')
		{
			try {
				int value = my_list->decaudate();
				std::cout << value << " was removed from the end of the list." << std::endl;
			} catch (char const* msg) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 'e' || selection == 'E')
		{
			try {
				int value = my_list->decapitate();
				std::cout << value << " was removed from the beginning of the list." << std::endl;
			} catch (char const* msg) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 'r' || selection == 'R')
		{
			try {
				unsigned index;
				std::cout << "Index of the element you'd like to remove:  ";
				std::cin >> index;
				int value = my_list->removeAt(index);
				std::cout << value << " was removed from the list." << std::endl;
				std::cin.ignore();
			} catch (std::bad_exception& e) {
				std::cerr << e.what() << std::endl;
			} catch (char const* msg) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 'c' || selection == 'C')
		{
			try {
				my_list->clear();
				std::cout << "The LinkedList is now empty!" << std::endl;
			} catch (char const* msg) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			}
			catch (std::bad_exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
		else if (selection == 'h' || selection == 'H')
		{
			try {
				int value = my_list->itemAtHead();
				std::cout << value << " is at the beginning of the list." << std::endl;
			} catch (char const* msg) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 't' || selection == 'T')
		{
			try {
				int value = my_list->itemAtTail();
				std::cout << value << " is at the end of the list." << std::endl;
			} catch (char const* msg) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 's' || selection == 'S')
		{
			try {
				unsigned index;
				std::cout << "What index would you like to check?:  ";
				std::cin >> index;
				int value = my_list->itemAt(index);
				std::cout << value << " is at index " << index << std::endl;
				std::cin.ignore();
			} catch (std::bad_exception& e) {
				std::cerr << e.what() << std::endl;
			} catch (char const* msg) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 'v' || selection == 'V')
		{
			int value;
			std::cout << "What value would you like to search the list for?:  ";
			std::cin >> value;
			std::cout << value << ((my_list->contains(value)) ? " was found!" : " was NOT found!") << std::endl;
			std::cin.ignore();
		}
		else if (selection == 'l' || selection == 'L')
			std::cout << "The length of the list is:  " << my_list->length() << std::endl;
		else if (selection == 'g' || selection == 'G')
		{
			try {
				std::cout << "The List BEFORE:  " << std::endl;
				my_list->print();
				my_list->removeDuplicates();
				std::cout << "The List AFTER:  " << std::endl;
				my_list->print();
			} catch (char const* msg) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 'n' || selection == 'N')
		{
			try {
				my_list->print();
			} catch (char const* msg) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 'q' || selection == 'Q') 
			break;
		else
			std::cout << "Please make a selection.\n\n\n\n" << std::endl;
	}
	delete my_list;
	std::cout << "Happy Coding!\n";
	return 0;
}

void menu()
{
	std::cout << "(A)ppend an Element to List\n" 
			  << "(P)repend an Element to List\n"
			  << "(I)nsert an Element To the List\n"
			  << "(D)ecaudate\n"
			  << "D(E)capitate\n"
			  << "(R)emove Element\n"
			  << "(C)lear the List\n"
			  << "(H)ead Element\n"
			  << "(T)ail Element\n"
			  << "(S)ee What Element is at an Index\n"
			  << "(V)alue in the List?\n"
			  << "(L)ength of the List\n"
			  << "(G)et Rid of Duplicates\n"
			  << "Pri(N)t\n"
			  << "(Q)uit\n" << std::endl;
}
char getSelection()
{
	char buffer[512];
	std::cout << "Selection:  ";
	std::cin.getline(buffer, 512);
	return buffer[0];
}