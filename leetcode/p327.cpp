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
// http://www.cnblogs.com/grandyang/p/5162678.html

//Merge Sort based count method
	// benefits from the index ordering...
int p327::MergeAndCount(vector<long> & sums, int start, int end, int lower, int upper) {
	if (end - start <= 1) return 0; // one element return 0, cannot just return at two element, since soring is needed...
	int mid = start + (end - start) / 2;
	int count = MergeAndCount(sums, start, mid, lower, upper)
		+ MergeAndCount(sums, mid, end, lower, upper); // should not do mid + 1 since ending is exclusive
	int j = mid, k = mid, t = mid;
	vector<int> cache(end - start, 0); // end is not inclusive...
	 //vector<int> cache(end - start, 0);
	for (int i = start, r = 0; i < mid; i++, r++) {
		while (k < end && sums[k] - sums[i] < lower) k++; // this k value has >= lower should be counted
		while (j < end && sums[j] - sums[i] <= upper) j++; // this j has > upper, should not be counted for instance k = 1, j = 3, effective only 1 and 2 works
		while (t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
		cache[r] = sums[i];
		count += j - k;
	}
	// t record the last one that copied int the merged array
	copy(cache.begin(), cache.begin() + t - start, sums.begin() + start);
	return count;
}

int p327::countRangeSum(vector<int>& nums, int lower, int upper) {
	vector<long> sums(nums.size() + 1, 0);
	for (int i = 0; i < nums.size(); ++i) {
		sums[i + 1] = sums[i] + nums[i];
	}
	return MergeAndCount(sums, 0, sums.size(), lower, upper);
}

void p327::test() {

}