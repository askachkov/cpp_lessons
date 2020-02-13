#include <iostream>
#include <string>
#include "optional.hpp"


int main(int argc, char *argv[])
{
	optional::Optional<int> a(1), b(1);
	optional::Optional<int> c = a / b;
	c.show();
	a.show();
	b.show();
	std::cout << "\n c equals to a " <<  ((c == a) ? "True" : "False") << std::endl;
	return 0;
}
