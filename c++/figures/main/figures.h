#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Point {
	Point(int in_x, int in_y);
	int x;
	int y;

};


class Figure{
public:
	string figname;
	int radius;
	virtual int calc_area() = 0;
	virtual int ñalc_perimetr() = 0;
	virtual void name() = 0;
};

class Circle :public Figure {

	Point center;
	int radius;
	Circle(Point center, int radius);

};

class Ellipse :public Figure {

	Point center;
	int radius_x, radius_y;

};


class Rectangle :public Figure {

	vector<Point> coordinates;
	vector<int> sides;
};


class Polygon :public Figure {

	vector<Point> coordinates;

};


class Triangle :public Figure {

	vector<Point> coordinates;
	vector<int> sides;

};

