# include "Solutions.h"

string p38::countAndSay(int n) {
	// my attempt :iterative
	// iteratively, count how many times for the string
	if (n == 0) {
		return "";
	}
	string ans = "1"; // starting point
	string tmp;
	for (int i = 0; i < n - 1; i++) { // do n -1 times
		tmp = "";
		char pre = '.';
		int count = 0;
		//bool flag = false;
		for (size_t j= 0; j < ans.length(); j++) {
			if (pre == ans[j] || pre == '.') {
				count++;
				pre = ans[j];
				//flag = true;
			}
			else {
				tmp = tmp + to_string(count) + pre;
				count = 1; // reset count;
				pre = ans[j];
				//flag = false;
			}
		}
		tmp = tmp + to_string(count) + pre;
		ans = tmp;
		//cout << tmp << endl; // check intermmeidate values
	}
	return ans;
}