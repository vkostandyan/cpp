#ifndef Dog_HPP
# define Dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog&);
    const Dog& operator=(const Dog&);
    ~Dog();
public:
    void makeSound() const;
private:
    Brain *brain;
};

#endif