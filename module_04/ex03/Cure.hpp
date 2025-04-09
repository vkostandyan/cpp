#ifndef Cure_HPP
# define Cure_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(const std::string&);
    Cure(const Cure&);
    const Cure& operator=(const Cure&);
    ~Cure();
public:
    AMateria *clone() const;
    void use(ICharacter&);
};

#endif