#include"Solutions.h"
//O(sqrt(c))
bool p633::judgeSquareSum(int c) {
	int m = sqrt(c);
	for (int a = 0; a <= m; a++) {
		int b = round(sqrt(c - a * a)); // conversion 1.99 --> 2.0 rather than 1
		if (a*a + b * b == c)
			return true;
	}
	return false;
}

void p633::test() {

}