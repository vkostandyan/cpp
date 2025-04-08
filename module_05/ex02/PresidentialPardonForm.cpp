#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("DefaultShrubbery", 0, 25, 5), target("Default")
{
    std::cout << "Presidential default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& s) : AForm("DefaultShrubbery", 0, 25, 5), target(s)
{
    std::cout << "Presidential parameter constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) : AForm(rhs), target(rhs.target)
{
    std::cout << "Presidential copy constructor called" << std::endl;
}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    std::cout << "Presidential copy assignment operator called" << std::endl;
    if (&rhs != this)
    {
        AForm::operator=(rhs);
        this->target = rhs.target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
// AForm::execute(executor) needs definition
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    (void)executor;
}
