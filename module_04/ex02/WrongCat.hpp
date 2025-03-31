#ifndef WrongCat_HPP
# define WrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat&);
    const WrongCat& operator=(const WrongCat&);
    ~WrongCat();
public:
    void makeSound() const;
};

#endif