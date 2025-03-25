#ifndef FragTrap_HPP
# define FragTrap_HPP

#include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string const name);
    FragTrap(const FragTrap& obj);
    FragTrap &operator=(const FragTrap &obj);
    ~FragTrap();
public:
    void highFivesGuys(void);

};

#endif