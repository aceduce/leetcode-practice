#include"Solutions.h"
// considering using backtracking method
// may attempt on back-tracking
// set case: no duplicate, still need to loop all the index
class p216::Solution_backtracking {
public:
	void sub_combSum(int dig, int const &n, int k, int sub_sum, vector<int> &tmp, vector<vector<int>> & ans) {
		if (sub_sum == n && k == 0) {
			ans.push_back(tmp);
			return;
		}

		if (dig == 10 || k < 0 || sub_sum > n) return;

		for (int i = dig; i <= 9; i++) {
			if (sub_sum < n) {
				tmp.push_back(i);
				sub_sum += i;
				sub_combSum(++i, n, --k, sub_sum, tmp, ans);
				// skip case
				k++;
				i--;
				tmp.pop_back();
				sub_sum -= i;
			}
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> tmp;
		vector<vector<int>> ans;
		int sub_sum = 0;
		sub_combSum(1, n, k, sub_sum, tmp, ans);
		return ans;
	}
};