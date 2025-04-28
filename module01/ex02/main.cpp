#include <iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *brainptr = &brain;
    std::string& brainref = brain;

    std::cout << &brain << std::endl;
    std::cout << brainptr << std::endl;
    std::cout << &brainref << std::endl;

    std::cout << brain << std::endl;
    std::cout << *brainptr << std::endl;
    std::cout << brainref << std::endl;


    return (0);
}