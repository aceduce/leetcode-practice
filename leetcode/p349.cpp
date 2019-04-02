#include"Solutions.h"
class p349::Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();
		if (n1 != n2) return {};
		if (n1 > n2) swap(nums1, nums2);
		vector<int> ans;
		unordered_set<int> s;
		for (auto const & n : nums1) {
			s.insert(n);
		}
		for (auto const & n : nums2) {
			if (s.count(n) != 0) {
				ans.push_back(n);
				s.erase(n);
			}
		}
		return ans;
	}
};