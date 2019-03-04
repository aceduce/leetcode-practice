#include"Solutions.h"
// 小Q
// https://www.youtube.com/watch?v=tLKQxz1Ww4c
pair<int, int> extract(string s) { // extract coeffcinet for left and right
	// state machine transfer
	// Three States: 0 --> +/- sign 
	//				 1 --> digits 
	//               2 --> x 
	int coeff = 0, number = 0; // number is the rolling one...
	int cons = 0;
	int mul = 1;
	int state = 0;
	s += '&';
	for (auto const & ch : s) {
		// state
		if (state == 0) { // sign state
			if (ch == '+') { continue; }
			else if (ch == '-') { mul = -mul; continue; }
			else if (isdigit(ch)) { state = 1; number = ch - '0'; continue; }
			else if (ch == 'x') { state = 2; coeff+= mul; continue; } // pay attention to the mul here!!
		}
		else if (state == 1) { // digit state
			if (ch == '+') { cons += mul * number; mul = 1; state = 0;  continue; } // x follow by a digit
			else if (ch == '-') { cons += mul * number; mul = -1; state = 0; continue; }
			else if (ch == '&') { cons += mul * number; break; }
			else if (ch == 'x') { state = 2;  coeff += mul * number; continue; }
			else if (isdigit(ch)) { number = number * 10 + ch - '0';  continue; }
		}
		else if (state == 2) { // state for x
			if (ch == '+') { state = 0; mul = 1; continue; } // correspond to initialization
			else if (ch == '-') { mul = -1; state = 0; continue; }
			else if (ch == '&') { break; }
		}	
	}
	pair<int, int> ret = { coeff, cons };
	return ret;
}
// State Machine Switching
string p640::solveEquation(string equation) {
	// divide into left and right portion:
	string left = equation.substr(0, equation.find("="));
	string right = equation.substr(equation.find("=") + 1, string::npos);
	pair<int, int> a = extract(left);
	pair<int, int> b = extract(right);
	int a_ = a.first - b.first;
	int b_ = b.second - a.second;
	if ((a_==0) && (b_==0)) return "Infinite solutions"; 
	if (a_ == 0) return "No solution";
	return "x=" + to_string(b_ / a_);
}

void p640::test() {
	string s = "x+5-3+x=6+x-2";
	cout << solveEquation(s) << endl;
}