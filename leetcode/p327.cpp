#include"Solutions.h"
// solution insight; https://leetcode.com/problems/count-of-range-sum/discuss/238956/C%2B%2B-BST-solution-with-using-multiset-O(nlogn)
int p327::countRangeSum(vector<int>& nums, int lower, int upper) {
	multiset<long> BST;
	int ans = 0;
	long cur_sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		cur_sum += nums[i];
		if (cur_sum >= lower && cur_sum <= upper)
			ans++; // from index of ZERO to i/j for sum
		//BST.insert(cur_sum);
		long from = cur_sum - upper;
		long to = cur_sum - lower;
		auto left = BST.lower_bound(from); // first Val >=
		auto right = BST.upper_bound(to); // first Val >
		if (left != BST.end()) { // found the sum
			while (left != right) {
				// count array:
				ans++;
				left++; // shift the left
			}
		}
		// did not find it!!
		BST.insert(cur_sum);
	}
	return ans;
}

// Second Method: Divide and Conquer...
// Seems hard to undestand

void p327::test() {

}