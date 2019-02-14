#include "Solutions.h"

// seems okay in line 20 if j < n is put first
void Solutions::p31::nextPermutation(vector<int> & nums) {
	if (nums.empty() || nums.size() == 1) return;

	int n = nums.size();
	int i;
	for (i = n - 2; i >= 0; i--) { // have to reach to zero --> > 0 ==> >= 0 
		if (nums[i] < nums[i + 1]) break;
	}
	// nums[i] is the one to swap
	if (i < 0) { // a case with all the numbers from left to right, descending order
		// need to include < rather then == zero: so that n = 1 is handled
		sort(nums.begin(), nums.end()); 
		return;
	}
	// swap number
	int num2swap = nums[i]; // i : the index of number to swap
	int j = i + 1;
	while (j < n && nums[j] > num2swap) {  //get the forthest larger number (smallest larger number)
		// as the data is in descending sequence
		j++;  
	}
	
	//int tmp = nums[j - 1];
	nums[i] = nums[j - 1];
	nums[j - 1] = num2swap;

	sort(nums.begin() + i + 1 , nums.end()); //sort the left range end -[ (n -1 ) - i ]--> end, 
	return;
}


