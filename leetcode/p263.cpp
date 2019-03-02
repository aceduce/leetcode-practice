#include"Solutions.h"
bool p263::isUgly(int num) {
	if (num == 0) return false;
	const vector<int> factors{ 2, 3, 5 };
	for (const auto & factor : factors) {
		while (num%factor == 0) num /= factor;
	}
	if (num == 1) return true;
	else return false;
}

void p263::test() {
	cout << isUgly(6) << endl;
}