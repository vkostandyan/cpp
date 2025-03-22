#ifndef Fixed_HPP
# define Fixed_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &cp);
        Fixed(const int number);
        Fixed(const float number);
        Fixed &operator=(const Fixed &fixed);
        ~Fixed();

        bool operator>(const Fixed& other);
        bool operator<(const Fixed& other);
        bool operator>=(const Fixed& other);
        bool operator<=(const Fixed& other);
        bool operator==(const Fixed& other);
        bool operator!=(const Fixed& other);

        const Fixed operator+(const Fixed& other);
        const Fixed operator-(const Fixed& other);
        const Fixed operator*(const Fixed& other);
        const Fixed operator/(const Fixed& other);

        const Fixed& operator++();
        const Fixed& operator--();
        const Fixed operator++(int);
        const Fixed operator--(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
            
    private:
        int fixed_point_nb;
        static const int fractional_bits = 8; 
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif