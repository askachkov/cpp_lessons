#include "complex.hpp"

//function prototypes was reviewed in hpp

Complex& Complex::operator =(const Complex& obj)
{
	m_real = obj.m_real;
	m_imag = obj.m_imag;
	return *this;
}

Complex& Complex::operator +(const Complex& obj)
{
	m_real += obj.m_real;
	m_imag += obj.m_imag;
	return *this;
}

Complex& Complex::operator -(const Complex& obj)
{
	m_real -= obj.m_real;
	m_imag -= obj.m_imag;
	return *this;
}

Complex& Complex::operator ++()
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


Complex& Complex::operator --()
{
	m_real ++;
	m_imag ++;
	return *this;
}

Complex Complex::operator --(int)
{
	Complex cntx(*this);
	this->operator--();
	return cntx;
}

bool Complex::operator ==(const Complex& obj)
{
// 	if ((obj.m_real == m_real) || (obj.m_imag == m_imag))
// 		return true;
// 	return false;
	return obj.m_real == m_real && obj.m_imag == m_imag; // && ?
}

bool Complex::operator !=(const Complex& obj)
{
	return !this->operator==(obj);
}

bool Complex::operator >(const Complex& obj)
{
	//комплексные числа нельзя сравнивать на больше/меньше; 
	//доказано, что нет способа распространить порядок, заданный
	//для вещественных чисел, на все комплексные так, чтобы 
	//порядок был согласован с арифметическими операциями 
	//Однако комплексные числа можно сравнивать на равно/не равно
	
	//As example - OK
	if ((obj.m_real + obj.m_imag) > (m_real + m_imag))
	{
		return true;
	}
	return false;
}

bool Complex::operator <(const Complex& obj)
{
	// no no ) It return true is a==b
	//return !this->operator>(obj);
	//In case if complex numbers can be comparable = should be
	return (obj.m_real + obj.m_imag) < (m_real + m_imag);
}

Complex::operator int()
{
	return m_real;
}

int Complex::operator [](int index)
{
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

Complex& Complex::operator ~()
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

//this prototype must be definedin cpp file.
std::ostream& operator<<(std::ostream &os, Complex const &cmpx)
{
	return os << "\nReal:\t" << cmpx.real() <<"\nImag:\t" << cmpx.imag() << std::endl;
}


Complex* Complex::operator->()
{
	Complex *t = new Complex(0,0);
	return t;
}

void Complex::set(int real, int imag)
{
	m_real = real;
	m_imag = imag;
}
