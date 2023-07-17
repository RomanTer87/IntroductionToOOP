#include<iostream>
using namespace std;

class Matrix
{
	int rows;
	int cols;
	double* matrix;
public:
	int rows()const
	{
		return rows;
	}
	int get_cols()const
	{
		return cols;
	}
	double* get_matrix()
	{
		return matrix;
	}
	void set_rows(int rows)
	{
		this->rows = rows;
	}
	void set_cols(int cols)
	{
		this->cols = cols;
	}

	// constructors:
	Matrix(int rows, int cols, double matrix)
	{
		this->rows = rows;
		this->cols = cols;
		this->matrix = matrix*[rows][cols];
		cout << "DefaultConstructor" << this << endl;
	}
	Matrix(int rows = 0, int cols = 0)
	{
		this->cols = cols;
		this->rows = rows;
		this->matrix = matrix*[rows][cols];
		cout << "Constructor:\t" << this << endl;
	}
	Matrix(const Matrix& other)
	{
		this->cols = other.cols;
		this->rows = other.rows;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Matrix()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//	Operators:
	Matrix& operator=(const Matrix& other)
	{
		this->cols = other.cols;
		this->rows = other.rows;
		cout << "CopyAssignment:\t" << this << endl;
	}
	// Methods:
	/*void print()const
	{
		this->matrix = matrix;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
	}*/
};

void main()
{
	setlocale(LC_ALL, "");




}