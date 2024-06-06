
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
private:
	int				rawBits;
	static const int amount_of_bits = 8;

public:
	Fixed(void);
	~Fixed(void);
	Fixed(const int bits);
	Fixed(const float bits);
	Fixed(const Fixed & other);
	Fixed&  operator=(const Fixed & other);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	int toInt( void ) const;
	float toFloat( void ) const;
};

std::ostream & operator<<(std::ostream &o, Fixed const & other);

#endif