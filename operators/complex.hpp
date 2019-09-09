#pragma once

#include <iostream>

class Complex {
private:
	int m_real;
	int m_imag;

	int length() const;
public:

	typedef void(Complex::*fnSet)(int, int);

	Complex();
	Complex(int real, int imag);
	Complex(const Complex& obj);

	Complex operator =(const Complex& obj);
	Complex operator +(const Complex& obj);
	Complex operator -(const Complex& obj);
	Complex operator ++();
	Complex operator ++(int);
	Complex operator --();
	Complex operator --(int);
	bool operator ==(const Complex& obj) const;
	bool operator !=(const Complex& obj) const;
	bool operator >(const Complex& obj) const;
	bool operator <(const Complex& obj) const;
	operator int() const;
	int operator [](int index) const;
	int operator [](int index);
	Complex operator +=(const Complex& obj);
	Complex operator ~();
	Complex* operator->() const;
	int real() const;
	int imag() const;
	void set(int, int);

};

std::ostream& operator<<(std::ostream &os, Complex const &cmpx);
