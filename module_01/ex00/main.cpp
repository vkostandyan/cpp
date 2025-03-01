#include "Zombie.hpp"

int main()
{
    Zombie *alo = newZombie("alo");
    alo->announce();

    randomChump("blo");

    delete(alo);
    return (0);
}