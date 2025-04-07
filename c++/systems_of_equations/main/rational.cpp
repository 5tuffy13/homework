#include "rational.h";

Rational::Rational()
{
	numer = 0;
	denom = 1;
}

Rational::Rational(int number)
{
	numer = number;
	denom = 1;
}

Rational::Rational(int n, int d)
{
	numer = n;
	denom = d;
	simplify();
}

Rational& Rational::operator +=(const Rational& r)
{
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	simplify();
	return *this;
}

Rational Rational::operator +(const Rational& r) const
{
	// this - указатель на себя 
	// *this - ссылка на себя 
	Rational res(*this);
	// Используем готовую операцию добавления
	return res += r;
}

Rational Rational::operator +(const int& n) const
{
	Rational res(*this);

	return res += Rational(n);
}

Rational Rational::operator -(const Rational& r) const
{

	Rational res(*this);
	return res -= r;
}

Rational Rational::operator -() const
{
	Rational r(-numer, denom);
	return r;
}

Rational Rational::operator -(const int& n) const
{
	Rational res(*this);

	return res -= Rational(n);
}

Rational& Rational::operator -=(const Rational& r)
{
	return (*this += (-r));
}

Rational& Rational::operator ++()
{
	numer += denom;
	simplify();
	return *this;
}

Rational Rational::operator ++(int)
{
	Rational r(*this);
	numer += denom;
	simplify();
	return r;
}

Rational& Rational::operator --()
{
	numer -= denom;
	simplify();
	return *this;
}

Rational Rational::operator --(int)
{
	Rational r(*this);
	numer -= denom;
	simplify();
	return r;
}

bool Rational::operator ==(const Rational& r) const
{
	return (numer == r.numer) && (denom == r.denom);
}

bool Rational::operator !=(const Rational& r) const
{
	return !(*this == r);
}

Rational::operator int() const
{
	return numer / denom;
}

Rational::operator double() const
{
	return ((double)numer) / denom;
}

istream& operator >>(istream& in, Rational& r)
{
	in >> r.numer >> r.denom;
	return in;
}

ostream& operator <<(ostream& out, const Rational& r)
{
	out << r.numer << "/" << r.denom;
	return out;
}

void Rational::simplify()
{
	int a = numer < 0 ? -numer : numer;
	int b = denom < 0 ? -denom : denom;

	while (a != 0 && b != 0)
	{
		if (a > b)
		{
			a = a % b;
		}

		else
		{
			b = b % a;
		}
	}

	numer = numer / (a + b);
	denom = denom / (a + b);
}

Rational Rational::operator *(const Rational& r) const
{
	Rational res;

	res.numer = this->numer * r.numer;
	res.denom = this->denom * r.denom;
	res.simplify();
	return res;
}

Rational Rational::operator /(const Rational& r) const
{
	Rational res;

	res.numer = this->numer * r.denom;
	res.denom = this->denom * r.numer;
	res.simplify();
	return res;
}

Rational Rational::operator *(const int& n) const
{
	Rational res;
	res.numer = this->numer * n;
	res.simplify();
	return res;
}

Rational Rational::operator /(const int& n) const
{
	Rational res;
	res.denom = this->numer * n;
	res.simplify();
	return res;
}




