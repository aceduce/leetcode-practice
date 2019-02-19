#include"Solutions.h"

// how to deal with the reference in recursive calls?
// my attempt is very slow though...
// vector .erase a element at fixed position
void p60::subgetPerm(int n, int k, string &sub, string &ans, int &count) {
	if (sub.size() == n) {
		count--;
		if (count == 0) ans = sub;
		return;
	}
	for (int i = 1; i < n + 1; i++) { //back-tracking main block
		if (sub.find((i + '0')) == string::npos) { // not in the string yet
			string tmp = sub;
			sub += (i + '0');
			subgetPerm(n, k, sub, ans, count);
			sub = tmp;
		}
	}
}
string p60::getPermutation_my(int n, int k) {
	string ans = "";
	string sub = "";
	int count = k;
	subgetPerm(n, k, sub, ans, count);
	return ans;
}

// with better search method:
string p60::getPermutation(int n, int k) {
	vector<int> fact(n + 1, 0); // save factorial, mush make sure size is good [0,n]
	fact[0] = 1;
	vector<int> num;
	//num.push_back(0); // should not have zero in the num vector
	for (int i = 1; i <= n; i++) {
		num.push_back(i);
		fact[i] = i * fact[i - 1];
	}
	k = k - 1; // this is to refere to index;
	string ans;
	for(int i = n; i > 0; i--){
		int index = k / fact[i - 1];
		ans = ans + (char)('0' + num[index]);
		num.erase(num.begin() + index);
		k = k % fact[i - 1];
	}
	return  ans;
}

void p60::test() {
	cout << getPermutation(4,9) << endl;
}