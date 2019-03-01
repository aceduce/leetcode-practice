#include"Solutions.h"

//Trivial DFS solutions
// NP problem
// sorting should help significant
// optimization on the choosing part: empty only choose x
// sort must be into a descending order!


bool p473::DFS(vector<int> & nums, int a, int b, int c, int d, const int & base, int index) {
	int n = nums.size();
	if (index == n) return true;
	int i = index;
	// no need for loop
	// for (int i = index; i < n; i++) { 
		if (a >= nums[i])
			if(DFS(nums, a - nums[i], b, c, d, base, index + 1)) return true;
		if (b >= nums[i] && a!= base) // a is not empty
			if (DFS(nums, a, b - nums[i], c, d, base, index + 1)) return true;
		if (c >= nums[i] && a != base && b!= base) // a is not empty
			if (DFS(nums, a, b , c - nums[i], d, base, index + 1)) return true;
		if (d >= nums[i] && a != base && b != base && c != base) // a is not empty
			if (DFS(nums, a, b, c , d - nums[i], base, index + 1)) return true;
	// }
	return false;
}


bool p473::makesquare(vector<int>& nums) {
	int size = nums.size();
	if (size == 0) return false;
	int total = 0;
	for (auto const & num : nums) {
		total += num;
	}
	if (total % 4 != 0 && !total) return false;
	//DFS search for 4 edges
	const int edges = total / 4;
	//vector<int> status;
	sort(nums.begin(), nums.end(), greater<int>()); // optimizations
	return DFS(nums, edges, edges, edges, edges, edges, 0);
}

void p473::test() {

}