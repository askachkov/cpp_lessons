#include "test.h"

using namespace std;

T::T():x(44), y(23) {}

ostream& operator<<(ostream &os, const T& t)
{
	return os << "\n x\t" << t.x << "\n y\t" << t.y;
}
