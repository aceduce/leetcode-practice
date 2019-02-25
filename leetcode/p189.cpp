#include"Solutions.h"
#include"Helper.h"
void p189::rotate_1(vector<int>& nums, int k) { // shift arrays, T: O(n), S: O(n) --> the k sub array
	int n = nums.size();
	if (n == 0) return;
	int k_ = k % n;
	// save the last k values and move them to the front
	// other values are all moving to the right by k
	vector<int> s{ nums.begin() + (n - k_), nums.end() };
	for (int i = n - k_ - 1; i >= 0; i--) { // this shift has to be backward shifts!!!
		nums[i + k_] = nums[i];
	}
	//reverse(s.begin(), s.end());
	copy(s.begin(), s.end(), nums.begin());

}

// need more methods
// method2: reverse reverse method
void p189::rotate(vector<int>& nums, int k) {
	int n = nums.size();
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + k);
	reverse(nums.begin() + k, nums.end());
}

void p189::test() {
	vector<int> input{ 1,2,3,4,5,6,7 };
	rotate(input, 1);
	Print(input);
}

// index:
// 1,2,3,4 
// n = 4, k = 1
// move index = n - k  = 3 separately
// then, move from 0 --> 2 by 1 to 1 --> 3