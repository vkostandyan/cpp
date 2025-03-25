#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Unknown_clap_name"), ScavTrap("Unknown"), FragTrap("Unknown"), name("Unknown")
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    set_health(FragTrap::get_health());
    set_energy_points(ScavTrap::get_energy_points());
    set_attack_damage(FragTrap::get_attack_damage());
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
    std::cout << "DiamondTrap parameter constructor called" << std::endl;
    set_health(FragTrap::get_health());
    set_energy_points(ScavTrap::get_energy_points());
    set_attack_damage(FragTrap::get_attack_damage());
}

DiamondTrap::DiamondTrap(DiamondTrap& ob) : ClapTrap(ob), ScavTrap(ob), FragTrap(ob)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    // this->name = ob.name;
    // this->health = ob.health;
    // this->energy = ob.energy;
	// this->damage = ob.damage;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& rhs)
{
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if(&rhs != this)
        ClapTrap::operator=(rhs);
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
  std::cout << "DiamondTrap name is " << this->name << " ClapTrap name is " << ClapTrap::get_name() << std::endl;
}