#include <iostream>

class Complex 
{
private:
	int m_real; // OK
	int m_imag; // OK. I used to name like "m_Imag" & "m_Real"
public:

	typedef void(Complex::*fnSet)(int, int);

	Complex(): m_real(0), m_imag(0) {}// should be in cpp
	Complex(int real, int imag): m_real(real), m_imag(imag) {}// should be in cpp
	Complex(const Complex& obj): m_real(obj.m_real), m_imag(obj.m_imag) {} // should be in cpp

	Complex& operator =(const Complex& obj); //OK
	Complex& operator +(const Complex& obj); //Better return object and make this method const - do not change internal state
	Complex& operator -(const Complex& obj); //Better return object and make this method const - do not change internal state
	Complex& operator ++(); // Returning reference - wrong, because different with next method ( ++() ).
	Complex operator ++(int); // Returning object - right
	Complex& operator --(); // Returning reference - wrong, because different with next method ( --() ).
	Complex operator --(int); // Returning object - right
	bool operator ==(const Complex& obj);// should be method const
	bool operator !=(const Complex& obj);// should be method const
	bool operator >(const Complex& obj);// should be method const
	bool operator <(const Complex& obj);// should be method const
	operator int(); // should be method const
	int operator [](int index); // OK
	Complex operator +=(const Complex& obj); // OK
	Complex& operator ~(); //In case of this class - const method that returning object better then returning refecrence. = Complex operator ~() const;
	friend std::ostream& operator<<(std::ostream &os, Complex const &cmpx); //Friend it's a bad practice. Better solution is to get access for all feilds thru public methods.
	Complex* operator->();//should has const "pair" => 
		//const Complex* operator->()const;
	int real() const; // OK
	int imag() const; // OK
	void set(int, int); // OK, but needs arguments names = what is real & imag?

};
