#include"Solutions.h"
//#include"Helper.h"
void p88::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (nums1[i] > nums2[j]) {
			// maybe there's a way to reduce the shift
			for (int k = m; k > i; k--) {
				nums1[k] = nums1[k - 1];
			}
			nums1[i] = nums2[j];
			i++;
			j++;
			m++;
		}
		else {
			i++;
		}
	}
	while(j < n) { // shift all the num2 to nums1
		nums1[i] = nums2[j];
		j++;
		i++;
	}
}

void p88::test() {
	vector<int> num1{ 2,0};
	vector<int> num2{ 1};
	merge(num1, 1, num2, 1);
	//Print<int>(num1);
}