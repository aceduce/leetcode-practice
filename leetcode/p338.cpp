#include"Solutions.h"
// A method from CSPirton
// O(n)
//
vector<int> p338::countBits(int num) {
	vector<int> ans(num + 1, 0);  // right-side inclusive!
	for (int i = 1; i <= num; i++) {
		ans[i] = ans[i & (i - 1)] + 1;
	}
	return ans;
}


// O(32N)
vector<int> p338::countBits_naive(int num) {
	vector<int> ans(num + 1, 0);  // right-side inclusive!
	for (int i = 1; i <= num; i++) {
		for (int k = 0; k < 32; k++) {
			if ((i >> k & 1) == 1) ans[i]++;
		}
	}
	return ans;
}