#include"Solutions.h"
int p198::rob(vector<int>& nums) {
	int even_sum = 0, odd_sum = 0;
	for (int i = 0; i < nums.size(); ) {
		even_sum += nums[i];
		i = i + 2;
	}
	for (int j = 1; j < nums.size();) {
		odd_sum += nums[j];
		j = j + 2;
	}
	return max(even_sum, odd_sum);
}