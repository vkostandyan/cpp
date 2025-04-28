#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

#include <iostream>
#include "AForm.hpp"
#include <cstdlib>
#include <ctime> 

class RobotomyRequestForm : public AForm
{
public:
    void execute(Bureaucrat const &) const;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string&);
    RobotomyRequestForm(const RobotomyRequestForm&);
    const RobotomyRequestForm& operator=(const RobotomyRequestForm&);
    ~RobotomyRequestForm();
private:
    std::string target;
};

#endif