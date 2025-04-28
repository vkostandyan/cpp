#include "Intern.hpp"

Intern::Intern()
{
	std::cout<<"Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	*this = other;
	std::cout<<"Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this == &other)
		return *this;
	std::cout<<"Intern copy assignment operator called" << std::endl;
	*this = other;
	return *this;
}

Intern::~Intern()
{
	std::cout<<"Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string arr[] = {"presidentialpardon", "robotomyrequest", "shrubberycreation"};
	int i = 0;	
	while (i < 3 && name != arr[i])
		i++;
	if (i < 3)
		std::cout << "Intern creates "<< name << std::endl;
	else
		throw Intern::NoSuchFormException();
	switch(i)
	{
		case 0:
			return (new PresidentialPardonForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new ShrubberyCreationForm(target));
	}
	return NULL;
}

const char* Intern::NoSuchFormException::what() const throw()
{
	return "No such form type!\n";
}
