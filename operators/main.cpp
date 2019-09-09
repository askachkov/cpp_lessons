#include <iostream>
#include "complex.hpp"


int main(int argc, char *argv[])
{
	Complex *pA = new Complex(0, 0);

	Complex::fnSet setter = &Complex::set;

	std::cout << pA->real() << std::endl;

	(pA->*setter)(1, 1);

	std::cout << pA->real() << std::endl;

	return 0;
}
