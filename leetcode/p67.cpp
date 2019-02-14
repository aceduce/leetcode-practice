#include"Solutions.h"
string p67::addBinary(string a, string b) {
	int lena = a.size();
	int lenb = b.size();
	int len = max(lena, lenb) + 1;
	int i = lena - 1, j = lenb - 1;
	int indx = len - 1;
	vector<int> sum(len, 0); // store results in int format
	string ans = "";
	while (i >= 0 && j >= 0) {
		int x = a[i] - '0';
		int y = b[j] - '0';
		int tmp = x + y + sum[indx];
		sum[indx] = (tmp) % 2;
		sum[indx - 1] += tmp / 2;
		indx--;
		i--;
		j--;	
	}
	// deal with the not same digits issue
	while (i >= 0) {
		int tmp = sum[indx] + (a[i] - '0');
		sum[indx] = (tmp) % 2;
		sum[indx - 1] += tmp / 2;
		indx--;
		i--;
	}
	while (j >= 0) {
		int tmp = sum[indx] + (b[j] - '0');
		sum[indx] = (tmp) % 2;
		sum[indx - 1] += tmp / 2;
		indx--;
		j--;
	}
	int m = 0;
	while (m <= len - 1 && sum[m] == 0) { m++; };
	if (m == len) return "0"; // sum equals to zero!
	// convert the int to string
	for (int k = m; k <= len - 1; k++) {
		ans = ans + (char)(sum[k] + '0');
	}
	return ans;
}



void p67::test() {
	string a = "110010";
	string b = "10111";
	cout << addBinary(a, b);

}