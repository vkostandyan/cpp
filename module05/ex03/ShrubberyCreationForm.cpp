#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("DefaultShrubbery", 0, 145, 137), target("Default")
{
    std::cout << "Shrubbery default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& s) : AForm("DefaultShrubbery", 0, 145, 137), target(s)
{
    std::cout << "Shrubbery parameter constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : AForm(rhs), target(rhs.target)
{
    std::cout << "Shrubbery copy constructor called" << std::endl;
}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    std::cout << "Shrubbery copy assignment operator called" << std::endl;
    if (&rhs != this)
    {
        AForm::operator=(rhs);
        this->target = rhs.target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    AForm::checkExecute(executor);
    std::ofstream outfile((this->target + "_shrubbery").c_str());
    if (outfile.is_open())
	{
		outfile << tree;
		outfile.close();
	}
    (void)executor;
}