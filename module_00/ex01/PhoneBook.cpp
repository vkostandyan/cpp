#include "PhoneBook.hpp"

void PhoneBook::add(int& i)
{
	i %= 8;
	this->contacts[i].set_first_name(get_input("Enter first name: "));
	this->contacts[i].set_last_name(get_input("Enter last name: "));
	this->contacts[i].set_nick_name(get_input("Enter nick name: "));
	this->contacts[i].set_phone_number(get_input("Enter phone number: "));
	this->contacts[i].set_darkest_secret(get_input("Enter darkest secret: "));
	if (isalpha_str(this->contacts[i].get_first_name())
		&& isalpha_str(this->contacts[i].get_last_name()) && isdigit_str(this->contacts[i].get_phone_number()))
	{
        i++;
        std::cout << "Contact added successfully" << std::endl;
	}
     else
		std::cout << "Please enter correct data!" << std::endl;
}

void PhoneBook::search()
{
    std::string index;

    this->print_phonebook();
    while (!std::cin.eof()) 
    {
		index = this->get_input("Select an index: ");
        if (index.length() == 1 && index[0] >= '1' && index[0] <= '8' && \
            this->contacts[index[0] - 1 - '0'].get_first_name().size())
        {
            this->print_contact(index[0] - 1 - '0');
            break ;
        }
		if (index != "")
			std::cout << "Invalid index!" << std::endl;
	}
    
}

void    PhoneBook::print_contact(int i)
{
    std::cout << "index: " << i + 1;
    std::cout << "first name: " << this->contacts[i].get_first_name() << std::endl;
    std::cout << "last name: " << this->contacts[i].get_last_name() << std::endl;
    std::cout << "nick name: " << this->contacts[i].get_nick_name() << std::endl;
    std::cout << "phone number: " << this->contacts[i].get_phone_number() << std::endl;
    std::cout << "darkest secret: " << this->contacts[i].get_darkest_secret() << std::endl;
}

void    PhoneBook::print_phonebook()
{
    int i = 0;

    while (i < 8 && this->contacts[i].get_first_name().size())
    {
        std::string first_name = this->contacts[i].get_first_name();
        std::string last_name = this->contacts[i].get_last_name();
        std::string nick_name = this->contacts[i].get_nick_name();
        if (first_name.length() > 10)
            first_name = first_name.substr(0, 9) + ".";
        if (last_name.length() > 10)
            last_name = last_name.substr(0, 9) + ".";
        if (nick_name.length() > 10)
            nick_name = nick_name.substr(0, 9) + ".";
        std::cout << std::right << std::setw(10) << i + 1 << " | ";
        std::cout << std::right << std::setw(10) << first_name << " | ";
        std::cout << std::right << std::setw(10) << last_name << " | ";
        std::cout << std::right << std::setw(10) << nick_name << std::endl;
        i++;
    }
}

std::string PhoneBook::get_input(std::string text)
{
	std::string str;
	std::cout << text;
	std::getline(std::cin, str);
	return (str);
}

int	PhoneBook::isalpha_str(const std::string &name)
{
	for (int i = 0; name[i]; i++)
	{
		if (!isalpha(name[i]))
			return (0);
	}
	return (1);
}

int	PhoneBook::isdigit_str(const std::string &name)
{
	for (int i = 0; name[i]; i++)
	{
		if (!isdigit(name[i]))
			return (0);
	}
	return (1);
}