#include"Solutions.h"
class p508::Solution {
public:
	// can also use a hashmap and traveres it...
	int subfindFrequentTreeSum(TreeNode* r, vector<int> &ans, unordered_map<int, int> & map, int & freq) {
		if (!r) return 0;
		int left = subfindFrequentTreeSum(r->left, ans, map, freq);
		int right = subfindFrequentTreeSum(r->right, ans, map, freq);
		int sum = left + right + r->val;
		map[sum]++;
		if (map[sum] >= freq) {
			if (map[sum] > freq) { // a typical treatment
				freq = map[sum];
				ans.clear();
			}
			ans.push_back(sum);
		}
		return sum;
	}

	vector<int> findFrequentTreeSum(TreeNode* root) {
		vector<int> ans;
		unordered_map<int, int> map;
		int freq = 0;
		int sum = 0;
		// need to have sum, other wise, not initalized
		subfindFrequentTreeSum(root, ans, map, freq);
		return ans;
	}
};