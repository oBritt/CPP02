
#include "triangle.hpp"

Point::Point(): x(Fixed(0)), y(Fixed(0)){
	return ;
}

Point::~Point()
{
	return;
}

Point::Point(float const x, float const y) : x(Fixed(x)), y(Fixed(y))
{
	return ;
}

Point& Point::operator=(Point const &other){
	*this = Point(other);
	return (*this);
}

Point::Point(Point const & other): x(Fixed((other.get_x_f()).toFloat())), y(Fixed((other.get_y_f()).toFloat())){
	return;
}

float Point::get_x(void) const
{
	return this->x.toFloat();
}

float Point::get_y(void) const
{
	return this->y.toFloat();
}

Fixed Point::get_x_f(void) const
{
	return this->x;
}

Fixed Point::get_y_f(void) const
{
	return this->y;
}

bool Point::operator>(Point const &other)
{
	return this->x.toFloat() > other.x.toFloat();
}

std::ostream& operator<<(std::ostream &o, Point const &p)
{
	o << "x cordinate is: " <<  p.get_x() << "  y corinate is: " << p.get_y();
	return o;
}