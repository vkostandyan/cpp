#include "ScavTrap.hpp"

int main()
{
    ClapTrap clapTrap1;
    ClapTrap clapTrap2("ClapTrap1");

    clapTrap2.attack("Target1");
    clapTrap2.takeDamage(5);
    clapTrap2.beRepaired(10);

    ClapTrap clapTrap3 = clapTrap2;
    ClapTrap clapTrap4;

    clapTrap4 = clapTrap2;

    ScavTrap scavTrap1;
    std::string name2 = "ScavTrap1";
    ScavTrap scavTrap2(name2);

    scavTrap2.attack("Target2");
    scavTrap2.guardGate();

    return 0;
}