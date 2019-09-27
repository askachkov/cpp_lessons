#pragma once
#include <iostream>


class T {
private :
	int x ,y;
public:
	T();
	friend std::ostream& operator <<(std::ostream &, const T& );
};


std::ostream& operator<<(std::ostream &os, const T& t);
