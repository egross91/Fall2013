#include "OrderedList.h"

void menu();
char getSelection();

int main()
{
	/* try {
		unsigned int size;
		std::cout << "How big of an ArrayList would you like?:  ";
		std::cin >> size;
	} catch (std::bad_exception& e) {
		std::cerr << e.what() << std::endl;
	} */

	// GOBALS
	OrderedList my_list;
	char selection;
	while (true)
	{
		menu();
		selection = getSelection();

		if (selection == 'p' || selection == 'P')
		{
			int val;
			std::cout << "Value to put:  ";
			std::cin >> val;
			my_list.put(val);
			std::cin.ignore();
		}
		/* else if (selection == 'd' || selection == 'D')
		{
			try {
				int value = my_list.decaudate();
				std::cout << value << " was removed from the end of the list." << std::endl;
			} catch (char msg[]) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 'e' || selection == 'E')
		{
			try {
				int value = my_list.decapitate();
				std::cout << value << " was removed from the beginning of the list." << std::endl;
			} catch (char msg[]) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			}
		} */
		else if (selection == 'r' || selection == 'R')
		{
			try {
				unsigned index;
				std::cout << "Index of the element you'd like to remove:  ";
				std::cin >> index;
				int value = my_list.removeAt(index);
				std::cout << value << " was removed from the list." << std::endl;
				std::cin.ignore();
			} catch (std::bad_exception& e) {
				std::cerr << e.what() << std::endl;
			} catch (char msg[]) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 'n' || selection == 'N')
		{
			try {
				my_list.print();
				std::cout << "\n\n" << std::endl;
			} catch (char msg[]) {
				std::cerr << msg << std::endl;
				std::cin.ignore();
			}
		}
		else if (selection == 'q' || selection == 'Q')
			break;
		else
			std::cout << "Please make a selection.\n\n\n\n" << std::endl;
	}
	std::cout << "Happy Coding!\n";
	return 0;
}

void menu()
{
	std::cout << "(P)ut an Element to List\n"
			  << "(I)nsert an Element into the List\n"
			  << "(D)ecaudate\n"
			  << "D(E)capitate\n"
			  << "(R)emove Element\n"
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