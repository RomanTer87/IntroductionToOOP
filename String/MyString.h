#pragma once
#include<iostream>
using namespace std;


////////////////////////////////////////////////////
//	Объявление класса - Class Declaration
////////////////////////////////////////////////////

class String
{
	int size;	 // Размер строки в Байтах
	char* str;	//адрес строки в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//	Constructors
	explicit String(int size = 80);
	String(int size, char str);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();
	//		Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	char operator[](int i)const;
	char& operator[](int i);

	//		Methods:
	void print()const;
};
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
////////////////////////////////////////////////////
//	Объявление класса - Class Declaration
////////////////////////////////////////////////////