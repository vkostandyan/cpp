#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Invalid arguments" << std::endl;
        return (1);
    }
    Harl harl;
    
    harl.complain(argv[1]);
    return (0);
}