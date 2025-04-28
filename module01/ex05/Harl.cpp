#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.";
    std::cout << " I really do!";
    std::cout << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. ";
    std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!";
    std::cout << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. ";
    std::cout << "I've been coming for years whereas you started working here since last month.";
    std::cout << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now.";
    std::cout << std::endl;
}

void Harl::complain(std::string level)
{
    std::string fun[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*ptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if (level == fun[i])
        {
            (this->*ptr[i])();
            return ;
        }
    }
}