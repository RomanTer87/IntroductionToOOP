#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer(void)const
	{
		return integer;
	}
	int get_numerator(void)const
	{
		return numerator;
	}
	int get_denominator(void)const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//				Constructors
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructr:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}

	//		Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old(*this);
		integer--;
		return old;
	}
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old(*this);
		integer++;
		return old;
	}
	


	//		Methods
	void to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
	}
	void to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
	}
	Fraction& reduce()
	{
		/*int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;*/
		to_proper();
		int less = numerator;
		int more = denominator;
		int rest;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; // GCD - Greatest Common Divisor (���������� ����� ��������)
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()const
	{
		if (integer)cout << integer; // ���� ���� ����� �����, ������� � �� �����
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		std::swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
}
Fraction operator/(const Fraction& left,const Fraction& right)
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
//#define CONSTRUCTORS_CHECK
//#define ARITHMETICALS_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");


#ifdef CONSTRUCTORS_CHECK
	Fraction A; // Default constructor
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = C; // CopyConstructor
	E.print();

	Fraction F; // CopyAssignmeent
	F = D;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICALS_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	/*A.to_improper();
	A.print();

	A.to_proper();
	A.print();*/

	/*Fraction C = A / B;
	C.print();

	Fraction D = A / B;
	D.print();*/

	/*A *= B;
	A.print();*/

	--A;
	++B;
	A.print();
	B.print();
#endif // ARITHMETICALS_OPERATORS_CHECK

#ifdef COMPARISON_OPERATORS_CHECK
	Fraction A(1, 2);
	Fraction B(5, 10);
	cout << (A <= B) << endl;
#endif // COMPARISON_OPERATORS_CHECK

	Fraction A(840, 3600);
	A.print();
	A.reduce();
	A.print();

}