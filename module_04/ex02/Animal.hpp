#ifndef Animal_HPP
# define Animal_HPP

#include <iostream>

class Animal
{
public:
    Animal();
    Animal(const Animal&);
    const Animal& operator=(const Animal&);
    virtual ~Animal();

public:
    void setType(std::string type);
    std::string getType() const;
    virtual void makeSound() const = 0;

protected:
    std::string type;
};

#endif