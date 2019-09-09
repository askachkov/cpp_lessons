#include "complex.hpp"
#include <cmath>


Complex::Complex(): m_real(0), m_imag(0)
{
}

Complex::Complex(int real, int imag): m_real(real), m_imag(imag)
{
}

Complex::Complex(const Complex& obj): m_real(obj.m_real), m_imag(obj.m_imag)
{
}

Complex Complex::operator =(const Complex& obj)
{
	m_real = obj.m_real;
	m_imag = obj.m_imag;
	return *this;
}

Complex Complex::operator +(const Complex& obj)
{
	m_real += obj.m_real;
	m_imag += obj.m_imag;
	return *this;
}

Complex Complex::operator -(const Complex& obj)
{
	m_real -= obj.m_real;
	m_imag -= obj.m_imag;
	return *this;
}

Complex Complex::operator ++()
{
	m_real ++;
	m_imag ++;
	return *this;

}

Complex Complex::operator ++(int)
{
	Complex cntx(*this);
	this->operator++();
	return cntx;
}


Complex Complex::operator --()
{
	m_real --;
	m_imag --;
	return *this;
}

Complex Complex::operator --(int)
{
	Complex cntx(*this);
	this->operator--();
	return cntx;
}

bool Complex::operator ==(const Complex& obj) const
{
	if ((obj.m_real == m_real) || (obj.m_imag == m_imag))
		return true;
	return false;

}

bool Complex::operator !=(const Complex& obj) const
{
	return !this->operator==(obj);
}

bool Complex::operator >(const Complex& obj) const
{
	if (obj.length() > length())
	{
		return true;
	}
	return false;
}

bool Complex::operator <(const Complex& obj) const
{
	if (obj.length() < length())
	{
		return true;
	}
	return false;
}

Complex::operator int() const
{
	return m_real;
}

int Complex::operator [](int index) const
{
	std::cout << "\nConst []" <<std::endl;
	if(index == 0)
		return m_real;
	else if (index == 1)
		return m_imag;
	throw "Invalid index";
}

int Complex::operator [](int index)
{
	std::cout << "\nUnconst []" <<std::endl;
	if(index == 0)
		return m_real;
	else if (index == 1)
		return m_imag;
	throw "Invalid index";
}

Complex Complex::operator +=(const Complex& obj)
{
	Complex cntx(*this);
	cntx.m_real += obj.m_real;
    cntx.m_imag += obj.m_imag;
	return cntx;
}

Complex Complex::operator ~()
{
	int temp = m_real;
	m_real = m_imag;
	m_imag = temp;
	return *this;
}

int Complex::real() const
{
	return m_real;
}

int Complex::imag() const
{
	return m_imag;
}

std::ostream& operator<<(std::ostream &os, Complex const &cmpx)
{
	return os << "\nReal:\t" << cmpx.real() <<"\nImag:\t" << cmpx.imag() << std::endl;
}


Complex* Complex::operator->() const
{
	Complex *t = new Complex(0,0);
	return t;
}

void Complex::set(int real, int imag)
{
	m_real = real;
	m_imag = imag;
}


int Complex::length() const {
	return sqrt(pow(2, m_real) + pow(2, m_imag));
}
