#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
public:
    Array();
    Array(unsigned int);
    Array(const Array&);
    Array& operator=(const Array&);
    ~Array();
public:
    unsigned int size() const;
    T &operator[](const unsigned int);
private:
    T *arr;
    unsigned int s;
};

#include "Array.tpp"

#endif