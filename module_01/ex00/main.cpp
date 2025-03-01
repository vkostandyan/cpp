#include "Zombie.hpp"

int main()
{
    Zombie *alo = newZombie("alo");
    randomChump("blo");

    alo->announce();
    delete(alo);
}