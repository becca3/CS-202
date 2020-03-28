#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
public:
	Complex() {}
	Complex(double real, double imag = 0);

	Complex operator+(const Complex complex);

	double realSec() const { return real_; }
	double imagSec() const { return imag_; }

private:
	double real_{ 0 };
	double imag_{ 0 };
};

//inline means that wherever the compiler sees the funciton it inserts the definition automatically. 
inline Complex operator+(double lhs, const Complex rhs)
{
	return Complex(lhs + rhs.realSec(), rhs.imagSec());
}

std::ostream& operator<<(std::ostream& os, const Complex& complex);

#endif 
