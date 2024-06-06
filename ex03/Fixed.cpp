

#include "Fixed.hpp"


Fixed::Fixed(void): rawBits(0){
	return ;
}

Fixed::~Fixed(void){
	return ;
}

Fixed::Fixed(const int bits){
	this->rawBits = (bits << this->amount_of_bits);
	return ;
}

Fixed::Fixed(const float bits){
	this->rawBits = roundf(bits * (1 << this->amount_of_bits));
	return ;
}

Fixed::Fixed(const Fixed & other)
{
	*this = other;
	return ;
}

Fixed&  Fixed::operator=(const Fixed & other){
	if (this != &other)
		this->rawBits = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	return this->rawBits;
}

void Fixed::setRawBits( int const raw )
{
	this->rawBits = raw;
	return ;
}

int Fixed::toInt( void ) const{
	return (this->rawBits >> amount_of_bits);
}

float Fixed::toFloat( void ) const{
	return (float)this->rawBits / (float) (1 << amount_of_bits);
}


Fixed Fixed::operator+(Fixed const & other)
{
	return Fixed(other.toFloat() + this->toFloat());
}

Fixed Fixed::operator-(Fixed const & other)
{
	return Fixed(this->toFloat() - other.toFloat() );
}

Fixed Fixed::operator*(Fixed const & other)
{
	return Fixed(other.toFloat() * this->toFloat());
}

Fixed Fixed::operator/(Fixed const & other)
{
	return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator<(Fixed const & other)
{
	return (this->toFloat() < other.toFloat());
}

bool Fixed::operator==(Fixed const & other)
{
	return (this->toFloat() == other.toFloat());
}

bool Fixed::operator<=(Fixed const & other)
{
	return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator>=(Fixed const & other)
{
	return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator!=(Fixed const & other)
{
	return (this->toFloat() != other.toFloat());
}

bool Fixed::operator>(Fixed const & other)
{
	return (this->toFloat() > other.toFloat());
}

Fixed& Fixed::operator++()
{
	++(this->rawBits);
	return *this;
}

Fixed& Fixed::operator--()
{
	--(this->rawBits);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	(this->rawBits)++;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	(this->rawBits)--;
	return temp;
}

const Fixed& Fixed::max(Fixed const & first, Fixed const & second)
{
	return (first.getRawBits() > second.getRawBits()) ? first : second;
}

const Fixed& Fixed::min(Fixed const & first, Fixed const & second)
{
	return (first.getRawBits() < second.getRawBits()) ? first : second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	return (first > second) ? first : second;
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	return (first < second) ? first : second;
}



std::ostream & operator<<(std::ostream &o, Fixed const & other)
{
	o << other.toFloat();
	return (o);
}

