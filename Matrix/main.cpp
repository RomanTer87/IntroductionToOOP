#include<iostream>
using namespace std;

class Matrix
{
	int rows;
	int cols;
	double* array;
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
		this->rows = 1;
		this->cols = 1;
		this->array = new double* [rows] {};
		for (int i = 0; i < rows; i++) array[i] = new double [cols] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Matrix(int cols)
	{
		this->rows = 1;
		this->cols = cols;
		this->array = new double* [rows] {};
		for (int i = 0; i < rows; i++) array[i] = new double[cols] {};

	}


};

void main()
{
	setlocale(LC_ALL, "");




}