#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Unknown"), health(10), energy(10), damage(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), health(10), energy(10), damage(0) 
{
    std::cout << "Parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& rhs) : name(rhs.name), health(rhs.health), energy(rhs.energy), damage(rhs.damage) 
{
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (&rhs != this)
    {
        this->name = rhs.name;
        this->health = rhs.health;
        this->energy= rhs.energy;
        this->damage = rhs.damage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (get_energy_points() > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
        set_energy_points(get_energy_points() - 1);
    }
    else
        std::cout << "ClapTrap " << this->name << " has no energy to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= (unsigned int)health)
        health = 0;
    else
        health -= amount;
    std::cout << "ClapTrap " << get_name() << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (get_energy_points() > 0)
    {
        set_energy_points(get_energy_points() - 1);
        set_health(get_health() + amount);
        std::cout << "ClapTrap " << this->name << " repairs itself, restoring " << amount << " hit points!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " has no energy to repair!" << std::endl;
}

std::string const ClapTrap::get_name() const
{
    return this->name;
}

int ClapTrap::get_health() const
{
    return this->health;
}

void ClapTrap::set_health(int health)
{
    this->health = health;
}

int ClapTrap::get_energy_points() const
{
    return this->energy;
}

void ClapTrap::set_energy_points(int energy)
{
    this->energy = energy;
}

int ClapTrap::get_attack_damage() const
{
    return this->damage;
}

void ClapTrap::set_attack_damage(int damage)
{
    this->damage = damage;
}

