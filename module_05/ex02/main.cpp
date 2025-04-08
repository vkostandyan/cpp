#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat ob("John", 110);
	ShrubberyCreationForm form1;
	RobotomyRequestForm form2;
	PresidentialPardonForm form3;
    std::cout << "Form1\n";
	ob.signForm(form1);
	ob.executeForm(form1);
    std::cout << "Form2\n";
    ob.signForm(form2);
	ob.executeForm(form2);
    std::cout << "Form3\n";
    ob.signForm(form3);
	ob.executeForm(form3);
}