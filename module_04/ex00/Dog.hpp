#ifndef Dog_HPP
# define Dog_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog&);
    const Dog& operator=(const Dog&);
    ~Dog();
public:
    void makeSound() const;
};

#endif