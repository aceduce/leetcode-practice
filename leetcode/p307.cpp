#include"Solutions.h"

class p307::FenwickTree {
public:
	void update(vector<int> & BIT, int index, int val) {
		while (index < BIT.size()) {
			BIT[index] += val;
			index += index & (-index);
		}
	}

	int query(vector<int> & BIT, int index) {
		int sum = 0;
		while (index > 0) {
			sum += BIT[index];
			index -= index & (-index);
		}
		return sum;
	}

	//private:
		//vector<int> BIT;
};

class p307::NumArray {
public:
	NumArray(vector<int> nums) {
		int n = nums.size();
		//int m = unique(nums.begin(), nums.end()) - nums.begin();
		BIT = vector<int>(n + 1, 0);
		nums_ = vector<int>{ nums.begin(), nums.end() };
		int i = 1;
		for (auto const num : nums) {
			tree_.update(BIT, i, num);
			i++;
		}
	}

	void update(int i, int val) { // val has to be a delta not absolute value
		tree_.update(BIT, i + 1, val - nums_[i]); // this is not BITs --> nums
		nums_[i] = val; // update the pre-sum and nums

	}

	int sumRange(int i, int j) {
		return tree_.query(BIT, j + 1) - tree_.query(BIT, i);
	}

private:
	FenwickTree tree_;
	vector<int> BIT; //need to have presum matrix
	vector<int> nums_; // need to have nums_ to store values

};

class p307::SegmentTree {
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */