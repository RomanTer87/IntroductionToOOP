#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;

#define delimiter "\n------------------------------------------------\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer(void)const;
	int get_numerator(void)const;
	int get_denominator(void)const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	Fraction();
	explicit Fraction(int integer);
	Fraction(double decimal);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	~Fraction();

	Fraction(const Fraction& other);

	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator--();
	Fraction operator--(int);
	Fraction& operator++();
	Fraction operator++(int);
	//		Type-cast operators
	explicit operator int()const;
	explicit operator double()const;

	//		Methods
	void to_improper();
	void to_proper();
	Fraction& reduce();
	void print()const;
	Fraction inverted()const;
};
std::ostream& operator<<(std::ostream& os, const Fraction& obj);
