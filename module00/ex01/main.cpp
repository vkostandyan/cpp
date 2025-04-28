#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
    PhoneBook phonebook;
    std::string input;
    int index = 0;

    input = phonebook.get_input("Enter command: ADD | SEARCH | EXIT\n");
    while (true)
    {
        if (input == "ADD")
            phonebook.add(index);
        else if (input == "SEARCH")
			phonebook.search();
        if (input == "EXIT")
		{
			std::cout << "Exiting program." << std::endl;
			break ;
		}
    }
    (void)argc;
    (void)argv;
    (void)index;
}