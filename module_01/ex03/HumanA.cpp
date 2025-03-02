#include "Weapon.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon)
{
}

HumanA::~HumanA()
{

}

void HumanA::attack() 
{
    std::cout << this->name << " attacks with " << weapon.getType() << std::endl;
}