#pragma once
#include <iostream>
using namespace std;
class Rational
{
	// Числитель 
	int numer;
	// Знаменатель (>=1) 
	int denom;



public:
	void simplify();
	Rational();// Дефолтный конструктор класса
	Rational(int number); // Преобразование из int в Rational
	Rational(int n, int d);// Конструктор класса (числитель и знаменатель)
	Rational& operator +=(const Rational& r);// Оператор добавления
	Rational operator +(const Rational& r) const;// Сложения
	Rational operator -(const Rational& r) const;// Вычитания
	Rational operator +(const int& n) const;// Сложения c int
	Rational operator -(const int& n) const;// Вычитания c int
	Rational operator -() const;//Унарный минус
	Rational& operator -=(const Rational& r);//уменьшение
	Rational& operator ++(); // префиксный инкремент
	Rational operator ++(int); // постфиксный инкремент
	Rational& operator --(); // префиксный декремент
	Rational operator --(int); // постфиксный декремент
	bool operator ==(const Rational& r) const;//сравнение
	bool operator !=(const Rational& r) const;//отрицательное сравнение
	operator int() const; // Преобразование в int
	operator double() const;// Преобразование в double
	friend istream& operator >>(istream& in, Rational& r);// Ввод
	friend ostream& operator <<(ostream& out, const Rational& r); // Вывод
	Rational operator *(const Rational& r) const;// Умножение на Rational
	Rational operator /(const Rational& r) const; // Деление на Rational
	Rational operator *(const int& n) const;// Умножение на int
	Rational operator /(const int& n) const;// Деление на int


};

