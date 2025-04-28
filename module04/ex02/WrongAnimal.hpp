#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

#include <iostream>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal&);
    const WrongAnimal& operator=(const WrongAnimal&);
    virtual ~WrongAnimal();

public:
    void setType(std::string type);
    std::string getType() const;
    void makeSound() const;

protected:
    std::string type;
};

#endif