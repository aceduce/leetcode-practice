#include "Solutions.h"

int p42::trap(vector<int>& height) {
	// keep track of left and right pointer
	// the lowest one decide the values
	if (height.empty()) return 0;
	int lefth = 0, righth = 0;
	int i = 0, j = height.size() - 1;
	lefth = max(lefth, height[0]);
	righth = max(righth, height[j]);
	int ans = 0;
	while (i < j) {
		if (lefth < righth) { // left side decide
			ans += max(0, lefth - height[i++]);
			lefth = max(height[i], lefth);
		}
		else {
			ans += max(0, righth - height[j--]);
			righth = max(height[j], righth);
		}
	}
	return ans;
}

void p42::test() {
	vector<int> input{ 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << trap(input) << endl;
}