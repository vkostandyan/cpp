#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default construtor called" << std::endl;
}

Ice::Ice(const std::string& type) : AMateria(type)
{
    std::cout << "Ice parameter construtor called" << std::endl;
}

Ice::Ice(const Ice& rhs) : AMateria(rhs)
{
    std::cout << "Ice copy construtor called" << std::endl;
}

const Ice& Ice::operator=(const Ice& rhs)
{
    std::cout << "Ice copy assignment operator called" << std::endl;
    if (&rhs != this)
        this->type = rhs.type;
    return (*this);
}

Ice::~Ice()
{
    std::cout << "Ice destrutor called" << std::endl;
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}