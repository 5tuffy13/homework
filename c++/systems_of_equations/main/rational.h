#pragma once
#include <iostream>
using namespace std;
class Rational
{
	// ��������� 
	int numer;
	// ����������� (>=1) 
	int denom;



public:
	void simplify();
	Rational();// ��������� ����������� ������
	Rational(int number); // �������������� �� int � Rational
	Rational(int n, int d);// ����������� ������ (��������� � �����������)
	Rational& operator +=(const Rational& r);// �������� ����������
	Rational operator +(const Rational& r) const;// ��������
	Rational operator -(const Rational& r) const;// ���������
	Rational operator +(const int& n) const;// �������� c int
	Rational operator -(const int& n) const;// ��������� c int
	Rational operator -() const;//������� �����
	Rational& operator -=(const Rational& r);//����������
	Rational& operator ++(); // ���������� ���������
	Rational operator ++(int); // ����������� ���������
	Rational& operator --(); // ���������� ���������
	Rational operator --(int); // ����������� ���������
	bool operator ==(const Rational& r) const;//���������
	bool operator !=(const Rational& r) const;//������������� ���������
	operator int() const; // �������������� � int
	operator double() const;// �������������� � double
	friend istream& operator >>(istream& in, Rational& r);// ����
	friend ostream& operator <<(ostream& out, const Rational& r); // �����
	Rational operator *(const Rational& r) const;// ��������� �� Rational
	Rational operator /(const Rational& r) const; // ������� �� Rational
	Rational operator *(const int& n) const;// ��������� �� int
	Rational operator /(const int& n) const;// ������� �� int


};

