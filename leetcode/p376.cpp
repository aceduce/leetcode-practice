#include"Solutions.h"
// O(n^2) method
// typical DP way

// http://www.cnblogs.com/grandyang/p/5697621.html
// DP method
class Solution_DP {
public:
	int wiggleMaxLength(vector<int>& nums) {
		// p and q vector:
		// @ ith element: p record array with it as high, q record it as low
		int size = nums.size();
		if (size == 0) return 0;
		vector<int> p(size, 1);
		vector<int> q(size, 1);
		for (int i = 1; i < size; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) p[i] = max(p[i], q[j] + 1);
				else if (nums[i] < nums[j]) q[i] = max(q[i], p[j] + 1);
			}
		}
		return max(p.back(), q.back());
	}
};

// Greedy method
class Solution_Greedy {
public:
	int wiggleMaxLength(vector<int>& nums) {
		// p and q vector:
		// @ ith element: p record array with it as high, q record it as low
		int size = nums.size();
		if (size == 0) return 0;
		int p = 1, int q = 1;
		for (int i = 1; i < size; i++) {
			if (nums[i] > nums[i - 1]) p = q + 1;
			else if (nums[i] < nums[i - 1]) q = p + 1;
		}
		return max(p, q);
	}
};

