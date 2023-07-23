#include"Fraction.h"

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICALS_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define INPUT_CHECK_1
//#define INPUT_CHECK_2
//#define	CONVERSION_FROM_OTHER_TO_CLASS
#define CONVERSION_FROM_CLASS_TO_OTHER


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
	Fraction A(4, 5);
	A.print();

	Fraction B(3, 4);
	B.print();

	Fraction C = A + B;
	C.print();

	A /= B;
	A.print();
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

	/*--A;
	++B;
	A.print();
	B.print();*/

#endif // ARITHMETICALS_OPERATORS_CHECK

#ifdef COMPARISON_OPERATORS_CHECK
	Fraction A(1, 2);
	Fraction B(5, 10);
	cout << (A <= B) << endl;
#endif // COMPARISON_OPERATORS_CHECK

#ifdef INPUT_CHECK_1
	Fraction A(840, 3600);
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
	A.reduce();
	cout << A << endl;
#endif // INPUT_CHECK_1

#ifdef INPUT_CHECK_2
	Fraction A, B, C;
	cout << "Введите три простые дроби: "; cin >> A >> B >> C;
	cout << A << "\t" << B << "\t" << C << endl;
#endif // 

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	Fraction A = Fraction(5);
	cout << A << endl;
	cout << delimiter << endl;
	Fraction B; // Default constructor
	cout << delimiter << endl;
	B = Fraction(8);
	cout << delimiter << endl;
	cout << B << endl;

	//Fraction C = 12; // explicit constrctor невозможно вызвать операцией присваивания
	//Fraction C(12); // explicit constrctor можно вызвать только так
	Fraction C{ 12 }; // или так
	cout << C << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS

#ifdef CONVERSION_FROM_CLASS_TO_OTHER
	Fraction A(2, 1, 2);
	cout << A << endl;
	int a = (int)A;
	cout << a << endl;

	Fraction B(2, 3, 4);
	cout << B << endl;
	double b = double(B);
	cout << b << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER

	//Fraction A = 2.76;
	//cout << A << endl;
}