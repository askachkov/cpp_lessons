#include <iostream>
#include <exception>


using namespace std;

class FooExcept : public exception {
public:
	virtual const char *what() const throw() {
		return "Foo exception";
	}
};

class TooExcept : public exception {
public:
	virtual const char *what() const throw() {
		return "Too exception";
	}
};

class BooExcept : public exception {
public:
	virtual const char *what() const throw() {
		return "Boo exception";
	}
};

class CooExcept : public exception {
public:
	virtual const char *what() const throw() {
		return "Coo exception";
	}
};

class Description {
public:
	Description() {
		cout << "Description instance has been created" << endl;
	}

	virtual const char *what() const throw() {
		return "Coo exception";
	}
};

class Cause {
public:
	void foo()
	{
		throw FooExcept();
	}
	void boo()
	{
		throw BooExcept();
	}
	void Too()
	{
		throw TooExcept();
	}
	void coo()
	{
		throw CooExcept();
	}
	void des()
	{
		throw Description();
	}
};

int main(int argc, char *argv[])
{
	Cause cs;
	try {
		try {
			cs.des();
			cs.boo();
			cs.foo();
			cs.boo();
		}
		catch(FooExcept &fo) {
			cout << "Paricular: " <<fo.what() <<std::endl;
		}
	}
	catch (exception &ex){
		cout << "General: " <<ex.what() <<std::endl;
	}

	cout << "Finished succesfully" << std::endl;
	return 0;
}
