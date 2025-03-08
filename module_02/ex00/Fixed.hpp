#ifndef Fixed_HPP
# define Fixed_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &cp);
        Fixed &operator=(const Fixed &fixed);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
    private:
        int fixed_point_nb;
        static const int fractional_bits = 8; 
};

#endif