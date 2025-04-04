#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unknown"), grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
    // if
    std::cout << "Bureaucrat parameter constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : name(rhs.name), grade(rhs.grade)
{
    // if
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    // if()
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (&rhs != this)
    {
        const_cast<std string&>(this->name) = rhs.name;
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
    // if
}

void Bureaucrat::decrementGrade()
{
    this->grade++;
    // if
}