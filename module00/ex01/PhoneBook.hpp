#ifndef PhoneBook_HPP
# define PhoneBook_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
    public:
        std::string get_input(std::string text);
        void add(int& index);
        void search();

    private:
        int isalpha_str(const std::string &name);
        int	isdigit_str(const std::string &name);
        void print_contact(int index);
        void print_phonebook();
        Contact contacts[8];
};

#endif