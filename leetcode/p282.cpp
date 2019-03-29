#include"Solutions.h"
// a typical back-tracking question
// similar to an DFS

// difficulty comes when * show after +
// need to change the compute sequence...
class Solution {
public:
	void subadd(const string & num, int idx, int val, const int & target,
		vector<string> & ans, string & tmp) {

		if (idx == num.size()) {
			if (val == target)
				ans.push_back(tmp);
			return;
		}

		string ops{ "+-*/" };
		for (auto const & ch : ops) {
			string t = tmp;
			int v = val;
			if (ch == '+') {
				val += num[idx] - '0';
				tmp += ch;
				tmp += num[idx];
			}
			else if (ch == '-') {
				val -= num[idx] - '0';
				tmp += ch;
				tmp += num[idx];
			}
			else if (ch == '*') {
				val *= num[idx] - '0';
				tmp += ch;
				tmp += num[idx];
			}
			else if (ch == '/') {
				if (num[idx] != '0') {
					val /= num[idx] - '0';
					tmp += ch;
					tmp += num[idx];
				}
				else continue;
			}
			subadd(num, idx + 1, val, target, ans, tmp);
			tmp = t;
			val = v;
		}
		return;
	}

	vector<string> addOperators(string num, int target) {
		if (num.size() == 0) return {};
		int idx = 0;
		int val = num[0] - '0';
		vector<string> ans;
		string tmp;
		tmp += num[0];
		subadd(num.substr(1), idx++, val, target, ans, tmp);
		return ans;
	}
};