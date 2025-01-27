#include <iostream>
#include <random>
using namespace std;
int checksum(const int N, int desk[8][8]); // Функция, находящая контрольную сумму доски
int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 1);// Выбор диапазона случайных чисел от 0 до 1
	const int N = 8;
	int desk[N][N];
	
	for (int i=0; i < N; i++) {
		for (int j=0; j < N; j++) {
			desk[i][j] = dist(gen); // Генерация случайеых чисел в массив 8 на 8
			cout << desk[i][j] << ' ';
		}
		cout << '\n';
	}
	int picked_cell; // Ячейка, выбранная троллем
	cout << "Choose cell number (0-63): ";
	cin >> picked_cell;
	int flipped_cell; // Монета, которую нужно перевернуть
	if (picked_cell != checksum(N, desk))
		flipped_cell = picked_cell ^ checksum(N, desk);
	else
		flipped_cell = 64; // Число 64, выходящее за предел количества клеток, означает, что ничего переворачивать не надо
	cout <<"Desk Number: " << checksum(N, desk) << endl;
	cout << "Number of the coin, which should be fliped: " << flipped_cell<< endl;
	desk[flipped_cell / N][flipped_cell % N] = desk[flipped_cell / N][flipped_cell % N] ^ 1; // Переворачиваем монету
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << desk[i][j]<<" "; //Новая матрица с перевернутой монетой
		cout << endl;
	}
	cout << "New Desk Number: " << checksum(N, desk) << endl; //Новое число доски, которое должно совпадать с picked_coin
	return 0;
}

int checksum(const int N, int desk[8][8]) {
	int n0=0, n1=0, n2=0, n3=0, n4=0, n5=0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			j % 2 != 0 ? n0 += desk[i][j] : 0;
			((N / 4 <= j && j < N / 2) or (j >= (N / 2) + (N / 4))) ? n1 += desk[i][j] : 0;
			j >= N / 2 ? n2 += desk[i][j] : 0;
			i % 2 != 0 ? n3 += desk[i][j] : 0;
			i >= N / 2 ? n5 += desk[i][j] : 0;
			((N / 4 <= i && i < N / 2) or (i >= (N / 2) + (N / 4))) ? n4 += desk[i][j] : 0;
		}
	}
	n0 = n0 % 2;
	n1 = (n1 % 2) << 1;
	n2 = (n2 % 2) << 2;
	n3 = (n3 % 2) << 3;
	n4 = (n4 % 2) << 4;
	n5 = (n5 % 2) << 5;
	return n0 + n1 + n2 + n3 + n4 + n5; // Нахождение контрольных сумм и вывод их суммы
}