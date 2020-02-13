#include <iostream>
#include "complex.hpp"


int main(int argc, char *argv[])
{
	Complex *pA = new Complex(0, 0);

	Complex::fnSet setter = &Complex::set;

	std::cout << pA->real() << std::endl;

	(pA->*setter)(1, 1);

	std::cout << pA->real() << std::endl;

	Complex a,b(2,3),c;

	std::cout << a;

	int b_real = b[0];

	std::cout << std::endl << b_real << std::endl;

	const Complex g(5,6);
	int b_rel = g[1];

	std::cout << std::endl << b_real << std::endl;

	std::cout << b_rel;

	std::cout << g << b;

	std::cout << (g > b) << std::endl;
	return 0;
}
