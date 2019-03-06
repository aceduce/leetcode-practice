#include"Solutions.h"
// convert back: this is reverse to p171
string p168::convertToTitle(int n) {
	string ans;
	while (n > 0) {
		char ch;
		ch = (n - 1) % 26 + 'A';
		ans = ch + ans;
		n = (n - 1) / 26;
	}
	return ans;
}

void p168::test() {
	cout << convertToTitle(52) << endl;
}