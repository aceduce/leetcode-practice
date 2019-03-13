#include"Solutions.h"
int p997::findJudge_my(int N, vector<vector<int>>& trust) {
	// i trusts j
	int ans = 0;
	if (trust.size() == 0 && N == 1) return 1;
	unordered_map<int, vector<int>> trust_map;// trusted person j : i being trusted
	set<int> s;
	vector<int> trusted_by_all;
	for (auto const & t : trust) {
		trust_map[t[1]].push_back(t[0]);
		s.insert(t[0]);
		if (trust_map[t[1]].size() == N - 1)
			trusted_by_all.push_back(t[1]);
	}
	for (auto const & a : trusted_by_all) {
		if (s.count(a) == 0) {
			ans = a;
			return ans;
		}

	}
	return -1;
}

// smart implementation

/*

实现思路：

1、如果 trust 小于 N - 1，明显没有 judge；
2、遍历 trust，记录信任 a 和 被信任 b 的数值；
3、检查 a 和 b 中符合条件的记录。

*/
int p997::findJudge(int N, vector<vector<int>>& trust) {
	if (trust.size() < N - 1)
		return -1;

	vector<int> a(N + 1, 0), b(N + 1, 0);

	for (vector<int> t : trust) {
		a[t[0]] ++;
		b[t[1]] ++;
	}

	int ans = -1;

	for (int i = 1; i <= N; i++) {
		if (ans == -1 && a[i] == 0 && b[i] == N - 1)
			ans = i;
	}

	return ans;
}