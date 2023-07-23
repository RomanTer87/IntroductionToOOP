#include"Fraction.h"
int Fraction::get_integer(void)const
{
	return integer;
}
int Fraction::get_numerator(void)const
{
	return numerator;
}
int Fraction::get_denominator(void)const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
//				Constructors
Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "DefaultConstructor:" << this << endl;
}
Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "1ArgConstructor:" << this << endl;
}
Fraction::Fraction(double decimal)
{
	decimal += 1e-10;
	integer = decimal;
	decimal -= integer;
	denominator = 1e+9; // точность всегда будет 9 знаков после запятой
	numerator = decimal * denominator;
	reduce();
	cout << "1ArgConstructor:\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	set_denominator(denominator);
	cout << "Constructor:\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	set_denominator(denominator);
	cout << "Constructr:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t" << this << endl;
}

Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor:\t" << this << endl;
}

//		Operators:
Fraction& Fraction:: operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction:: operator--()
{
	integer--;
	return *this;
}
Fraction Fraction:: operator--(int)
{
	Fraction old(*this);
	integer--;
	return old;
}
Fraction& Fraction::operator++()
{
	integer++;
	return *this;
}
Fraction Fraction:: operator++(int)
{
	Fraction old(*this);
	integer++;
	return old;
}
//		Type-cast operators
Fraction:: operator int()const
{
	return integer;
}
Fraction:: operator double()const
{
	return integer + (double)numerator / denominator;
}

//		Methods
void Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
}
void Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
}
Fraction& Fraction::reduce()
{
	/*int more, less, rest;
	if (numerator > denominator)more = numerator, less = denominator;
	else less = numerator, more = denominator;*/
	to_proper();
	int less = numerator;
	int more = denominator;
	int rest;
	if (less == 0)return *this;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more; // GCD - Greatest Common Divisor (наибольший общий делитель)
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}
void Fraction::print()const
{
	if (integer)cout << integer; // если есть целая часть, выводим её на экран
	if (numerator)
	{
		if (integer)cout << "(";
		cout << numerator << "/" << denominator;
		if (integer)cout << ")";
	}
	else if (integer == 0)cout << 0;
	cout << endl;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	std::swap(inverted.numerator, inverted.denominator);
	return inverted;
}

Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	{
		(left.get_numerator() * right.get_denominator()) + (right.get_numerator() * left.get_denominator()),
		left.get_denominator() * right.get_denominator()
	};
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	{
		(left.get_numerator() * right.get_denominator()) - (right.get_numerator() * left.get_denominator()),
		left.get_denominator() * right.get_denominator()
	};
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	);*/
	return left * right.inverted();
}
Fraction& operator+=(Fraction& left, Fraction& right)
{
	left = left + right;
	return left;
}
Fraction& operator-=(Fraction& left, Fraction& right)
{
	left = left - right;
	return left;
}
Fraction& operator/=(Fraction& left, Fraction& right)
{
	left = left / right;
	return left;
}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	left.to_improper();
	/*if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())
		return true;
	else
		return false;*/
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction left, const Fraction right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction left, const Fraction right)
{
	//return left > right || left == right;
	return !(left < right);
}
bool operator<= (const Fraction left, const Fraction right)
{
	//return left > right || left == right;
	return !(left > right);
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer(); // если есть целая часть, выводим её на экран
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	const int SIZE = 256;
	char buffer[SIZE] = {};
	cin >> buffer;
	int number[3] = {};
	int n = 0; // счетчик введенных чисел
	char delimiters[] = "()/";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		number[n++] = std::atoi(pch);
	switch (n)
	{
	case 1: obj.set_integer(number[0]); break;
	case 2:
		obj.set_numerator(number[0]);
		obj.set_denominator(number[1]);
		break;
	case 3:
		obj.set_integer(number[0]);
		obj.set_numerator(number[1]);
		obj.set_denominator(number[2]);
	}
	return is;
}