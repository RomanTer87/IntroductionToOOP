#include<iostream>
using namespace std;

#define DELIMITER "_________________________________________________________________"
class Point
{
	double x;
	double y;
public:
	double get_x()const
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
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}*/
	Point(double x=0, double y=0)  //универсальный конструктор, который может работать как с параметрами так и без них(так как в инициализации предусмотрены параметры по умолчанию.
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
	//		 Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//			Methods:
	double distance(const Point& other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		return sqrt(pow(x_distance, 2) + pow(y_distance, 2));
	}
	void print()
	{
		cout << "X: " << x << "\tY: " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
}
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK 

void main()
{
	setlocale(LC_ALL, "");

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);

	Point B;
	B.set_x(7);
	B.set_y(8);

	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << "----------------------------------------------" << endl;

	cout << "–ассто€ние между точками A и B:\t" << distance(A, B) << endl;
	cout << "----------------------------------------------" << endl;
	cout << "–ассто€ние от точки ј до точки ¬:\t" << A.distance(B) << endl;
	cout << "----------------------------------------------" << endl;
	cout << "–ассто€ние от точки B до точки A:\t" << B.distance(A) << endl;
	cout << "----------------------------------------------" << endl;
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	Point A;
	A.print();

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;
	D.print();

	Point E;
	E = C;
	E.print();
#endif // CONSTRUCTORS_CHECK


}