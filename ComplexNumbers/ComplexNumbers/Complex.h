#ifndef _MY_COMPLEX_CLASS_H_
#define _MY_COMPLEX_CLASS_H_

#include <iostream>
#include <sstream>
#include <memory>
#include <cmath>

#define PI 3.14159265359

class Complex {
	double real;
	double img;
public:
	/********************
	 * MEMBER FUNCTIONS *
	 ********************/
	Complex() : real(0), img(0) { } // Default
	Complex(int r) : real(r), img(0) { }
	Complex(double r) : real(r), img(0) { }
	Complex(double r_, double i_) : real(r_), img(i_) { }
	Complex(const Complex& cplx) : real(cplx.real), img(cplx.img) { } // Copy
	Complex& operator=(const Complex& cplx); // Copy-Assignment
	Complex(Complex&& cplx); // Move
	Complex& operator=(Complex&& cplx); // Move-Assignment
	~Complex() {  }
	Complex complexFromPolar(double rho, double theta);
	double Real();
	double Img();
	double rho();
	double theta();
	std::string string();
	std::string stringCart();
	std::string stringPolar();

	/*************************
	 * OVERLOADED OPERATIONS *
	 *************************/
	friend std::ostream& operator<<(std::ostream& os, Complex& cplx) {
		os << cplx.string();
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Complex& cplx) { 
		std::string coords;
		std::getline(is, coords);
		if (!is)
			throw ("Bad stream!");

		std::string temp;
		for (unsigned i = 0; i != coords.length()-1; ++i) {
			if (coords[i] != ' ' && coords[i] != '+')
				 temp += coords[i];
			else if (coords[i] == ' ' && (coords[i+1] == '-' || coords[i+1] == '+')) // stream seperator
				temp.append(" ");
		}

		std::cout << temp << std::endl;
		
		std::stringstream ret(temp);
		ret >> cplx.real >> cplx.img;	
		return is;
	}
	
	friend inline bool operator==(const Complex& left, const Complex& right);
	friend inline bool operator!=(const Complex& left, const Complex& right);
	friend inline bool operator<(const Complex& left, const Complex& right);
	friend inline Complex operator+(const Complex& left, const Complex& right);
	friend inline Complex operator-(const Complex& left, const Complex& right);
	friend inline Complex operator*(const Complex& left, const Complex& right);
	friend inline Complex operator/(const Complex& left, const Complex& right);

	inline Complex& operator+=(const Complex& cplx);
	inline Complex& operator-=(const Complex& cplx);
	inline Complex& operator*=(const Complex& cplx);
	inline Complex& operator/=(const Complex& cplx);
}; /* END COMPLEXNUMBER CLASS */


/***********************
 * NONMEMBER FUNCTIONS *
 ***********************/
inline bool operator==(const Complex& left, const Complex& right) {
	return (right.real == left.real &&
			right.img == left.img);
}

inline bool operator!=(const Complex& left, const Complex& right) {
	return !(left == right);
}

inline bool operator<(const Complex& left, const Complex& right) {
	return ((left.real + left.img) < (right.real + right.img));
}

inline bool operator<=(const Complex& left, const Complex& right) {
	return (left < right || left == right);
}

inline bool operator>(const Complex& left, const Complex& right) {
	return !(left <= right);
}

inline bool operator>=(const Complex& left, const Complex& right) {
	return !(left < right);
}

inline Complex operator+(const Complex& left, const Complex& right) {
	Complex result = left;
	result.real += right.real;
	result.img += right.img;

	return result;
}

inline Complex operator-(const Complex& left, const Complex& right) {
	Complex result = left;
	result.real -= right.real;
	result.img -= right.img;

	return result;
}

inline Complex operator*(const Complex& left, const Complex& right) {
	Complex result;
	result.real = (left.real * right.real) - (left.img * right.img);
	result.img = (left.real * right.img) + (left.img * right.real);

	return result;
}

inline Complex operator/(const Complex& left, const Complex& right) {
	double num_real = (left.real * right.real) + (left.img * (-right.img));
	double num_img = (left.img * right.real) + (left.real * (-right.img));
	double denom = (left.real * left.real) + (right.img * right.img);

	Complex result((num_real / denom), (num_img / denom));
	return result;
}

#endif /* _MY_COMPLEX_CLASS_H_ */