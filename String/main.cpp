#include<iostream>
using namespace std;

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

String operator+(const String& left, const String& right)
{
	/*const int a = 2;
	a = 3;*/
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];

	return cat;
}


std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

// :: - Scope operator (оператор разрешения видимости)
// scope::name
//namespace::name
int String:: get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//			Constructors
//	Ключевое слово Explicit можно использовать только внутри класса.
//	При помщи Explicit мы только объявляем метод, но реализуется без 'Explicit'
String::String(int size /*= 80*/) :size(size), str(new char[size] {})
// Параметры по умолчанию пишутся только в прототипе функции
{
	cout << "DefConstructor:\t" << this << endl;
}
String::String(int size, char str)
{
	this->size = size;
	this->str = new char[size] {};
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//Deep copy
	cout << "CopyConstructor:\t" << this << endl;
}
String::String::String(String&& other) : size(other.size), str(other.str)
{
	//Shallow copy:
	//this->size = other.size;
	//this->str = other.str;
	other.size = 0;
	other.str = 0;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] str;
	cout << "Destructor:\t" << this << endl;
}
//		Operators:
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	if (this == &other) return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
}
char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//		Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;

}

#define BASE_CHECK
#define CALING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
	
#ifdef BASE_CHECK
	cout << sizeof("Hello") << endl;
	String str(5);
	str.print();

	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;
	cout << "\n-----------------------------------------------------------\n";
	String str3 = str1 + str2;
	cout << str3 << endl;
	cout << "\n-----------------------------------------------------------\n";

	String str4;
	str4 = str1 + str2;
	cout << str4 << endl;

	String str5 = str4;
	cout << str5 << endl;
#endif // BASE_CHECK


}