#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
	Complex() {}
	Complex(double real, double imag = 0);

private:
	double real_{ 0 };
	double imag_{ 0 };
};

#endif 
