#include "Solutions.h"

string p179::helper(int input) {
	stringstream ss;
	ss << input;
	string tmp;
	ss >> tmp;
	return tmp;
}

struct p179::comp {
	bool operator()(const string & lhs, const string &rhs) {
		string t = lhs + rhs;
		string t2 = rhs + lhs;
		return t > t2;
	}
};
string p179::largestNumber(vector<int>& nums) {
	// NOT WORKING: vector<string> input{ nums.begin(), nums.end() };
	vector<string> input;
	if (nums.size() == 0) return "";
	string ans;
	for (auto const & num : nums) {
		input.push_back(helper(num));
	}
	sort(input.begin(), input.end(), comp());
	if (input[0] == "0") return "0";
	else {
		for (auto const & str : input) {
			ans = ans + str;
		}
	}
	return ans;
}

void p179::test() {
	vector<int> input{3, 30, 34, 5, 9};
	largestNumber(input);
}	