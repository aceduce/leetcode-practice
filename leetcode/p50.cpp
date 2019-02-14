#include"Solutions.h"
double p50::myPow(double x, int n) {
	if (x == 1 || n == 0) return 1;
	if (x == 0) return 0;
	double ans = 1;
	double num = x;
	int flag = -1;
	/* No need to use this flag thing
	if (n < 0) {
	n = -n;
	flag = 0;
	}
	*/
	// this is to use -(power+1) to avoid MIN_VALUE case
	if (n < 0)
		return 1 / (x*myPow(x, -(n + 1)));
	
	while (n > 0) {
		if (n % 2 == 1) {
			ans *= num;
		}
		num = num * num;
		n = n / 2;
	}
	
	return ans;

}

void p50::test() {
	cout << myPow(2.0, 10) << endl;;
	cout << myPow(2.1, 3) << endl;
	cout << myPow(2.0, -2) << endl;
}
