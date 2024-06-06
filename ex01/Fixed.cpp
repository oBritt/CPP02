

#include "Fixed.hpp"


Fixed::Fixed(void): rawBits(0){
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int bits){
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = (bits << this->amount_of_bits);
	return ;
}

Fixed::Fixed(const float bits){
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(bits * (1 << this->amount_of_bits));
	return ;
}

Fixed::Fixed(const Fixed & other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

Fixed&  Fixed::operator=(const Fixed & other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->rawBits = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = raw;
	return ;
}

int Fixed::toInt( void ) const{
	return (this->rawBits >> amount_of_bits);
}

float Fixed::toFloat( void ) const{
	return (float)this->rawBits / (float) (1 << amount_of_bits);
}


std::ostream & operator<<(std::ostream &o, Fixed const & other)
{
	o << other.toFloat();
	return (o);
}