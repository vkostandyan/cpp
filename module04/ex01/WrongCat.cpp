#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal(rhs)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

const WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (&rhs != this)
        WrongAnimal::operator=(rhs);
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout<<"Meow\n";
}