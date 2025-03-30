#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& rhs) : Animal(rhs)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

const Cat& Cat::operator=(const Cat& rhs)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (&rhs != this)
        Animal::operator=(rhs);
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout<<"Meow\n";
}