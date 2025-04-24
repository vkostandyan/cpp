#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm> 

template <typename T>
typename T::iterator easyfind(T &container, const int find) 
{
    return std::find(container.begin(), container.end(), find);
}

#endif