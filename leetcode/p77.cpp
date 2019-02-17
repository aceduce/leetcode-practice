#include"Solutions.h"
//#include"Helper.h"
// a typical backtracking, without duplicates
void subcom(vector<vector<int>> &ans, vector<int> &tmp, int indx, int n, int k) {
	if (tmp.size() == k ) {
		ans.push_back(tmp);
		return;
	}
	for (int i = indx; i <= n; i++) {
		tmp.push_back(i);
		subcom(ans, tmp, i + 1, n, k);
		tmp.pop_back();
	}
}

vector<vector<int>> p77::combine(int n, int k) {
	vector<vector<int>> ans;
	vector<int> tmp;
	subcom(ans, tmp, 1, n, k);
	return ans;
}

void p77 ::test() {
	//Print2D(combine(1, 1));
}