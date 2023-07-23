#include<iostream>
using namespace std;

class Matrix
{
	int rows;
	int cols;
	double** array;
public:
	//	Get-Methods
	int get_rows() const
	{
		return rows;
	}
	int get_cols() const
	{
		return cols;
	}
	double** get_array()const
	{
		return array;
	}
	//	Constructors
	Matrix()
	{
		this->rows = 2;
		this->cols = 2;
		this->array = new double* [rows] {};
		for (int i = 0; i < rows; i++) array[i] = new double [cols] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Matrix(int cols)
	{
		this->rows = 2;
		this->cols = cols;
		this->array = new double* [rows] {};
		for (int i = 0; i < rows; i++) array[i] = new double[cols] {};
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Matrix(int cols, int rows)
	{
		this->rows = rows;
		this->cols = cols;
		this->array = new double* [rows] {};
		for (int i = 0; i < rows; i++) array[i] = new double[cols] {};
		cout << "Constructor:\t" << this << endl;
	}
	Matrix(const Matrix& other)
	{
		this->rows = other.rows;
		this->cols = other.cols;
		this->array = other.array;
		cout << "CopyConstructor:\t" << endl;
	}
	~Matrix()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//		Operators
	Matrix& operator=(const Matrix& other)
	{
		if (this == &other)return *this;
		for (int i = 0; i < rows; i++) delete[] array[i];
		delete[] array;
		this->rows = other.rows;
		this->cols = other.cols;
		this->array = other.array;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	void FillRand()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				array[i][j] = rand() % (rows*cols);
			}
		}
	}
	void print()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << array[i][j] << "\t";
			}
			cout << endl;
		}
	}

};

void main()
{
	setlocale(LC_ALL, "");

	Matrix A(2, 2);
	A.FillRand();
	A.print();
	cout << "____________________________________________" << endl;
	Matrix B(2, 2);
	A.FillRand();
	A.print();
}