#include "complex.h"
#include <iomanip>

Complex::Complex(double real, double imag)
	: real_(real), imag_(imag)
{

}

Complex Complex::operator+(const Complex complex)
{
	return Complex(real_ + complex.real_,
		imag_ + complex.imag_);
}

//My subtraction operator
Complex& Complex::operator-=(const Complex complex)
{
	Complex(real_ -= complex.real_,
		imag_ -= complex.imag_);
	return *this;
}

Complex& Complex::operator+=(const Complex complex)
{
	*this = *this + complex;
	/*real_ += complex.real_;
	imag_ += complex.imag_;*/
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
	os << complex.realSec();
	os << " + i ";
	os << complex.imagSec();
	return os; 
}