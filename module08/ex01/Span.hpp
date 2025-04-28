#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Span
{
public:
    void addNumber(int);
    int shortestSpan() const;
    int longestSpan() const;
    void fill();

public:
    Span();
    Span(const unsigned int);
    Span(const Span&);
    Span& operator=(const Span&);
    ~Span();
private:
    unsigned int N;
    std::vector<int> v;
};

#endif