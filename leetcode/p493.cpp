#include"Solutions.h"
int p493::reversePairs(vector<int>& nums) {
	// TLE
	multiset<long> BST;
	int ans = 0;
	for (int i = 0; i < nums.size(); i++) {
		long search = 2 * (long)nums[i];
		auto index = BST.upper_bound(search);
		/*
		while (index != BST.end()) { // found one value
			index++; // real first element
			ans++;
		}
		*/
		if (index != BST.end())
			ans = ans + distance(index, BST.end());
		BST.insert((long)nums[i]);
	}
	return ans;
}


void p493::test() {

}