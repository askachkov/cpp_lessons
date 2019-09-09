#include <iostream>

class Complex {
private:
	int m_real;
	int m_imag;
public:

	typedef void(Complex::*fnSet)(int, int);

	Complex(): m_real(0), m_imag(0) {}
	Complex(int real, int imag): m_real(real), m_imag(imag) {}
	Complex(const Complex& obj): m_real(obj.m_real), m_imag(obj.m_imag) {}

	Complex& operator =(const Complex& obj);
	Complex& operator +(const Complex& obj);
	Complex& operator -(const Complex& obj);
	Complex& operator ++();
	Complex operator ++(int);
	Complex& operator --();
	Complex operator --(int);
	bool operator ==(const Complex& obj);
	bool operator !=(const Complex& obj);
	bool operator >(const Complex& obj);
	bool operator <(const Complex& obj);
	operator int();
	int operator [](int index);
	Complex operator +=(const Complex& obj);
	Complex& operator ~();
	friend std::ostream& operator<<(std::ostream &os, Complex const &cmpx);
	Complex* operator->();
	int real() const;
	int imag() const;
	void set(int, int);

};
