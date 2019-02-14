# include "Solutions.h"

// jump series # 2:
// need to figure out the number of steps
// compare this step and next step, whichever ones go further
int p45::jump(vector<int>& nums) { 
	if (nums.size() <= 1) return 0;
	int steps = 0;
	int curMax = 0;
	int nextMax = nums[0] + 0;
	int index = 0;
	while (curMax < nextMax) {
		steps++;
		curMax = nextMax;
		if (curMax >= nums.size() - 1) return steps;
		// explore if next step could go further
		while (index <= curMax) {
			nextMax = max(nextMax, nums[index] + index); // next steps reach the farthest
			if (nextMax >= nums.size() - 1) return steps + 1; // reaches the end!
			index++;
		}	
	}
	return 0; // fail
}

void p45::test() {
	vector<int> input{ 2,3,1,1,4 };
	cout << jump(input) << endl;
}