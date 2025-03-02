#include "Weapon.hpp"

HumanB::HumanB(const std::string& name)
{
    this->name = name;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    if (this->weapon)
        std::cout << this->name << " attacks with " << weapon->getType() << std::endl;
    else
        std::cout << this->name << " does not have weapon to attack" << std::endl;
}