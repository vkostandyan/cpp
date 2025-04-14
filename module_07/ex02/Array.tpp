#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array() : arr(NULL), s(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : s(n)
{
    arr = new T[s];
}

template <typename T>
Array<T>::Array(const Array& rhs)
{
    this->s = rhs.s;
    this->arr = new T[s];
    for (unsigned int i = 0; i < this->s; ++i)
        this->arr[i] = rhs.arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
    if (&this != this)
    {
        delete[] this->arr;
        this->s = rhs.s;
        this->arr = new T[s];
        for (unsigned int i = 0; i < this->s; ++i)
            this->arr[i] = rhs.arr[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] arr;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->s;
}

template <typename T>
T &Array<T>::operator[](const unsigned int i)
{
    if (i < 0 || i >= this->s)
        throw std::exception();
    return this->arr[i];
}

#include "Array.tpp"

#endif