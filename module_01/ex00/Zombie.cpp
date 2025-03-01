#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
}

void Zombie::announce()
{
    std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}