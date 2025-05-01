#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <sstream>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe&);
    PmergeMe &operator=(const PmergeMe&);
    ~PmergeMe();
public:
    void fill(int, char**);
    template <typename T>
    void sort(T&);
    void manage();
    void print();
public:
    std::vector<int> vec;
    std::deque<int> deq;
};
#endif