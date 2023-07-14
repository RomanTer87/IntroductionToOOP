#include<iostream>
using namespace std;

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
	Point()
	{
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}


	//			Methods:
	double distance(Point other)
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

	cout << "Расстояние между точками A и B:\t" << distance(A, B) << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Расстояние от точки А до точки В:\t" << A.distance(B) << endl;
	cout << "Расстояние от точки B до точки A:\t" << B.distance(A) << endl;
#endif // DISTANCE_CHECK

	Point A;
	A.print();

	Point B = 5;
	B.print();
} 