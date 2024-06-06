
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
	Fixed operator+(Fixed const & other);
	Fixed operator-(Fixed const & other);
	Fixed operator*(Fixed const & other);
	Fixed operator/(Fixed const & other);
	bool operator>(Fixed const & other);
	bool operator<(Fixed const & other);
	bool operator==(Fixed const & other);
	bool operator>=(Fixed const & other);
	bool operator<=(Fixed const & other);
	bool operator!=(Fixed const & other);
	Fixed & operator++();
	Fixed & operator--();
	Fixed  operator++(int);
	Fixed  operator--(int);
	static const Fixed& min(const Fixed& first, const Fixed& second);
	static const Fixed& max(const Fixed& first, const Fixed& second);
	static Fixed& max(Fixed& first, Fixed& second);
	static Fixed& min(Fixed& first, Fixed& second);
};

std::ostream & operator<<(std::ostream &o, Fixed const & other);

#endif