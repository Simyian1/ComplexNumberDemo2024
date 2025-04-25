#pragma once

#include <iostream>

class complex
{
public:
	complex();
	complex(double num1);
	complex(double num1, double numI);
	~complex();

	//gets the real part of the complex as a double
	const double getReal() const;
	//gets the imaginary part of the complex as a double
	const double getImaginary() const;
	//sets the real part of the complex as a double
	void setReal(double num);
	//sets the imaginary part of the complex as a double
	void setImaginary(double num);

	//Performs basic arithmatic on complex number
	//(a + ib) + (c + id) = (a + c) + i(b + d)
	complex operator+(const complex& comp);
	// (a + ib) - (c + id) = (a - c) + i(b - d)
	complex operator-(const complex& comp);
	//(a + ib) (c + id) = (ac - bd) + i(ad + bc)
	complex operator*(const complex& comp);
	complex operator/(const complex& comp);

	//the complex conjugate of a + bi is a - bi
	complex conjugate();

	//if equal return true
	bool operator==(const complex& comp) const;
	//if not equal return false
	bool operator!=(const complex& comp) const;
	
	//return a copy of comp to the lhs
	complex& operator=(const complex& comp);
	//return a copy of lhs * rhs
	complex& operator*=(const complex& comp);
	//return a copy of lhs / rhs
	complex& operator/=(const complex& comp);
	//return a copy of lhs - rhs
	complex& operator-=(const complex& comp);
	//return a copy of lhs + rhs
	complex& operator+=(const complex& comp);

private:
	double real = 0.0;
	double imaginary = 0.0;
};

//outstream function using getters
std::ostream& operator<<(std::ostream& outStream, const complex& comp);
//instream function using setters
std::istream& operator>>(std::istream& inStream, complex& comp);
