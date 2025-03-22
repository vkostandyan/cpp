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