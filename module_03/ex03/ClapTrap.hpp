#ifndef ClapTrap_HPP
# define ClapTrap_HPP

#include <iostream>

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& rhs);
    ClapTrap& operator=(const ClapTrap& rhs);
    ~ClapTrap();
public:
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    std::string const get_name() const;
    int get_health() const;
    void set_health(int health);
    int get_energy_points() const;
    void set_energy_points(int energy_points);
    int get_attack_damage() const;
    void set_attack_damage(int attack_damage);
private:
    std::string name;
    int health;
    int energy;
    int damage;
};

#endif