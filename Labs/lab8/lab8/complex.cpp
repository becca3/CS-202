#include "complex.h"
#include <iomanip>

Complex::Complex(double real, double imag)
	: real_(real), imag_(imag)
{

}

std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
	os << complex.realSec();
	os << " + i ";
	os << complex.imagSec();
	return os; 
}