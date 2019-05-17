#pragma once

#include "gtest/gtest.h"
#include <ostream>
#include <istream>

#define _USE_MATH_DEFINES
#define EPS 1e-9

#ifndef COMPLEX_COMPLEXNUM_H
#define COMPLEX_COMPLEXNUM_H

class Polar;

class Complex {
public:
	Complex(long double, long double);
	explicit Complex(long double);
	Complex();
	explicit Complex(Polar);

	long double re() const;
	long double im() const;
	void re(long double);
	void im(long double);

	~Complex() = default;

	long double my_sqr() const;

	bool operator==(const Complex&) const;

	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, const Complex&);
	friend Complex operator/(const Complex&, const Complex&);

	long double abs() const;
	long double arg() const;

	friend Complex pow(const Complex&, uint32_t);
private:
	long double real, imag;
};

class Polar {
public:
	Polar(long double, long double);
	Polar();
	explicit Polar(Complex);

	long double r() const;
	long double p() const;
	void r(long double);
	void p(long double);

	~Polar() = default;

	bool operator==(const Polar&) const;

	friend Polar operator+(const Polar&, const Polar&);
	friend Polar operator-(const Polar&, const Polar&);
	friend Polar operator*(const Polar&, const Polar&);
	friend Polar operator/(const Polar&, const Polar&);

	friend Polar pow(Polar, uint32_t);
private:
	long double rho, phi;
};

#endif