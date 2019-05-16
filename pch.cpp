#include "pch.h"
#include <cmath>
#include <string>

//Complex class
Complex::Complex(long double _re, long double _im) : real(_re), imag(_im) {}

Complex::Complex(long double _val) : real(_val), imag(0) {}

Complex::Complex() : real(0), imag(0) {}

Complex::Complex(Polar n) {
	real = n.r() * cosl(n.p());
	imag = n.r() * sinl(n.p());
}


long double Complex::re() const {
	return this->real;
}

long double Complex::im() const {
	return this->imag;
}

void Complex::re(long double _val) {
	real = _val;
}

void Complex::im(long double _val) {
	imag = _val;
}


long double Complex::my_sqr() const {
	return real * real + imag * imag;
}


bool Complex::operator==(const Complex &_c) const {
	return fabsl(real - _c.real) < EPS && fabsl(imag - _c.imag) < EPS;
}


Complex operator+(const Complex &_cLeft, const Complex &_cRight) {
	Complex c = Complex(_cLeft.real + _cRight.real, _cLeft.imag + _cRight.imag);
	return c;
}

Complex operator-(const Complex &_cLeft, const Complex &_cRight) {
	Complex c = Complex(_cLeft.real - _cRight.real, _cLeft.imag - _cRight.imag);
	return c;
}

Complex operator*(const Complex &_cLeft, const Complex &_cRight) {
	long double real = (_cLeft.real * _cRight.real - _cLeft.imag * _cRight.imag);
	long double imag = (_cLeft.real * _cRight.imag + _cLeft.imag * _cRight.real);
	return Complex(real,  imag);
}

Complex operator/(Complex _cLeft, const Complex &_cRight) {
	long double denominator = (_cRight.real * _cRight.real + _cRight.imag * _cRight.imag);
	long double real = ((_cLeft.real * _cRight.real + _cLeft.imag * _cRight.imag) / denominator);
	long double imag = ((_cLeft.imag * _cRight.real - _cLeft.real * _cRight.imag) / denominator);
	return Complex(real, imag);
}

long double Complex::abs() const {
	return sqrtl(my_sqr());
}

long double Complex::arg() const {
	return atan2l(imag, real);
}

Complex pow(const Complex &x, uint32_t y) {
	return Complex(pow(Polar(x), y));
}


//Polar Class
Polar::Polar(long double _rho, long double _phi) : rho(_rho), phi(_phi) {}

Polar::Polar() : rho(0), phi(0) {}

Polar::Polar(Complex n) {
	rho = n.abs();
	phi = n.arg();
}


long double Polar::r() const {
	return rho;
}

long double Polar::p() const {
	return phi;
}

void Polar::r(long double _val) {
	rho = _val;
}

void Polar::p(long double _val) {
	phi = _val;
}

bool Polar::operator==(const Polar &_val) const {
	return Complex(*this) == Complex(_val);
}

Polar operator+(const Polar &_pLeft, const Polar &_pRight) {
	return Polar(Complex(_pLeft) + Complex(_pRight));
}

Polar operator-(const Polar &_pLeft, const Polar &_pRight) {
	return Polar(Complex(_pLeft) - Complex(_pRight));
}

Polar operator*(Polar _pLeft, const Polar &_pRight) {
	return Polar(Complex(_pLeft) * Complex(_pRight));
}

Polar operator/(Polar _pLeft, const Polar &_pRight) {
	return Polar(Complex(_pLeft) / Complex(_pRight));
}


Polar pow(Polar x, uint32_t y) {
	x.r(powl(x.r(), y));
	x.p(x.p() * y);
	return Polar(Complex(x));
}