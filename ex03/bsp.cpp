
#include "triangle.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (a.get_x() == b.get_x() && c.get_x() == a.get_x())
	{
		std::cout << "not a triangle" << std::endl;
		return (0);
	}
	if (a.get_y() == b.get_y() && c.get_y() == a.get_y())
	{
		std::cout << "not a triangle" << std::endl;
		return (0);
	}
	if (a.get_y() == b.get_y() && a.get_x() == b.get_x())
	{
		std::cout << "not a triangle" << std::endl;
		return (0);
	}
	if (a.get_y() == c.get_y() && a.get_x() == c.get_x())
	{
		std::cout << "not a triangle" << std::endl;
		return (0);
	}
	if (b.get_y() == c.get_y() && b.get_x() == c.get_x())
	{
		std::cout << "not a triangle" << std::endl;
		return (0);
	}
	float x1 = b.get_x() - a.get_x();
	float x2 = c.get_x() - a.get_x();
	float y1 = b.get_y() - a.get_y();
	float y2 = c.get_y() - a.get_y();
	float x3 = point.get_x() - a.get_x();
	float y3 = point.get_y() - a.get_y();

	float r;
	float s;

	if (x1 == 0.0 && y2 == 0.0)
	{
		r = x3 / x2;
		s = y3 / y1;
	}
	else if (x2 == 0.0 && y1 == 0.0)
	{
		s = x3 / x1;
		r = y3 / y2;
	}
	else if (x1 == 0.0)
	{
		r = x3 / x2;
		s = (y3 - r * y2) / y1;
	}
	else
	{
		r = (x3 * y1 - y3 * x1) / (x2 * y1 - y2 * x1);
		s = (x3 - r * x2) / x1;
	}
	return (r > 0 && s > 0 && r + s < 1);
}