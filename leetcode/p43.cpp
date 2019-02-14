# include"Solutions.h"

// PENDING Carry-OVER problem...
// need to declare fixed length for the resulting string
// the trick on overflow!!!
string p43::multiply(string num1, string num2) {
	int len1 = num1.size();
	int len2 = num2.size();
	//string result(len1 + len2, '0'); // varaible length declarations
	string ans = "";
	vector<int> res(len1 + len2, 0); // put the integer for now
	for (int i = len1 - 1; i >= 0; i--) {
		for (int j = len2 - 1; j >= 0; j--) {
			int pos = i + j + 1;
			int tmp = res[pos] + (num1[i] - '0') * (num2[j] - '0');
			res[pos] = tmp % 10; // need to make sum first and then mode
			// need to examine carry-over
			res[pos - 1] += (tmp / 10);
		}
	}
	// eliminate unneccaray zeros at the front
	int i = 0;
	for (i = 0; i < len1 + len2; i++) {
		if (res[i] != 0) break;
	}
	if (i == len1 + len2) return "0"; // every digits = 1
	for (int j = i; j < len1 +len2 ; j++) {
		ans = ans + (char)(res[j] + '0');
	}
	
	return ans;
}

void p43::test() {
	string num1 = "2";
	string num2 = "0";
	cout << multiply(num1, num2);
}