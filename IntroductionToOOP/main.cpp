#include<iostream>
using namespace std;

#define delimiter "\n________________________________________________________\n"
class Point
{
	double x;
	double y;
public:
	double get_x(void)const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//			Constructors:
	/*Point()
	{
		x = y = double(); //double() - это значение по умолчанию для заданного типа
							// таким образом мы якобы вызываем констурктор по умолчанию для заданного типа.
		cout << "DefaultConstructor;\t\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//			Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Point& operator++()  // Prefix increment
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this;  // сохраняем исходное значение объекта
		x++;
		y++;
		return old;
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	Point& operator-=(const Point& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}
	Point& operator*=(const Point& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}
	Point& operator/=(const Point& other)
	{
		this->x /= other.x;
		this->y /= other.y;
		return *this;
	}
	//			Methods:
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};
// _______________Конец класса_____________________

// ______________ФУНКЦИИ__________________________
Point operator + (const Point& left, const Point& right)
{
	/*Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());*/

	/*Point result(left.get_x() + right.get_x(), left.get_y() + right.get_y());
	return result;*/

	return Point
	(
		left.get_x() + right.get_x(),
		left.get_y() + right.get_y()
	);
}Point operator - (const Point& left, const Point& right)
{
	return Point
	(
		left.get_x() - right.get_x(),
		left.get_y() - right.get_y()
	);
}
Point operator * (const Point& left, const Point& right)
{
	return Point
	(
		left.get_x() * right.get_x(),
		left.get_y() * right.get_y()
	);
}
Point operator / (const Point& left, const Point& right)
{
	return Point
	(
		left.get_x() / right.get_x(),
		left.get_y() / right.get_y()
	);
}
Point operator % (const Point& left, const Point& right)
{
	return Point
	(
		(int)left.get_x() % (int)right.get_x(),
		(int)left.get_y() % (int)right.get_y()
	);
}
ostream& operator<<(ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << "\tY = " << obj.get_y();
}

double distance(const Point& A, const Point& B)
{
	/*double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);*/
	return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
}

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTOR_CHECK
//#define ASSIGNMENT_CHECK
//#define INCREMENT_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	//type_name;
	int a; // Объявление переменной a типа int
	Point A; // Объявдение переменной A типа Point; создание объекта А структуры Point; создание экземпляра А структуры Point

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << "A:\t" << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << "B:\t" << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'A' до точки 'B':\t" << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A':\t" << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками А и В: \t" << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками А и В: \t" << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHEK

#ifdef CONSTRUCTOR_CHECK
	Point A;
	A.print();

	Point B = 5;		// Single-argument constructor 
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;  // CopyConstructor
	D.print();

	Point E; // Copy Assignment
	E = D;
	E.print();
#endif // CONSTRUCTOR_CHECK

#ifdef ASSIGNMENT_CHECK
	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();
#endif // 

#ifdef INCREMENT_CHECK
	int a = 2;
	int b = 3;
	int c = a + b;
	cout << c << endl;

	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;
	C.print();

	A++;
	A.print();
#endif // INCREMENT_CHECK

	Point A(2, 3);
	A.print();

	Point B(7, 8);
	B.print();

	A /=B;
	A.print();

	cout << A << endl;
}