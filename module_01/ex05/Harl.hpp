#ifndef Harl_HPP
# define Harl_HPP

#include <iostream>

class Harl
{
    public: 
        Harl();
        ~Harl();
        void complain(std::string level);

    private:
        void debug();
        void info();
        void warning();
        void error();
};

#endif