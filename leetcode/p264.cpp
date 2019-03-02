#include"Solutions.h"
int p264::nthUglyNumber(int n) {
	static vector<int> num{ 1 };
	static int i2 = 0;
	static int i3 = 0;
	static int i5 = 0;
	while (num.size() < n) {
		int next2 = num[i2] * 2;
		int next3 = num[i3] * 3;
		int next5 = num[i5] * 5;
		int next = min(min(next2, next3), next5);
		num.push_back(next);
		// same case add bath
		if (next == next2) i2++;
		if (next == next3) i3++;
		if (next == next5) i5++;
	}

}

void p264::test() {

}