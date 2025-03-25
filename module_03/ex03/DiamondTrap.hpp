#ifndef DiamondTrap_HPP
# define DiamondTrap_HPP

#include <ostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap& ob);
    DiamondTrap& operator=(DiamondTrap& rhs);
    ~DiamondTrap();
public:
    void whoAmI();
private:
    std::string name;
};

#endif