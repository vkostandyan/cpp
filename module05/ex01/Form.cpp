#include "Form.hpp"

Form::Form() : name("Unknown"), isSigned(false), signGrade(150), executeGrade(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const bool isSigned, const int signGrade, const int executeGrade) : \
                name(name), isSigned(isSigned), signGrade(signGrade), executeGrade(executeGrade)
{
    std::cout << "Form parameter constructor called" << std::endl;
	validateGrade(signGrade);
	validateGrade(executeGrade);
}

Form::Form(const Form& rhs) : name(rhs.name), isSigned(rhs.isSigned), signGrade(rhs.signGrade), executeGrade(rhs.executeGrade)
{
    std::cout << "Form copy constructor called" << std::endl;
}

const Form& Form::operator=(const Form& rhs)
{
    std::cout << "Form copy assignment operator called" << std::endl;
	if (&rhs != this)
	{
		const_cast<std::string &>(this->name) = rhs.name;
		this->isSigned = rhs.isSigned;
		const_cast<int &>(this->signGrade) = rhs.signGrade;
		const_cast<int &>(this->executeGrade) = rhs.executeGrade;
	}
	return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "The grade cannot be higher than 1.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "The grade cannot be lower than 150.";
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

void Form::validateGrade(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

const std::string &Form::getName(void) const { return this->name; }

bool Form::getSign(void) const { return this->isSigned; }

int Form::getSignGrade(void) const { return this->signGrade; }

int Form::getExecuteGrade(void) const { return this->executeGrade; }

std::ostream&	operator<<(std::ostream& os, const Form& ob)
{
    std::cout << "Name: " << ob.getName() << std::endl;
    std::cout << "Is signed: " << ob.getSign() << std::endl;
    std::cout << "Grade to sign: " << ob.getSignGrade() << std::endl;
    std::cout << "Grade to execute: " << ob.getExecuteGrade() << std::endl;
    return os;
}