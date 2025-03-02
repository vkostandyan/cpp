#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(const std::string&, Weapon&);
        ~HumanA();
        void attack();

    private:
        std::string name;
        Weapon& weapon;
};