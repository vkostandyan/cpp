#ifndef Cat_HPP
# define Cat_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat&);
    const Cat& operator=(const Cat&);
    ~Cat();
public:
    void makeSound() const;
};

#endif