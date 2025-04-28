#ifndef AMateria_HPP
# define AMateria_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
    std::string type;
public:
    AMateria();
    AMateria(std::string const&);
    AMateria(AMateria const&);
    const AMateria& operator=(const AMateria&);
    virtual ~AMateria();
public: 
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter&);
};

#endif