#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

enum type {
	type_none,
	type_number,
	type_real,
	type_string
};

class var {
	union
	{
		long long number;
		double real;
		char *str;
	};
	type data;
	size_t len;
public:
	var();

#pragma region ConstructorsForDataTypes
	var(long long num);
	var(double num);
	var(bool num);
	var(char *num);
	var(short int num);
	var(unsigned short int num);
	var(int num);
	var(unsigned int num);
	var(long int num);
	var(unsigned long int num);
	var(float num);
	var(long float num);
#pragma endregion


#pragma region var_operator+
	var operator+(int num);
	var operator+(long long num);
	var operator+(double num);
	var operator+(bool num);
	var operator+(char* num);
	var operator+(short int num);
	var operator+(unsigned short int num);
	var operator+(long int num);
	var operator+(unsigned long int num);
	var operator+(float num);
	var operator+(long float num);
	var operator+(var num);
#pragma endregion
#pragma region var_operator-
	var operator-(int num);
	var operator-(long long num);
	var operator-(double num);
	var operator-(bool num);
	var operator-(char num);
	var operator-(short int num);
	var operator-(unsigned short int num);
	var operator-(long int num);
	var operator-(unsigned long int num);
	var operator-(float num);
	var operator-(long float num);
#pragma endregion
#pragma region var_operator*
	var operator*(int num);
	var operator*(long long num);
	var operator*(double num);
	var operator*(bool num);
	var operator*(char num);
	var operator*(short int num);
	var operator*(unsigned short int num);
	var operator*(long int num);
	var operator*(unsigned long int num);
	var operator*(float num);
	var operator*(long float num);
#pragma endregion
#pragma region var_operator/
	var operator/(int num);
	var operator/(long long num);
	var operator/(double num);
	var operator/(bool num);
	var operator/(char num);
	var operator/(short int num);
	var operator/(unsigned short int num);
	var operator/(long int num);
	var operator/(unsigned long int num);
	var operator/(float num);
	var operator/(long float num);
#pragma endregion
#pragma region var_operator=
	var operator=(int num);
	var operator=(long long num);
	var operator=(double num);
	var operator=(bool num);
	var operator=(char num);
	var operator=(short int num);
	var operator=(unsigned short int num);
	var operator=(long int num);
	var operator=(unsigned long int num);
	var operator=(float num);
	var operator=(long float num);
#pragma endregion
#pragma region var_operator+=
	var operator+=(int num);
	var operator+=(long long num);
	var operator+=(double num);
	var operator+=(bool num);
	var operator+=(char num);
	var operator+=(short int num);
	var operator+=(unsigned short int num);
	var operator+=(long int num);
	var operator+=(unsigned long int num);
	var operator+=(float num);
	var operator+=(long float num);
#pragma endregion
#pragma region var_operator-=
	var operator-=(int num);
	var operator-=(long long num);
	var operator-=(double num);
	var operator-=(bool num);
	var operator-=(char num);
	var operator-=(short int num);
	var operator-=(unsigned short int num);
	var operator-=(long int num);
	var operator-=(unsigned long int num);
	var operator-=(float num);
	var operator-=(long float num);
#pragma endregion
#pragma region var_operator==
	var operator==(int num);
	var operator==(long long num);
	var operator==(double num);
	var operator==(bool num);
	var operator==(char num);
	var operator==(short int num);
	var operator==(unsigned short int num);
	var operator==(long int num);
	var operator==(unsigned long int num);
	var operator==(float num);
	var operator==(long float num);
#pragma endregion
#pragma region var_operator<
	var operator<(int num);
	var operator<(long long num);
	var operator<(double num);
	var operator<(bool num);
	var operator<(char num);
	var operator<(short int num);
	var operator<(unsigned short int num);
	var operator<(long int num);
	var operator<(unsigned long int num);
	var operator<(float num);
	var operator<(long float num);
#pragma endregion
#pragma region var_operator>
	var operator>(int num);
	var operator>(long long num);
	var operator>(double num);
	var operator>(bool num);
	var operator>(char num);
	var operator>(short int num);
	var operator>(unsigned short int num);
	var operator>(long int num);
	var operator>(unsigned long int num);
	var operator>(float num);
	var operator>(long float num);
#pragma endregion


#pragma region AllOperators
	operator long long();
	operator double();
	operator bool();
	operator char*();
	operator short int();
	operator unsigned short int();
	operator int();
	operator unsigned int();
	operator long int();
	operator unsigned long int();
	operator float();
	operator long float();
#pragma endregion

	/*
	Для строки, перегрузите операторы
	+, =, ==, <, >
	*/

	~var();
};

var::var()
{
	data = type_none;
	len = 0;
}
var::var(long long num) : var()
{
	number = num;
	data = type_number;
}
var::var(double num) : var()
{
	real = num;
	data = type_real;
}
var::var(bool num)
{
	number = num;
	data = type_number;
}
var::var(char *num)
{
	if (str != NULL)
	{
		delete[] str;
		str = new char[strlen((num)+1)];
		strcpy_s(str, strlen(num), num);
	}
	data = type_string;
}
var::var(short int num)
{
	number = num;
	data = type_number;
}
var::var(unsigned short int num)
{
	number = num;
	data = type_number;
}
var::var(int num)
{
	number = num;
	data = type_number;
}
var::var(unsigned int num)
{
	number = num;
	data = type_number;
}
var::var(long int num)
{
	number = num;
	data = type_number;
}
var::var(unsigned long int num)
{
	number = num;
	data = type_number;
}
var::var(float num)
{
	real = num;
	data = type_real;
}
var::var(long float num)
{
	real = num;
	data = type_real;
}


var::operator long long()
{
	return number;
}
var::operator double()
{
	return real;
}
var::operator char*()
{
	return str;
}

var::~var()
{
	if (data == type_string)
	{
		delete[] str;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	cout << "Size of the class var = " << sizeof(var) << endl;

	var tmp(7ll);
	cout << (long long)tmp << endl;

	var tmp2(7.5);
	cout << (double)tmp2 << endl;

	return 0;
}

#pragma region constructors_operator+
var var::operator+(int num)
{
	return var(this->number + num);
}
var var::operator+(long long num)
{
	return var(this->number + num);
}
var var::operator+(double num)
{
	return var(this->number + num);
}
var var::operator+(bool num)
{
	return var(this->number + num);
}
var var::operator+(char * num)
{
	if (data == type_string)
		return var(strcat_s(str, strlen(num) + strlen(str) + 1, num));
	else
		cout << "Error trying to fold char and numeric value! " << endl;
}
var var::operator+(short int num)
{
	return var(this->number + num);
}
var var::operator+(unsigned short int num)
{
	return var(this->number + num);
}
var var::operator+(long int num)
{
	return var(this->number + num);
}
var var::operator+(unsigned long int num)
{
	return var(this->number + num);
}
var var::operator+(float num)
{
	return var(this->number + num);
}
var var::operator+(long float num)
{
	return var(this->number + num);
}
var var::operator+(var num)
{
	if (type_number == num.data)
		return var(this->number + num.data);
	else if (type_real == num.data)
		return var(this->number + num.real);
	else if (type_string == num.data)
		return var(strcat_s(str, strlen(num), num));
	else
		cout << "Error!" << endl;
}
#pragma endregion

