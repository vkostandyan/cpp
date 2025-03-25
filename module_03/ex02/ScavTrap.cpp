#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Unknown ScavTrap") 
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    set_health(100);
    set_energy_points(50);
    set_attack_damage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap parameter constructor called" << std::endl;
    set_health(100);
    set_energy_points(50);
    set_attack_damage(20);
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (get_energy_points() > 0)
    {
        std::cout << "ScavTrap " << get_name() << " attacks " << target << ", causing " << get_attack_damage() << " points of damage!" << std::endl;
        set_energy_points(get_energy_points() - 1);
    }
    else
        std::cout << "ScavTrap " << get_name() << " has no energy to attack!" << std::endl;
}

void ScavTrap::guardGate() const
{
	std::cout << "ScavTrap " << get_name() << " is now in gate keeper mode." << std::endl;
}

