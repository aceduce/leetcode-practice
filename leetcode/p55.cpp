# include "Solutions.h"

// borrow the solution from JUMP2
/*

bool p55::canJump(vector<int>& nums) {
if (nums.size() == 1) return true;
if (nums.empty()) return false;
int steps = 0;
int curMax = 0;
int nextMax = nums[0] + 0;
int index = 0;
while (curMax < nextMax) {
steps++;
curMax = nextMax;
if (curMax >= nums.size() - 1) return true;
// explore if next step could go further
while (index <= curMax) {
nextMax = max(nextMax, nums[index] + index); // next steps reach the farthest
if (nextMax >= nums.size() - 1) return true;// reaches the end!
index++;
}
}
return false; // fail
}


*/


// dual- cut off at the top:
// corner case on [0] and [1,2,3] reach needs equal!
bool p55::canJump(vector<int>& nums) {
	if (nums.size() == 1) return true;
	int reach = nums[0] + 0;
	for (int i = 0; i < nums.size() && i <= reach; i++) {
		reach = max(reach, nums[i] + i);
		if (reach >= nums.size() - 1) return true;
	}
	return false;
}

void p55::test() {
	vector<int> input{ 1,2,3 };
	cout << canJump(input) << endl;
}