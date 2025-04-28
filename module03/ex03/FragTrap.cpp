#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unknown FragTrap") 
{
    std::cout << "FragTrap default constructor called" << std::endl;
    set_health(100);
    set_energy_points(100);
    set_attack_damage(30);
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
    std::cout << "FragTrap parameter constructor called" << std::endl;
    set_health(100);
    set_energy_points(100);
    set_attack_damage(30);
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
		std::cout << "FragTrap " << get_name() << " - high fives Guys!" << std::endl;
}
