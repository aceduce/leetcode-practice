#include"Solutions.h"
// binary search method
int p69::mySqrt(int x) {
	if (x == 0) return 0;
	int right = sqrt(INT_MAX);
	int left = 1; 
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		if (mid*mid == x) return mid;
		if (mid*mid < x) {
			left = mid;
		}
		else {
			right = mid;
		}
	}

	if (right*right <= x) return right;
	else return left;
}

void p69::test() {
	cout << mySqrt(4) << endl;
	cout << mySqrt(8) << endl;
	cout << mySqrt(0) << endl;
	cout << mySqrt(1) << endl;
}