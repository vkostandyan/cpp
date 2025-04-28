#ifndef Brain_HPP
# define Brain_HPP

#include <iostream>

class Brain
{
public:
    Brain();
    Brain(const Brain&);
    const Brain& operator=(const Brain&);
    ~Brain();
public:
    std::string ideas[100];
};

#endif