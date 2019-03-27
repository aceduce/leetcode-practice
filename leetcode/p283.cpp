#include"Solutions.h"
class p283::Solution_1 {
public:
	void moveZeroes(vector<int>& nums) {
		// two pointers
		int left = 0;
		int right = nums.size();
		while (left < right) {
			while (left < nums.size() && nums[left] != 0) left++; // gradual shift to the right
			while (right >= 0 && nums[right] == 0) right--;
			// right points to non-zero, left points to zero
			if (left < right) {
				int i = left, j = right;
				while (i < j) {
					nums[i] = nums[i + 1];
					i++;
				}
				nums[j] = 0;
				right--;
			}
		}
	}
};

class p283::Solution_2{
public:
	void moveZeroes(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				int j = i;
				while (j < nums.size() && nums[j] == 0) {
					j++;
				}
				int st = i;
				// j points to first non zero elemnt
				for (int k = j; k < nums.size(); k++) {
					nums[st++] = nums[k];
				}
				i = j + 1;
			} 
		}
	}
};