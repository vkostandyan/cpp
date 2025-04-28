#include "AMateria.hpp"

AMateria::AMateria() : type("default")
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) : type(type)
{
    std::cout << "AMateria parameter constructor called" << std::endl;
}

AMateria::AMateria(AMateria const& rhs) : type(rhs.type)
{
    std::cout << "AMateria copy constructor called" << std::endl;
}

const AMateria& AMateria::operator=(AMateria const& rhs)
{
    std::cout << "AMateria copy assignment operator called" << std::endl;
    if (&rhs != this)
        this->type = rhs.type;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria use " << this->getType() << " on " << target.getName() << std::endl;
}

std::string const& AMateria::getType() const { return (this->type); }