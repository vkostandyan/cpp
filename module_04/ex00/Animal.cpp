#include "Animal.hpp"

Animal::Animal() : type("Default")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& rhs) : type(rhs.type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

const Animal& Animal::operator=(const Animal& rhs)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (&rhs != this)
        this->type = rhs.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::setType(std::string type)
{
    this->type = type;
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout << "Default sound" << std::endl;
}