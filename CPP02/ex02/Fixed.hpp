#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;

    public:
        Fixed( void );
        Fixed( int const value );
        Fixed( float const value );
        Fixed( Fixed const & src );
        Fixed &operator=( Fixed const & rhs );
        ~Fixed( void );

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

        Fixed operator+( Fixed const & rhs );
        Fixed operator-( Fixed const & rhs );
        Fixed operator*( Fixed const & rhs );
        Fixed operator/( Fixed const & rhs );

        Fixed &operator++( void );
        Fixed operator++( int );
        Fixed &operator--( void );
        Fixed operator--( int );

        static Fixed & min( Fixed & lhs, Fixed & rhs );
        static Fixed const & min( Fixed const & lhs, Fixed const & rhs );
        
        static Fixed & max( Fixed & lhs, Fixed & rhs );
        static Fixed const & max( Fixed const & lhs, Fixed const & rhs );
};

std::ostream &operator<<( std::ostream & o, Fixed const & rhs );

bool operator>( Fixed const & lhs, Fixed const & rhs );
bool operator<( Fixed const & lhs, Fixed const & rhs);
bool operator>=( Fixed const & lhs, Fixed const & rhs);
bool operator<=( Fixed const & lhs, Fixed const & rhs);
bool operator==( Fixed const & lhs, Fixed const & rhs);
bool operator!=( Fixed const & lhs, Fixed const & rhs);

#endif
