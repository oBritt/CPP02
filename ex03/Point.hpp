
#ifndef POINT_HPP
#define POINT_HPP

#include "triangle.hpp"

class Point{
private:
	Fixed const x;
	Fixed const y;

public:
	Point();
	~Point();
	Point(Point const &other);
	Point& operator=(Point const &other);
	Point(float const x, float const y);
	float get_x(void) const;
	float get_y(void) const;
	Fixed get_x_f(void) const;
	Fixed get_y_f(void) const;
	bool operator>(Point const &other);
};

std::ostream& operator<<(std::ostream &o, Point const &p);


#endif