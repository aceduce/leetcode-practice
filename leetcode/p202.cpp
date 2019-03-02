#include"Solutions.h"
bool p202::isHappy(int n) {
	unordered_map<int, int> digits;
	digits[n] = 1;
	int sum = 0;
	while (n!= 1 && digits[n]<=1) {	// dupicates means a lot
		sum = 0;
		while (n) {
			//digits.push_back(n % 10);
			sum += (n % 10) *(n % 10);
			n = n / 10;
		}
		digits[sum]++;
		if (sum == 1) return true;
		n = sum;
	}
	return false;
}

void p202::test() {
	cout << isHappy(2) << endl;
}