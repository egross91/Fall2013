#include "Complex.h"

/* Copy-Assignment */
Complex& Complex::operator=(const Complex& cplx) 
{
	this->real = cplx.real;
	this->img = cplx.img;

	return *this;
}

/* Move Constructor */
Complex::Complex(Complex&& cplx)
{
	this->real = cplx.real;
	this->img = cplx.img;

	cplx.real = cplx.img = 0;
}

/* Move-Assignment */
Complex& Complex::operator=(Complex&& cplx) 
{
	if (*this != cplx) {
		this->real = cplx.real;
		this->img = cplx.img;

		cplx.real = cplx.img = 0;
	}
	return *this;
}

Complex Complex::complexFromPolar(double rho, double theta) 
{
	Complex result;
	result.real = (rho * std::cos(theta));
	result.img = (rho * std::sin(theta));

	return result;
}

double Complex::Real()
{
	return this->real;
}

double Complex::Img()
{
	return this->img;
}

double Complex::rho() 
{
	double a_sqrd = this->real * this->real;
	double b_sqrd = this->img * this->img;
	double sum_sqrd = a_sqrd + b_sqrd;

	return std::sqrt(sum_sqrd);
}

double Complex::theta()
{
	double a = this->real;
	double b = this->img;
	double quo_ab = a / b;

	return std::atan(quo_ab);
}

std::string Complex::string() 
{
	std::stringstream ret;
	ret << this->real;
	if (this->img < 0) {
		ret << " - ";
		ret << -this->img;
	}
	else { // (this->img >= 0)
		ret << " + ";
		ret << this->img;
	}
	ret << " i";

	return ret.str();
}

std::string Complex::stringCart()
{
	std::stringstream ret;

	ret <<"(" << this->real << "," << this->img << ")";
	
	return ret.str();
}

std::string Complex::stringPolar()
{
	std::stringstream ret;

	ret << "(" << this->real << "," << this->img << ")";
	
	return ret.str();
}

/************************
 * OVERLOADED OPERATORS *
 ************************/
inline Complex& Complex::operator+=(const Complex& cplx) {
	real += cplx.real;
	img += cplx.img;

	return *this;
}

inline Complex& Complex::operator-=(const Complex& cplx) {
	real -= cplx.real;
	img -= cplx.img;

	return *this;
}

inline Complex& Complex::operator*=(const Complex& cplx) {
	*this = (*this * cplx);

	return *this;
}

inline Complex& Complex::operator/=(const Complex& cplx) {
	*this = (*this / cplx);

	return *this;
}