# include"Solutions.h"
vector<int> p66::plusOne(vector<int>& digits) {
	int carry_o = 0;
	for (int i = digits.size() - 1; i >= 0; i--) {
		if (i == digits.size() - 1) digits[i] += 1;
		int carry = digits[i] / 10;
		digits[i] = digits[i] % 10;
		if (i == 0) {
			carry_o = carry;
			break;
		}
		digits[i - 1] += carry;
	}
	if (carry_o) {
		vector<int> ans(digits.size()+1, 0);
		ans[0] = carry_o;
		copy(digits.begin(), digits.end(), ans.begin()+1);
		return ans;
	}
	else return digits;
}

void p66::test() {
	vector<int> input{9,9 };
	vector<int> out = plusOne(input);
	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}
	cout << endl;

}