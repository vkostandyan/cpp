#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    void execute(Bureaucrat const &) const;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string&);
    PresidentialPardonForm(const PresidentialPardonForm&);
    const PresidentialPardonForm& operator=(const PresidentialPardonForm&);
    ~PresidentialPardonForm();
private:
    std::string target;
};

#endif