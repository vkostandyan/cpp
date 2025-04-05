#ifndef Character__HPP
# define Character__HPP

// #include  "AMateria.hpp"
#include  "ICharacter.hpp"

class Character : public ICharacter
{
public:
    Character();
    Character(const std::string&);
    Character(const Character&);
    const Character& operator=(const Character&);
    ~Character();
public:
    const std::string &getName() const;
    void unequip(int);
    void equip(AMateria *);
    void use(int idx, ICharacter &target);
private:
    AMateria *slots[4];
    std::string name;
};

#endif