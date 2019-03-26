#include"Solutions.h"
// https://www.youtube.com/watch?v=r6I-ikllNDM
// a common used method (reverse sum)
// use handy accumlate STL
// O(sum * N)
// can potentially do reverse sort...
bool p416::canPartition(vector<int>& nums) {
	const int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2 != 0) return false;
	// only 20 K data range
	vector<int> DP(sum + 1, 0);
	DP[0] = 1; // sum to zero is valid
	for (auto const & n : nums) {
		for (int i = sum; i >= 0; i--) { // tricky way to do sum, no need to worry about sum less
			if (DP[i]) DP[i + n] = 1; // valid
			if (DP[sum / 2]) return true;
		}
	}
	return false;
}