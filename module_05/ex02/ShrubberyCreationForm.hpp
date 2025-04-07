#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string&);
    ShrubberyCreationForm(const ShrubberyCreationForm&);
    const ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
    ~ShrubberyCreationForm();
private:
    std::string target;
}

#endif