#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("DefaultShrubbery", 0, 72, 45), target("Default")
{
    std::cout << "Robotomy default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& s) : AForm("DefaultShrubbery", 0, 72, 45), target(s)
{
    std::cout << "Robotomy parameter constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : AForm(rhs), target(rhs.target)
{
    std::cout << "Robotomy copy constructor called" << std::endl;
}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    std::cout << "Robotomy copy assignment operator called" << std::endl;
    if (&rhs != this)
    {
        AForm::operator=(rhs);
        this->target = rhs.target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
// AForm::execute(executor) needs definition
    std::cout<<"Some drilling noices" << std::endl;
    if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " robotomy failed." << std::endl;
        (void)executor;
    
}