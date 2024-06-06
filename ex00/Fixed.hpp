
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
private:
	int				rawBits;
	static const int amount_of_bits = 8;

public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed & other);
	Fixed&  operator=(const Fixed & other);
	int getRawBits( void ) const;
	void setRawBits( int const raw );

};

#endif