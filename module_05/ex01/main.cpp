#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat bureaucrat("John", 75);

    Form form("form", 0, 100, 110);
    Form form1(form);
    bureaucrat.signForm(form);
    bureaucrat.signForm(form1);
	std::cout << bureaucrat;
	std::cout << form1;
}