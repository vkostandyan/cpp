#ifndef MateriaSource_HPP
# define MateriaSource_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    MateriaSource(const MateriaSource &);
    const MateriaSource &operator=(const MateriaSource &);
    ~MateriaSource();
public:
    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &);
private:
    AMateria *slots[4];
};

#endif