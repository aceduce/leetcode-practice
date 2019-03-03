#include"Solutions.h"
// linear sorting... 
// quick sort could be linear...
int p164::maximumGap_bucket(vector<int>& nums) {
	int n = size(nums);
	if (n <= 1) return 0;
	// find the busket
	const auto mm = minmax_element(nums.begin(), nums.end());
	// return iterators, not int
	// int num hass to use * to de-reference
	int range = *mm.second - *mm.first;
	// how to decide this piece???
		// ceil[ ( B - A ) / (n - 1)
	int bucket_size = range / n + 1; // make sure size is bigger than one!! range / (n - 1);
	// use standard answer
	bucket_size = max(1, range / (n - 1));
	n = range / bucket_size + 1;
	// bucket number = n
	vector<int> max_val(n, INT_MIN);
	vector<int> min_val(n, INT_MAX);
	for (auto const & num : nums) {
		int index = (num - *mm.first) / bucket_size;
		max_val[index] = max(max_val[index], num);
		min_val[index] = min(min_val[index], num);
	}
	// loop to find the max btw gaps:
	int maxgap = 0;
	int prevmax = max_val[0]; // prevmax must not be zero element: this is for sure as min is there
	for (int i = 1; i < n; i++) {
		if (max_val[i] != INT_MIN) { // has to make sure this one has elements
			maxgap = max(maxgap, min_val[i] - prevmax);
			prevmax = max_val[i];
		}
	}
	return maxgap;
}

int p164::maximumGap(vector<int>& nums) {
	// use radix sort!!
	int size = nums.size();
	if (size <= 1) return 0;
	int exp = 1, radix = 10;
	const auto maxval = *max_element(nums.begin(), nums.end());
	// radix sort
	while (maxval / exp > 0) { // still have digits to extract
		// need to be here to intialize!
		vector<int>count(radix, 0);
		vector<int> new_order(size, 0);
		// count matrix
		for (int i = 0; i < size; i++) { // N loop
			count[(nums[i] / exp)%10]++;
		}
		for (int i = 0; i < radix - 1; i++) { // k loop
			count[i + 1] += count[i];
		}
		// rearrange the order
		// MUST USE FROM RIGHT TO LEFT
		for (int i = size - 1; i >= 0; i--) {
			new_order[--count[(nums[i] / exp) % 10]] = nums[i];
		}
		nums = new_order;
		// its okay to use this: for(int i = 0; i < size; i++)	nums[i] = new_order[i];
		exp = 10 * exp;
	}

	int max_gap = 0;
	for (int i = 0; i < size - 1; i++) {
		max_gap = max(max_gap, nums[i + 1] - nums[i]);
	}
	return max_gap;
}


void p164::test() {
	vector<int> input{15252, 16764, 27963, 7817, 26155, 20757, 3478, 22602, 20404, 6739, 16790, 10588, 16521, 6644, 20880, 15632, 27078, 25463, 20124, 15728, 30042, 16604, 17223, 4388, 23646, 32683, 23688, 12439, 30630, 3895, 7926, 22101, 32406, 21540, 31799, 3768, 26679, 21799, 23740};
	//{1,10000000};
	cout << maximumGap(input) << endl;
}