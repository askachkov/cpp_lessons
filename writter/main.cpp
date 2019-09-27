#include <iostream>
#include "writer.h"

int main(int argc, char *argv[])
{
	std::cout << "\n writer" << std::endl;
	Writer wr(string("log.txt"));
	wr << "Hello twice again\n";
	wr << "Hello twice again\n";
	wr << "Hello twice again\n";
	wr << "Hello twice again\n";
	wr << "Hello twice again\n";
	wr << "Hello twice again\n";
	std::cout << wr << std::endl;
	std::cout << wr << std::endl;

	return 0;
}
