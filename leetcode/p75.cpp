#include"Solutions.h"
//#include"Helper.h"
// only 3 colors in this case
// adapt basket method
void p75::sortColors(vector<int>& nums) {
	if (nums.size() <= 1) return;
	int indexL = 0;
	int indexR = nums.size() - 1;
	while (indexL <= nums.size() - 1 && nums[indexL] == 0) indexL++;
	while (indexR >= 0 && nums[indexR] == 2) indexR--;
	if (indexL >= indexR) return; // all 0 or all 2 not need to do anything.
	// looping:
	for (int i = indexL; i <= indexR; i++) {
		if (nums[i] == 2) { // move to right
			int tmp = nums[indexR];
			nums[indexR] = 2;
			nums[i] = tmp;
			indexR--;
			i--; // stay the same
		}
		else if(nums[i] == 0){
			int tmp = nums[indexL];
			nums[indexL] = 0;
			nums[i] = tmp;
			indexL++;
		}
	}
}

void p75::test() {
	vector<int> input{ 2,0,1 };
	sortColors(input);
	//Print(input);
}