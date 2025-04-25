#include "complex.h"


complex::complex() {}

complex::complex(double num1) : real(num1) {}

complex::complex(double num1, double numI) : real(num1), imaginary(numI) {}

complex::~complex()
{
}

const double complex::getReal() const
{
	//return real number
	return real;
}

const double complex::getImaginary() const
{
	//return imaginary number
	return imaginary;
}

void complex::setReal(double num)
{
	//set real to num
	real = num;
}

void complex::setImaginary(double num)
{
	//set imaginary to num
	imaginary = num;
}

complex complex::operator+(const complex& comp)
{
	//return a new complex with the current real and imaginary added to comp's
	//(a + ib) + (c + id) = (a + c) + i(b + d)
	return complex(comp.real + real, comp.imaginary + imaginary);
}

complex complex::operator-(const complex& comp)
{
	//return a new complex with comp's real and imaginary being subtracted from this'
	// (a + ib) - (c + id) = (a - c) + i(b - d)
	return complex(real - comp.real, imaginary - comp.imaginary);
}

complex complex::operator*(const complex& comp)
{
	//return a new complex with comp's real and imaginary being multiplied with this' real and imaginary
	//(a + ib) (c + id) = (ac - bd) + i(ad + bc)
	return complex( (real * comp.real) - (imaginary * comp.imaginary), (real * comp.imaginary) + (imaginary * comp.real));
}

complex complex::operator/(const complex& comp)
{
	//check for denominator being 0, if so print error and return lhs
	if (comp.real == 0 && comp.imaginary == 0)
	{
		std::cout << "Error: Division by zero." << std::endl;
		return complex();
	}
	//if not dividing by 0 then continue
	
	//get the numerator and denominator functions for readability
	complex num = *this;
	complex den = comp;
	
	//multiply numerator and denominator by the complex conjugate
	num = (num * den.conjugate());
	//get the real number denominator since the imaginary squared is 1, ergo now real num with squared value
	double realDen = (den.real * den.real) + (den.imaginary * den.imaginary);

	

	//return the fraction with real and imaginary divided by the realDen
	return complex(num.real / realDen, num.imaginary / realDen);
}

complex complex::conjugate()
{
	//return the conjugate
	//the complex conjugate of a + bi is a - bi
	return complex(real, -imaginary);
}

bool complex::operator==(const complex& comp) const
{
	//if match return true, else false
	return (real == comp.real && imaginary == comp.imaginary);
}

bool complex::operator!=(const complex& comp) const
{
	//if not match return true, else false
	return (real != comp.real || imaginary != comp.imaginary);
}

complex& complex::operator=(const complex& comp)
{
	//copy over data from comp
	real = comp.real;
	imaginary = comp.imaginary;
	return *this;
}

complex& complex::operator*=(const complex& comp)
{
	//multiply this and comp and return it
	*this = *this * comp;
	return *this;
}

complex& complex::operator/=(const complex& comp)
{
	//divide this and comp and return it
	*this = *this / comp;
	return *this;
}

complex& complex::operator-=(const complex& comp)
{
	//subtract this and comp and return it
	*this = *this - comp;
	return *this;
}

complex& complex::operator+=(const complex& comp)
{
	//add this and comp and return it
	*this = *this + comp;
	return *this;
}

std::ostream& operator<<(std::ostream& outStream, const complex& comp)
{
	//get the numbers seperate to perform logic
	const double r = comp.getReal();
	const double i = comp.getImaginary();
	//if both 0 print 0
	if (r == 0 && i == 0)
	{
		outStream << 0;
	}
	//if real is 0 print just imaginary i
	else if(r == 0)
	{
		outStream << i << "i";
	}
	//if imaginary is 0 print just real
	else if (i == 0)
	{
		outStream << r;
	}
	//if imaginary less than 0 then do not print "+" sign, real-imaginaryi
	else if (i < 0)
	{
		outStream << r << i << "i";
	}
	else
	//if output has positive imaginary and all are non 0 then output real+imaginary i
	{
		outStream << r << "+" << i << "i";
	}
	return outStream;
}

std::istream& operator>>(std::istream& inStream, complex& comp)
{
	//create vars for input
	double r;
	double i;
	//get input
	inStream >> r >> i;
	//set variables
	comp.setReal(r);
	comp.setImaginary(i);
	return inStream;
}
