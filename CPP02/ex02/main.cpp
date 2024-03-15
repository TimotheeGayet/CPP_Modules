#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a( 3.5f );
	Fixed b( 2.5f );

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	std::cout << "a + b: " << a + b << std::endl;
	std::cout << "a - b: " << a - b << std::endl;
	std::cout << "a * b: " << a * b << std::endl;
	std::cout << "a / b: " << a / b << std::endl;
	
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;
	
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;

	return 0;
}