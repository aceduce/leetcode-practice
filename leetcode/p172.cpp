#include"Solutions.h"
int p172::trailingZeroes(int n) {
	long long p = 5;
	int ans = 0;
	while (n / p > 0) {
		ans += n / p;
		n = n / p;
	}
	return ans;
}

void p172::test() {

}