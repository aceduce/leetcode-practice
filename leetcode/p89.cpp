#include"Solutions.h"
//#include"Helper.h"
vector<int> p89::grayCode(int n) {
	// equation : i ^ (i/2 or i>>1)
	vector<int> ans;
	for (int i = 0; i < (1 << n); i++) {
		ans.push_back(i ^ (i >> 1));
	}
	return ans;
}

void p89::test() {
	vector<int> ans = grayCode(2);
	//Print(ans);
}