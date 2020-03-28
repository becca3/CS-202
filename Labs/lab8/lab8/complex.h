#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
public:
	Complex() {}
	Complex(double real, double imag = 0);

	double realSec() const { return real_; }
	double imagSec() const { return imag_; }

private:
	double real_{ 0 };
	double imag_{ 0 };
};

std::ostream& operator<<(std::ostream& os, const Complex& complex);

#endif 
