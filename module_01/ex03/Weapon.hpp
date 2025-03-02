#ifndef WEAPON_H
# define WEAPON_H

class Weapon;

#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

class Weapon
{
    public:
        Weapon(std::string type);
        ~Weapon();
        void setType(std::string type);
        const std::string& getType();
        
    private:
        std::string type;
};


#endif