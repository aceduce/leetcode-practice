#include"Solutions.h"
// naive solution but too slow TLE
int p201::rangeBitwiseAnd_TLE(int m, int n) {
	int ans = 0;
	for (int i = 0; i < 32; i++) {
		int d = 1;
		for (long long k = m; k <= n; k++) { // AND the corresponding digit
			if (k == 2147483647)
				cout << endl;
			d = d & (k >> i & 1);
		}
		ans = ans | (d << i);
	}
	return ans;
}

int p201::rangeBitwiseAnd(int m, int n) {
	//int ans = 0;
	int i = 0;
	while (m != n) {
		m = m >> 1;
		n = n >> 1;
		i++;
	}
	return m << i;
}

void p201::test() {

}