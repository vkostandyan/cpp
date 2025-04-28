#include "Zombie.hpp"

int main()
{
    Zombie *alo = zombieHorde(4, "alo");

    for(int i = 0; i < 4; i++)
        alo[i].announce();
        
    delete[] alo;

    return (0);
}