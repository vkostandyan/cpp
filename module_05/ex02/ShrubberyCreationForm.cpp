#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("DefaultShrubbery", 0, 145, 137), target("Default")
{
    std::cout << "Shrubbery default ctor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& s) : AForm("DefaultShrubbery", 0, 145, 137), target(s)
{
    std::cout << "Shrubbery parameter constructor called" << std::endl;
}