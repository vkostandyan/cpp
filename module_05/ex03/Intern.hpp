#ifndef Intern_HPP
# define Intern_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
		AForm *makeForm(std::string name, std::string target);
		
		class NoSuchFormException : public std::exception
		{
			public:
                const char* what() const throw();
		};
};

#endif