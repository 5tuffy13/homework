#pragma once
#include "rational.h"
class Matrix {

	Rational** ptr;
	int size_N, size_M;

public:
	Rational& operator[](int N);
	
	



};