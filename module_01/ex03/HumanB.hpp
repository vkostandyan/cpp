#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(const std::string& name);
        ~HumanB();
        void setWeapon(Weapon& weapon);
        void attack();

    private:
        std::string name;
        Weapon *weapon;
};