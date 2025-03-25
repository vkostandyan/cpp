#ifndef ScavTrap_HPP
# define ScavTrap_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& obj);
    ScavTrap& operator=(const ScavTrap& rhs);
    ~ScavTrap();
public:
    void attack(const std::string& target);
    void guardGate() const;
};



#endif