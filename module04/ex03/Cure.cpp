#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default construtor called" << std::endl;
}

Cure::Cure(const std::string& type) : AMateria(type)
{
    std::cout << "Cure parameter construtor called" << std::endl;
}

Cure::Cure(const Cure& rhs) : AMateria(rhs)
{
    std::cout << "Cure copy construtor called" << std::endl;
}

const Cure& Cure::operator=(const Cure& rhs)
{
    std::cout << "Cure copy assignment operator called" << std::endl;
    if (&rhs != this)
        this->type = rhs.type;
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure destrutor called" << std::endl;
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* shoots an Cure bolt at " << target.getName() << " *" << std::endl;
}