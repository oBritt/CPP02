
#include "triangle.hpp"


int main()
{
	Point p1(-9.86f, -1.57f);
	Point p2(-1.3f, 3.01f);
	Point p3(9.6f, 5.17f);

	Point p4(-6.0f, 0.0f);
	std::cout << bsp(p1, p2, p3, p4);
}
