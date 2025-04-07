#include "AForm.hpp"

AForm::AForm() : name("Unknown"), isSigned(false), signGrade(150), executeGrade(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const bool isSigned, const int signGrade, const int executeGrade) : \
                name(name), isSigned(isSigned), signGrade(signGrade), executeGrade(executeGrade)
{
    std::cout << "AForm parameter constructor called" << std::endl;
}

AForm::AForm(const AForm& rhs) : name(rhs.name), isSigned(rhs.isSigned), signGrade(rhs.signGrade), executeGrade(rhs.executeGrade)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

const AForm& AForm::operator=(const AForm& rhs)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
	if (&rhs != this)
	{
		const_cast<std::string &>(this->name) = rhs.name;
		this->isSigned = rhs.isSigned;
		const_cast<int &>(this->signGrade) = rhs.signGrade;
		const_cast<int &>(this->executeGrade) = rhs.executeGrade;
	}
	return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "The grade cannot be higher than 1.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "The grade cannot be lower than 150.";
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

const std::string &AForm::getName(void) const { return this->name; }

bool AForm::getSign(void) const { return this->isSigned; }

int AForm::getSignGrade(void) const { return this->signGrade; }

int AForm::getExecuteGrade(void) const { return this->executeGrade; }

std::ostream&	operator<<(std::ostream& os, const AForm& ob)
{
    std::cout << "Name: " << ob.getName() << std::endl;
    std::cout << "Is signed: " << ob.getSign() << std::endl;
    std::cout << "Grade to sign: " << ob.getSignGrade() << std::endl;
    std::cout << "Grade to execute: " << ob.getExecuteGrade() << std::endl;
    return os;
}