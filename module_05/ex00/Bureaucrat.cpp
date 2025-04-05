#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unknown"), grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat parameter constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : name(rhs.name), grade(rhs.grade)
{
    if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (&rhs != this)
    {
        const_cast<std::string&>(this->name) = rhs.name;
        this->grade = rhs.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade()
{
    this->grade--;
    if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::decrementGrade()
{
    this->grade++;
    if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade cannot be higher than 1.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade cannot be lower than 150.";
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& ob)
{
	std::cout<<ob.getName()<<", bureaucrat grade "<< ob.getGrade()<<std::endl;
	return (os);
}