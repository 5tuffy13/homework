#include "figures.h"
Point::Point(int in_x,int in_y)
{
	x = in_x;
	y = in_y;
}


class Circle : public Figure
{
	void name() override
	{
		cout << this->figname << endl;
	}

	int calc_area() override
	{
		return radius * radius * 3;
	}

	int ñalc_perimetr() override
	{
		return radius * 6;
	}

};