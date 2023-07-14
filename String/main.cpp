#include<iostream>
using namespace std;
#include"String.h"

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