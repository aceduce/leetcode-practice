#include"Solutions.h"
// 小Q
// emulation quetions
string p166::fractionToDecimal(long numerator, long denominator) {
	bool pos = true;
	long long a = numerator;
	long long b = denominator;
	if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) pos = false; // negative sign
	if (a < 0) a = -a;
	if (b < 0) b = -b;

	string ret;
	char tmp[20];
	int res = a / b;
	long long mode = a % b;
	sprintf_s(tmp, "%lld", res);
	ret += string(tmp);

	//while (mode > 0) { // with resisudals in the division
	map<pair<long long, long long>, int> m; // a / b = c + d;  <c, d>  ==> key, the value is index
	
	if (mode == 0) return pos ? ret : "-" + ret;
	else if (mode != 0) {
		ret += ".";
		string decimal = "";
		//cout << "Make_pair = " << m[make_pair(c, d)] << endl;
		for (int index = 1; ; index++) { // 
			mode = mode * 10; // first digit
			long long c = mode / b;
			long long d = mode % b;

			if (m[make_pair(c, d)] != 0) {
				// repeating number
				// prep to return the answer:
				int left = m[make_pair(c, d)] - 1;
				ret += decimal.substr(0, left); // decimal 0 is zero
				// 0.666--> 0: empty, 1: 6
				ret += '(';
				ret += decimal.substr(left, decimal.size()-left) + ')';
				break;
			}
			else {
				m[make_pair(c, d)] = index;
				// add into 
				decimal += c + '0';
			}
			if (d == 0) {// with no residual left
				ret += decimal;
				break;
			}
			mode = d;
			//}
		}
	}
	
	return pos? ret : "-" + ret;
}

void p166::test() {
	//cout << fractionToDecimal(-2147483648, 1) << endl;
}