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

static int get_level(std::string& level)
{
    std::string complains[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) 
    {
		if (complains[i] == level) 
			return (i);
	}
	return (-1);
}

void Harl::complain(std::string level)
{
    void (Harl::*ptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    int lvl = get_level(level);
    switch(lvl)
    {
        case(0):
            std::cout << "[ DEBUG ]" << std::endl;
            (this->*ptr[0])();
        case(1):
            std::cout << "[ INFO ]" << std::endl;
            (this->*ptr[1])();
        case(2):
            std::cout << "[ WARNING ]" << std::endl;
            (this->*ptr[2])();
        case(3):
            std::cout << "[ ERROR ]" << std::endl;
            (this->*ptr[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}