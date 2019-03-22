#include"Solutions.h"
//other conditions are pretty cool!
//https://leetcode.com/problems/rectangle-overlap/solution/
class p836::Solution {
public:
	// use the method from P223: shift the first rect1 to the first quadrant
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		// (x1, y1) - (x2, y2)
		// each data point (- x1, - y1)
		int tmpx = rec1[0];
		int tmpy = rec1[1];
		for (int i = 0; i < rec1.size(); i++) {
			if (i % 2 == 0) {
				rec1[i] -= tmpx;
				rec2[i] -= tmpx;
				if (rec2[i] < 0) rec2[i] = 0;
			}
			else {
				rec1[i] -= tmpy;
				rec2[i] -= tmpy;
				if (rec2[i] < 0) rec2[i] = 0;
			}
		}
		if (rec2[0] >= rec1[2] || rec2[1] >= rec1[3])
			return false;
		if (rec2[2] == 0 || rec2[3] == 0) return false;
		//int x  = a - rec2[1];
		return true;
	}
};