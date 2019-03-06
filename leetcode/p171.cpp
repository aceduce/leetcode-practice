#include"Solutions.h"
int p171::titleToNumber(string s) {
	int ans = 0;
	int tmp = 0;
	for (auto const & ch : s) {
		tmp = tmp * 26;
		tmp += ch - 'A' + 1;
	}
	return ans = tmp;
}

void p171::test() {
	cout << titleToNumber("ZY") << endl;
}