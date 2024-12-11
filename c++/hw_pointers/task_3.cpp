#include <iostream>
using namespace std;

int main() {
	int n = 80;
	int k = 0;
	char* str = new char[n + 1];
	cin.getline(str, n);
	cout << "The string:" << '\t' << str << '\n';
	str[n] = '\0';
	int cnt_max = -1;
	char digit_cnt_max;
	for (int i = 0; i < n and *(str + i) != '\0'; i++) {
		if (isdigit(*(str + i))) {
			for (int j = 0; j < n and *(str + j) != '\0'; j++) {
				if (*(str + i) == *(str + j)) {
					k++;
				}
			}
			if (k >= cnt_max) {
				cnt_max = k;
				digit_cnt_max = *(str + i);
			}
			k = 0;
		}
	}
	if (cnt_max == -1) {
		cout << "No digits in a string";
		return -1;
	}
	else
		cout << "Digit '" << digit_cnt_max << "' has been repeated " << cnt_max << " times";

	return 0;
}
