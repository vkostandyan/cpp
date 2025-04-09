#ifndef Ice_HPP
# define Ice_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const std::string&);
    Ice(const Ice&);
    const Ice& operator=(const Ice&);
    ~Ice();
public:
    AMateria *clone() const;
    void use(ICharacter&);
};

#endif