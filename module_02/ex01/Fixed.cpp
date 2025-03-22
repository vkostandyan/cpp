#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    fixed_point_nb = 0;
}

Fixed::Fixed(const Fixed &cp)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = cp;
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(number << this->fractional_bits);
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    setRawBits(roundf(number * (1 << this->fractional_bits)));
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (*this == fixed)
        return (*this);
    this->fixed_point_nb = fixed.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fixed_point_nb);
}

void Fixed::setRawBits(int const raw)
{
    fixed_point_nb = raw;
}

float Fixed::toFloat(void) const
{
    return((float)this->fixed_point_nb / (1 << this->fractional_bits));
}

int Fixed::toInt(void) const
{
    return(this->fixed_point_nb >> this->fractional_bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}