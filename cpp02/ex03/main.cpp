#include "Point.hpp"

int main ( void ) {

    bool result;

	Point const a(0, 0);
	Point const b(6, 0);
	Point const c(3, 6);
	Point d;
	d = a;//does assignment op overload work??

    Point const isInside(3, 1);
    Point const isOutside(8, 8);
    Point const isOnEdge(3, 0);

	std::cout << "CASE 1: point inside triangle:" << std::endl;
	std::cout << bsp(a, b, c, isInside) << std::endl;
	std::cout << "CASE 2: point outside triangle:" << std::endl;
	result = bsp(a, b, c, isOutside);
    std::cout << result << std::endl;
	std::cout << "CASE 3: point on edge:" << std::endl;
	result = bsp(a, b, c, isOnEdge);
    std::cout << result << std::endl;
	std::cout << "CASE 4: point on vertex:" << std::endl;
	result = bsp(a, b, c, d);
    std::cout << result << std::endl;

	return (0);
}