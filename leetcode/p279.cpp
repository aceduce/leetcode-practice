#include"Solutions.h"
// this is a typcial DP quetions
// Space O(N); Time N*log(N)
int p279::numSquares(int n) {
	if (n <= 0) return 0;
	vector<int> DP(n + 1, INT_MAX);
	DP[0] = 0;
	for (int i = 1; i <= n; i++) {
		int j = 1;
		while (i - j * j >= 0) { // try breaking-down into a square and res
			DP[i] = min(DP[i], 1 + DP[i - j * j]);
			j++;
		}
	}
	return DP[n];
}

void p279::test() {

}