#include "FragTrap.hpp"

int main() {
    FragTrap frag1("FragTrap1");
    FragTrap frag2("FragTrap2");

    // Battle Simulation
    frag1.attack(frag2.get_name());
    frag2.takeDamage(frag1.get_attack_damage());

    frag2.attack(frag1.get_name());
    frag1.takeDamage(frag2.get_attack_damage());

    frag1.attack(frag2.get_name());
    frag2.takeDamage(frag1.get_attack_damage());

    frag1.highFivesGuys();  // Call high-five

    return 0;
}