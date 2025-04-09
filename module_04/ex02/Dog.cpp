#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog& rhs) : Animal(rhs)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*rhs.brain);
}

const Dog& Dog::operator=(const Dog& rhs)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (&rhs != this)
    {
        Animal::operator=(rhs);
        this->brain = new Brain(*rhs.brain);
    }
    return (*this);
}

Dog::~Dog()
{
    delete (this->brain);
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout<<"Meow\n";
}