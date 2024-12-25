#include <iostream>
using namespace std;
int func1(int &number);
int main() {
	int n;
	cout << "Enter the number" << "\t";
	cin >> n;
	cout << "Prime divisors of numbers: ";//Вывод всех простых делителей числа
	func1(n);
}

int func1(int &number)// Определение рекурсивной функции
{
	if (number != 1)
	{
		for (int i = 2; i <= number; i++)
		{
			if (number % i == 0)
			{
				cout << i << ' ';
				int n = number / i;
				func1(n);
				break;
			}
		}
	}

	else
		return 1;
}
