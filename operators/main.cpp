#include <iostream>
#include "complex.hpp"


int main(int argc, char *argv[])
{
	Complex a(1,2);
	Complex b(3,4);
	std::cout << a << b << a + b;
	a++;
	++b;
	std::cout << a << b << a + b;
	std::cout<<"Hello world"<<std::endl;
	return 0;
}
