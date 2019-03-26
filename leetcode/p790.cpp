#include"Solutions.h"
// a typical DP question
// https://leetcode.com/problems/domino-and-tromino-tiling/discuss/116581/Detail-and-explanation-of-O(n)-solution-why-dpn2*dn-1+dpn-3

int p790::numTilings(int N) {
	int M = 1e9 + 7;
	vector<long> ans(max(N + 1, 4), 0);
	ans[0] = 0, ans[1] = 1, ans[2] = 2, ans[3] = 5;
	for (int i = 4; i < N + 1; i++) {
		ans[i] = (2 * ans[i - 1] + (ans[i - 3])) % M;
	}
	return ans[N];
}
