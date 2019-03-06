#include"Solutions.h"
int p258::addDigits(int num) {
	int exp = 1;
	while (num >= 10) { // only one digit left
		int tmp = 0;
		long long exp = 1;
		while (num / exp > 0) {
			tmp += num / exp % 10;
			exp *= 10;
		}
		num = tmp;
	}
	return num;
}

void p258::test() {
	cout << addDigits(2032610959) << endl;
}