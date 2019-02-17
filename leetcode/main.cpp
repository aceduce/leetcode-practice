
#include "Solutions.h"
#include "Struct.h"
#include "BST.h"

using namespace std; //needs standard library in C++

// Problem TWO:


//below is not working, not having a good grasp on the case
ListNode* addTwoNumbers_1(ListNode* l1, ListNode* l2) {
	//struct ListNode * temp;
	int carry = 0, num1, num2;
	ListNode * ans{ nullptr };
	ans = new ListNode{ -1 };
	ListNode * ans_t{ ans };
	ListNode * ans_t_pre{ nullptr };
	for (ListNode * i = l1, *j = l2; ; ) { 
		//need to hanle corner cases when one of them is shorter...
		// for loop is tricky		
		if (i->next == NULL and j->next == NULL and carry == 0) { //finish the calculations
			if (ans_t->val == -1) {
				ans_t_pre->next = NULL ; //trace back and delete!
			}
			return ans;
		}
		else {
			// regular conditions, still needs to calculate
			if (i != NULL) {
				num1 = i->val;
			}
			else num1 = 0;
			if (j != NULL) {
				num2 = j->val;
			}
			else num2 = 0;

			ans_t->val = (num1 + num2 + carry)%10;
			carry = (num1 + num2) / 10;
			// not finished, then create a new node
			ans_t->next = new ListNode{ -1 }; //place holder for a new value
			// this is just to delete previous ptr
			ans_t_pre = ans_t;
			ans_t = ans_t->next;
			//i = i->next, j = j->next;

			if (i->next == NULL) {
				num1 = 0; //and keeps the ptr
			}
			else i = i->next;

			if (j->next == NULL) {
				num2 = 0;
			}
			else j = j->next;
			
		}
		
		
	}
	return nullptr;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int carry = 0, num1, num2;
	int sum;
	ListNode * ans{ nullptr };
	ans = new ListNode{ -1 };
	ListNode * ans_t{ ans };

	for (ListNode * i = l1, *j = l2; ; ) {
		if (i != NULL) {
			num1 = i->val;
			i = i->next;
		}
		else num1 = 0;
		if (j != NULL) {
			num2 = j->val;
			j = j->next;
		}
		else num2 = 0;

		sum = (num1 + num2 + carry) % 10;
		ans_t->val = sum;
		carry = (num1 + num2 + carry) / 10;

		if (i!= NULL or j!= NULL or carry != 0) {
			//need to create a new node in answer
			ans_t->next = new ListNode{ -1 };
			ans_t = ans_t->next;
		}
		else
			return ans;
	}
}

void print_ptr(ListNode * p) {
	cout << "The Chain values is" << endl;
	cout << p->val << "->";
	p = p->next;
	for (auto i = p; ; i = i->next) {
		cout << i->val;
		if (i->next == NULL) {
			cout << endl;
			//cout << i->next->val;
			break;
		}
		cout << "->";
	}
		
	cout << endl;
}


int lengthOfLongestSubstring_1(string s) {
	int len = s.length();
	set <char> unique;
	for (int i = len; i > 0;  i--) {
		for (int j = 0; j <= len - i; j++) {
			// string is index from j to j+i
			int flag = 0;
			unique.clear();
			/*
			for (int k = 0; k < i; k++) { //see if repeating character exist, need an effective method to call into this!	
				for (int l = k+1; l < i; l++) {
					if (s[k+j] == s[l+j]) flag = 1; //this solution exeed time
				} */
			for (int k = j; k < j+i; k++) {
				if (unique.find(s[k]) != unique.end()) {
					flag = 1;
					break;
				}
				unique.insert(s[k]); // use set stil exeed the time for run!
			}
			if (flag == 0) return i;
		}
	}
	return 0;
}

int lengthOfLongestSubstring_2(string s) { //using unordered_set passed;
	int n = s.length();
	int i = 0, j = 0, mx = 0;
	unordered_set <char> unique;
	while (i < n && j < n) {
		if (unique.find(s[j]) == unique.end()) {
			unique.insert(s[j++]);
			mx = max(j - i, mx); //expand to the max length undere same i
		}
		else { //begin to have duplicate
			unique.erase(s[i++]);
		}
	}
	return mx;
}

int lengthOfLongestSubstring(string s) { //using unordered_map (like a hashmap in JAVA) passed;
	int n = s.length();
	int i = 0, j = 0, mx = 0;
	unordered_map <char, int> unique;
	while (i < n && j < n) {
		if (unique.find(s[j]) != unique.end()) {
			i = max(i, unique.find(s[j])->second);
		}
		//unique.insert({ s[j] , j+1 }); //should fail for duplicate..., not updating at all!!
		unique[s[j]] = j + 1; // mimicing a hashmap in Java
		mx = max(j - i + 1, mx); //expand to the max length undere same i
								 // need to always calcualte this step, other wise, ending with new character in "tmmzuxt"
		j++;
	}
	return mx;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	// another question is how to have both sored and merge them togher??
	int len1 = nums1.size();
	int len2 = nums2.size();
	// make sure m <= n 
	if (len1 > len2) {
		vector <int> temp = nums1;
		nums1 = nums2;
		nums2 = temp;
		int len_t = len1;
		len1 = len2;
		len2 = len_t;
	}
	int i, j;
	int imin = 0, imax = len1, half = (len1 + len2 + 1) / 2;
	while (imin <= imax) { // search range still makes sense!
		i = (imin + imax) / 2;
		j = half - i;
		if (i > imin && nums1[i - 1] > nums2[j]) { // i is too large
			imax = i - 1;
		}
		else if (i < imax && nums1[i] < nums2[j - 1]) { // i is too small
			imin = i + 1;
		}
		else {
			// good i, j selected
			int leftmax = 0;
			if (i == 0) leftmax = nums2[j - 1];
			else if (j == 0) leftmax = nums1[i - 1];
			else leftmax = max(nums1[i - 1], nums2[j - 1]);
			if ((len1 + len2) % 2 == 1)  return leftmax;

			int rightmin = 0;
			if (i == len1) rightmin = nums2[j];
			else if (j == len2) rightmin = nums1[i];
			else rightmin = min(nums1[i], nums2[j]);
			return (leftmax + rightmin) / 2.0;
		}
	} return 0;
}


int palindromic(string s, int i, int j, int mem [100][100]);


string longestPalindrome_n(string s) { //using Dynamic Programing here: do the number first, then index...
	int len = s.length();
	int start = 0, length = 0;
	bool P[1000][1000]{ false }; //the P matrix from the hint
	for (int i = 0; i < len - 1; i++) { //base conditions set for DP
		P[i][i + 1] = (s[i] == s[i+1]);
		P[i][i] = true;
	}
	P[len - 1][len - 1] = true;
	int m = 0;
	for (int j = 1; j < len; j++){
		for (int i = 0; i < len; i++)
		 {
			if (P[i][i + j] == false && (i + j < len)) {
				P[i][i + j] = (s[i] == s[i + j]) && P[i + 1][i + j - 1];
			}
			if (P[i][i + j] && (i + j) < len) {
				if (m <= j) { // max length of the palindromic!
					m = j;
					start = i;
					length = j;
				}
			}
		}		
	}
	return s.substr(start, length + 1);
}

int palindromic(string s, int i, int j, int mem[100][100]) { //pass 2-D array by reference ==> need more expansions
	if (mem[i][j] != NULL) {
		return mem[i][j];
	}
	if (j == i + 1 ) {// single word
		mem[i][j] = (s[i] == s[j]);
		return mem[i][j];
	} else if ((j == i)){
		mem[i][j] = true;
		return mem[i][j];
	} else if (s[i] == s[j]) {
		mem[i][j] = palindromic(s.substr(i + 1, j - 1 - i), i + 1, j - 1, mem);
		return mem[i][j];
	}
	else { // string index: i+1--> j; length = j-i // index: i --> j-1 ; lenght = j - i
		return mem[i][j] = max(palindromic(s.substr(i + 1, j - i), i + 1, j, mem), palindromic(s.substr(i, j  - i), i, j - 1, mem));
	}
}


// Critical points is fight against overflow!
int reverse(int x) {
	int rev = 0;
	while (x != 0) {
		int pop = x % 10;
		x /= 10;
		if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
		if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
		rev = rev * 10 + pop;
	}
	return rev;
}

// maybe I can extract the data from the first step!!
namespace p6 {
	int get_index(int n, int numRows) {
		int res = n % (2 * numRows - 2);
		if (res < numRows) { // vertial
			return res;
		}
		else { // zag
			res -= (numRows - 1);
			return numRows - res - 1;
		}

	}
	string convert(string s, int numRows) {
		if (numRows == 1) {
			return s;
		}
		int len = s.length();
		int unit_len = 2 * numRows - 2;
		//int unit = len / unit_len + (len / unit_len == 0) ? 0 : 1;
		string rev;
		// use array data structure
		// maybe can try linkedlist later or so on
		
		vector<vector<int> > vect(numRows, vector<int>()); //default values set to be -1
		for (int i = 0; i < len; i++) {
			vect[get_index(i, numRows)].push_back(i);
		}
		for (int i = 0; i < numRows; i++) {
			vector<int>:: iterator it = vect[i].begin();
			while (it != vect[i].end()) {
				rev += s[*it];
				it++;
			}
		}
		return rev;
	}

	

	int get_bloc(int n, int numRows) {
		return n / (2 * n - 2);
	}
}

namespace p8 {
	int myAtoi(string str) {
		int rev = 0; 
		int i = 0;
		bool positive = true;
		while (str[i] == ' ' || str[i] == '/t') i++; // reach the first non-white space character
		if (str[i] == '-') {
			positive = false;
			i++;
		} else if (str[i] == '+') {
			i++;
		}
		// exception handling is a pain ... in a..
		while(isdigit(str[i])) {
			if (rev > INT_MAX / 10 || rev < INT_MIN) {
				return positive ? INT_MAX : INT_MIN;
			}
			else if ((rev == INT_MAX / 10  && (str[i] - '0' >= 7 && positive))) {
				return INT_MAX;
			} else if ((rev == -INT_MIN / 10 && (str[i] - '0' >= 8 && !positive))) {
				return INT_MIN;
			}
			else {
				rev *= 10;
				rev += (str[i] - '0');
				i++;
			}
		}
		return positive ? rev : -rev;
	}
}

namespace p9 {
	bool isPalindrome(int x) {
		if (x < 0) return false;
		vector<int> vect;
		while (x != 0) {
			vect.push_back(x % 10);
			x /= 10;
		}
		vector<int>::iterator iter = vect.begin();
		int len = vect.end() - vect.begin();
		for (int i = 0; i < len/2; iter++, i++) {
			if (*iter != *(vect.begin() + len - i - 1))
				return false;
		}
		return true;
	}
}

namespace p10 {
	bool isMatch(string s, string p) {
		// if (s.empty() || p.empty()) return false; // strings will not both be empty
		// create a two-dimesional vectors
		// DP method: vect(S, P): 
		// s: length of the text
		// p: length of the pattern
		int s_len = s.size();
		int p_len = p.size();
		vector<vector<bool>> vect(s.size() + 1, vector<bool>(p.size() + 1, false)); // two-dimensional vector

		//initiallizeing
		vect[0][0] = true;
		/*
		for (int i = 1; i < s_len; i++) {
			vect[0][i] = false;
		}*/
		for (int j = 1; j <= p_len; j++) {
			if (p[j - 1] == '*') {
				vect[0][j] = vect[0][j - 2];
			}
		}
		// default values are all zero (false)

		// DP process:
		for (int i = 1; i < s_len + 1; i++)
			for (int j = 1; j < p_len + 1; j++) {
				if (p[j - 1] == '*') {
					// stars mean duplicate
					if (p[j - 2] == s[i - 1] || p[j - 2] == '.') { //  maybe able to change?
						vect[i][j] = vect[i][j - 2] || vect[i - 1][j];
					}
					else { // starts mean no string
						vect[i][j] = vect[i][j - 2];
					}
				}
				else if (s[i - 1] == p[j - 1] || p[j - 1] == '.') { // the comparing character matches
					vect[i][j] = vect[i - 1][j - 1];
				}
			}

		return vect[s_len][p_len];
	}
}

namespace p11 {

	int subMaxArea(int size, vector<int> & height) {
		if (size <= 1) {
			return 0;
		}
		else if (size == 2) {
			return min(height[0], height[1]);
		}
		int index = size - 1;
		int area = 0, area_n = 0;
		for (int i = 0; i < index; i++) {
			area_n = (index - i) * min(height[i], height[index]);
			area = max(area_n, area);
		}
		return max(area, subMaxArea(size - 1, height));
	}

	int maxArea(vector<int>& height) {
	  // recursively solving the problem:
		return subMaxArea(height.size(), height);
      // interpret into a DP problem...
		
	// from n = 3 forward, one can just use recursive method!

	  // insights into iterative methods...

	  // brutal force
	}

	
}

namespace p12 {
	string rep(int n, char sym) {
		string s; 
		for (int i = 0; i < n; i++) {
			s += sym;
		}
		return s;
	}

	string intToRoman(int num) {
		int digit = 0;
		string ret;
		int count = 0;
		while (num != 0) {
			digit = num % 10;
			if (digit == 9) {
				// a special case here 
				switch (count) {
				case 0: ret += "XI";//"IX";
					break;
				case 1: ret += "CX";//"XC";
					break;
				case 2: ret += "MC";//"CM";
					break;
				}
			}
			else if (digit >= 5) {
				// print 5 first and multiple Is
				switch (count) {
				case 0: ret += rep(digit - 5, 'I') + "V" ;
					break;
				case 1: ret += rep(digit - 5, 'X') + "L";
					break;
				case 2: ret += rep(digit - 5, 'C') + "D" ;
					break;
				}
			}
			else if (digit == 4) {
				switch (count) {
				case 0: ret += "VI";
					break;
				case 1: ret += "LX";
					break;
				case 2: ret += "DC";
					break;
				}
			}
			else { // digit < 4
				switch (count) {
				case 0: ret += rep(digit, 'I');
					break;
				case 1: ret += rep(digit, 'X');
					break;
				case 2: ret += rep(digit, 'C');
					break;
				case 3: ret += rep(digit, 'M');
					break;
				}
			}
			num = num / 10;
			count++;
		}
		int n = ret.length();
		for (int i = 0; i < n/2; i++) {
			char tmp = ret[i];
			ret[i] = ret[n - 1 - i];
			ret[n - 1 - i] = tmp;
		}
		return ret;
	}
}

namespace p13 {
	int romanToInt(string s) { // literally think about situations...
		// maybe having a map struture is better...
		int len = s.length();
		int rev = 0;
		map<string, int> mark_single; 
		map<string, int> mark_double;

		mark_single.insert(pair<string, int>("I", 1));
		mark_single.insert(pair<string, int>("V", 5));
		mark_single.insert(pair<string, int>("X", 10));
		mark_single.insert(pair<string, int>("L", 50));
		mark_single.insert(pair<string, int>("C", 100));
		mark_single.insert(pair<string, int>("D", 500));
		mark_single.insert(pair<string, int>("M", 1000));
		mark_double.insert(pair<string, int>("IV", 4));
		mark_double.insert(pair<string, int>("IX", 9));
		mark_double.insert(pair<string, int>("XL", 40));
		mark_double.insert(pair<string, int>("XC", 90));
		mark_double.insert(pair<string, int>("CD", 400));
		mark_double.insert(pair<string, int>("CM", 900));
		int freq = 0;
		// search the above patterns: 4/9 patterns first
		map<string, int>::iterator iterd = mark_double.begin();
		for (iterd; iterd != mark_double.end(); iterd++) {
			freq = 0;
			int pos = 0;
			while ((pos = s.find(iterd->first, pos)) != string::npos) {
				freq++;
				s[pos] = 'a';
				s[pos + 1] = 'a';
				pos += 2;
			}
			rev += iterd->second * freq;
			// str.replace(str.find(str2),str2.length(),str3);
			//s.replace(s.find(iterd->first), iterd->first.length(), " ");
		}

		map<string, int>::iterator iters = mark_single.begin();
		for (iters; iters != mark_single.end(); iters++) {
			freq = 0;
			freq = count(s.begin(), s.end(), iters->first[0]);
			rev += iters->second * freq;
			// str.replace(str.find(str2),str2.length(),str3);
			//s.replace(s.find(iterd->first), iterd->first.length(), " ");
		}

		return rev;
	}

}

//namespace p14 {
//	string longestcommonprefix(vector<string>& strs) {
//		if (strs.size() == 0) return "";
//		int min_size = int_max;
//		string min_str;
//		vector<string>::iterator iter = strs.begin();
//		cout << *iter << endl;
//		cout << strs.size() << endl;
//		for (auto & s : strs) {
//			if (min_size > s.size()) {
//				min_size = s.size();
//				min_str = s;
//			}
//		}
//
//
//		/* this for loop is not working...
//		for (auto & s : strs) {
//			if (min_size > s.size()) {
//				min_size = s.size();
//				min_str = s;
//			}
//		}
//		
//		for (int i = 0; i < strs.size(); i++) {
//			if (min_size > strs[i].length) {
//				min_size = strs[i].length;
//				min_str = strs[i];
//			}
//		} 
//		*/
//		
//		for (int i = min_str.size(); i > 0; i--) {
//			string sub = min_str.substr(0, i); // i : string length
//			bool compare = true;
//			for (auto s : strs) {
//				if (s.substr(0, i) != sub) {
//					compare = false;
//					break;
//				}
//			}
//			if (compare == true) {
//				return sub;
//			}
//		}
//		return "";
//	}
//}

namespace p15 {
	void twoSum(vector<int>& nums, vector<vector<int>>& output, int target, int index) {
		map<int, int> val2index;
		for (int i = index + 1; i < nums.size(); i++) {
			if (val2index.find(nums[i]) != val2index.end()) { //value exist!
				vector<int> tmp{ nums[index], nums[val2index[nums[i]]], nums[i] };
				sort(tmp.begin(), tmp.end());
				// deal with duplicates
				if (find(output.begin(), output.end(), tmp) == output.end()) { // no such element
					output.push_back(tmp); // find out a new three items
				}
			}
			val2index.insert(pair<int, int>{target - nums[i], i});
			
		}
	}
	vector<vector<int>> threeSum(vector<int>& nums) {
		// simplify the input vector if some values show more than three times
		set<int> uniq (nums.begin(), nums.end());
		if (uniq.size() == 0) return {};
		vector<int> newinput;
		if (nums.size() / uniq.size() > 5) {
			// recreate the inputs:
			set<int>::iterator i = uniq.begin();
			for (; i != uniq.end() ; i++) {
				for (int j = 0; j < count(nums.begin(), nums.end(), *i) && j < 3; j++) {
					newinput.push_back(*i);
				}
			}
			nums = newinput;
		}


		//break down this problem into twoSum problem (which I did before)
		int target = 0;

		vector<vector<int>> output;
		for (int i = 0; i < nums.size(); i++) {
			target = -nums[i];
			twoSum(nums, output, target, i);
		}
		// deal with duplicates
		// can we use set??
		return output;
	}
}


namespace p17 {

	void subLC(string input, vector<string> & ret, map<char, string> & table, string tmp) {
		// tmp is the string to be built
		if (tmp.size() == input.size()) {
			ret.push_back(tmp); //RIGHT PLACE TO ADD PUSHBACK
			return; //size is just right
		}
		// utillize the length there!, won't overflow due to above
		for (char ch : table[input[tmp.size()]]){
			tmp += ch;
			subLC(input, ret, table, tmp);
			//ret.push_back(tmp);
			tmp.pop_back(); // delte added character
			}
	}

	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		if (digits == "") {
			return ret;
		}
		//list<char> num2letter[10]; // use list data structure
		//num2letter[2].push_back('a');
		// vector<string> num2letter; // can also use map
		map<char, string> num2letter;
		num2letter.insert(pair<char, string> {'2', "abc"});   //2
		// store for 2, index = 0; there's a gap of 2
		num2letter.insert(pair<char, string> {'3', "def"});   //3
		num2letter.insert(pair<char, string> {'4', "ghi"});   //4
		num2letter.insert(pair<char, string> {'5', "jkl"});   //5
		num2letter.insert(pair<char, string> {'6', "mno"});   //6
		num2letter.insert(pair<char, string> {'7', "pqrs"});  //7
		num2letter.insert(pair<char, string> {'8', "tuv"});   //8
		num2letter.insert(pair<char, string> {'9', "wxyz"});  //9
		
		
		subLC(digits, ret, num2letter, ""); // "" refer to the string to be build
		return ret;
	}
}

namespace p16{
	// assume each question has exactly one answer:
	// pay particular attention to how to move to avoid duplicate!
	int threeSumClosest(vector<int>& nums, int target) {
		int i = 0, j, k; // 3 pointers method
		int n = nums.size();
		sort(nums.begin(), nums.end());
		if (nums.size() <= 2) { // less than 3 varaibles
			return -1; 
		}
		// vector<vector<int>> ans;
		int ret = 0;
		int gap = INT_MAX;
		int ans;
		while (i <= n - 2) {
			j = i + 1;
			k = n - 1;
			while (j < k) {
				int gapp = INT_MAX, gapn = INT_MAX;
				ret = nums[i] + nums[j] + nums[k];
				if (ret > target) {
				gapp = ret - target;
				while (k > 0 && nums[k] == nums[k - 1]) { k--; }
				k--; // even k = 0 is Okay
				//ans.pop_back();
				//ans.push_back({ nums[i], nums[j], nums[k]});
				}		
				else if (ret < target) {
				gapn = target - ret;
				// move left and right pointer {j, k}
				// j could access to out of bond number
				while (j < n - 1 && nums[j] == nums[j + 1]) { j++; }
				j++;
				}
				else {
					return target; //no gap;
				}
				// too simple: gap = min(gap, min(gapp, gapn));		
				// need to find the sum:
				gap = min(gap, min(gapp, gapn));
				if (abs(ret - target) == gap) ans = ret;
			}
			// find one smaller, move i
			while (i < n - 2 && nums[i] == nums[i + 1]) { i++; }
			i++;
		}
		return ans;
	}
}

namespace p18 {
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		// ret: return answer
		vector<vector<int>> ret; 
		sort(nums.begin(), nums.end());
		if (nums.size() == 0) return ret; // default is an empty vector return
		int n = nums.size();
		for (int i = 0; i < n - 3; i++) {
			while (i != 0 && nums[i] == nums[i - 1]) { i++; } // shift i to avoid duplicate, but the first index is an exception
			for (int j = i + 1; j < n - 2; j++) {
				while (j != i + 1 && j < n -2 && nums[j] == nums[j - 1]) { j++; } // if not adding && j < n -2, j could overflow? 
			// the last left/right pointer
				int left = j + 1;
				int right = n - 1; 
				while (left < right) {
					if (target - nums[i] - nums[j] > nums[left] + nums[right]) {
						left++;
						while (left <= n - 2 && nums[left - 1] == nums[left]) { left++; }
					}
					else if (target - nums[i] - nums[j] < nums[left] + nums[right]) {
						right--; //order matters
						while (right >=3 && nums[right + 1] == nums[right]) { right--; }
					}
					else { // a successful insertion
						ret.push_back({ nums[i], nums[j], nums[left], nums[right] });
						left++;
						while (left <= n - 2 && nums[left - 1] == nums[left]) { left++; }
						right--;
						while (right >= 3 && nums[right + 1] == nums[right]) { right--; }
					}
				}
			}

		}
		return ret;
	}
}

namespace p19 {
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		// delete n-th element from the end
		// single-linked list
		// keep log and log + n

		int log = 0;  
		ListNode *log_ptr = head;
		ListNode *log_ptr_n = head;
		// this may only work with n > 1
		for (int i = 0; i < n; i++) {
			log_ptr_n = log_ptr_n->next;
		}
		if (log_ptr_n == NULL) {
			head = head->next;
			return head;
		}
		while (log_ptr_n->next != NULL) {
			log_ptr_n = log_ptr_n->next;
			log_ptr = log_ptr->next;
		}
		//remove
		log_ptr->next = log_ptr->next->next;	
		return head;
	}
}

namespace p20 {
	bool isValid(string s) { //intends to use stack data structure
		if (s.size() == 0) {
			return true;
		}
		map<char, char> tab;
		tab.insert(pair<char, char>{'{', '}'});
		tab.insert(pair<char, char>{'[', ']'});
		tab.insert(pair<char, char>{'(', ')'});

		stack<int> current;
		for (int i = 0; i < s.size(); i++) {
			if (current.size() != 0) {
				if (tab.count(current.top()) != 0) { // contatins
					if (s[i] == tab[current.top()]) {
						current.pop();
						continue;
					}
				}
			
			}
			current.push(s[i]);
		}
			return current.size() == 0 ? true : false;

		}
	}



namespace p21 {
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
		
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode * ans = new ListNode{ -1 };
		ListNode * head = ans;
		ListNode * p1 = l1, *p2 = l2;
		while (p1!= NULL && p2!= NULL) {
			if (p1->val < p2->val) { // this sequence matters alot. first assign next, then value
				ListNode *tmp = new ListNode{ -1 };
				ans->next = tmp;
				ans = ans->next;
				ans->val = p1->val;
				p1 = p1->next;
			}
			else {
				ListNode *tmp = new ListNode{ -1 };
				ans->next = tmp;
				ans = ans->next;
				ans->val = p2->val;
				p2 = p2->next;
			}
		}
		while(p1 != NULL) {
			ListNode *tmp = new ListNode{ -1 };
			ans->next = tmp;
			ans = ans->next;
			ans->val = p1->val;
			p1 = p1->next;
		}
		while(p2 != NULL) {
			ListNode *tmp = new ListNode{ -1 };
			ans->next = tmp;
			ans = ans->next;
			ans->val = p2->val;
			p2 = p2->next;
		}
		ans = NULL;
		return head->next;
	}

}

namespace p22 {
	// using backtracking:
	void subgP(string tmp, vector<string> &ans, int left, int right, int n) {
		if (right == n) {
			ans.push_back(tmp);
		}
		if (left < n) {
			subgP(tmp + '(', ans, left + 1, right, n);
		}
		if (right < left) {
			subgP(tmp + ')', ans, left, right + 1, n);
		}
	}

	vector<string> generateParenthesis(int n) {
		string tmp = "";
		vector<string> ans;
		subgP(tmp, ans, 0, 0, n);
		return ans;
	}
}

namespace p23 {
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	class NodeCompare {
	public:
		bool operator()(ListNode *a, ListNode *b) { // overloading...
			return a->val > b->val;
		}
	};
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, NodeCompare> pq;
		ListNode* ans = new ListNode{ -1 }; //head
		ListNode* ret = ans; //return the ret->next as head
		// need to overwrite the compare function for priority queue
		for (int i = 0; i < lists.size(); i++) { // push into the first element into the pq
			if (lists[i] != NULL) {
				pq.push(lists[i]);
			}
			// once push in, no need to worries about next, as each string will continue
			// this is the beauty of linkedlist
		}
		while (!pq.empty()) {
			ListNode * tmp = pq.top();
			pq.pop();
			ans->next = tmp;
			if (tmp->next != NULL) { // still has element 
				pq.push(tmp->next);
			}
			ans = ans->next;
		}
		return ret->next;

	}
}

namespace p24 {
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	ListNode * swapPairs(ListNode* head) {
		ListNode * dummy = new ListNode{ -1 }; // on the heap
		dummy->next = head;
		ListNode * ans = dummy;
		while (dummy->next != NULL && dummy->next->next != NULL) {
			//swap the nodes
			ListNode * tmp = dummy->next;
			dummy->next = dummy->next->next;
			tmp->next = dummy->next->next;
			dummy->next->next = tmp;

			// move the pointers:
			dummy = dummy->next->next;
		}
		return ans->next;
	}
}

namespace p25 {
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	ListNode* subreverse(ListNode *pre, const int &k);
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL) return NULL;

		ListNode * dummy = new ListNode{ 0 };
		dummy->next = head;
		ListNode * pre = dummy; // return pointer
		while (pre!= NULL) {
			pre = subreverse(pre, k);
		}
		return dummy->next;
		
	}
	ListNode* subreverse(ListNode *pre, const int &k) {
		//if (pre == NULL) return NULL;
		ListNode * last{ pre };
		
		for (int i = 0; i < k + 1; i++) {
			last = last->next;
			if (i!= k && last == NULL) return NULL; // earlier exit, means no need to change the link
		}
		// these two variables need to be declare here! as less than k cases are elimated from the return NULL branch!
		ListNode * current{ pre->next->next };  
		ListNode * tail{ pre->next };
		//ListNode * next;
		//last = next->next;
		while (current != last) {
			ListNode* tmp{ current->next };
			current->next = pre->next; // wrong: current->next = tail
			pre->next = current;
			tail->next = tmp;
			current = tmp;
		}
		return tail;
	}
}

namespace p26 {
	int removeDuplicates(vector<int>& nums) {
		for (int i = 0; i < nums.size() ; i++) { 
			int k = i + 1; // k project next index to go!
			
			int l = 0;
			if (k > nums.size() - 1) {
				// last i --> unique element
				return nums.size();
			}
			while (nums[k - 1] == nums[k]) {
				k++;  //  find the unique k --> problematic as at the end of array duplicate, no new element, aka ending with duplicate
				l++;
				if (k > nums.size() - 1) {
					// last i --> duplicate element
					return nums.size() - l;
				}
			}
			if (l > 0) {
				nums.erase(nums.begin() + i + 1, nums.begin() + k);
			}
			//i = k - l - 1;
		}
		return nums.size();
	}
}

namespace p27 {
	int removeElement(vector<int>& nums, int val) {
		int n = nums.size();
		for (int i = 0; i < n;) {
			if (nums.at(i) == val) {
				while (nums.at(n - 1) == val) {
					n--;
					if (n <= i || n < 1) { return i; }
				}
				nums.at(i) = nums.at(n - 1);
				n--;
			}
			i++;
		}
		return n;
	}
}

namespace p28 {
	int strStr(string haystack, string needle) {
		if (needle.size() == 0) return 0;
		else if (haystack.length() == 0) return -1;

		int hlen = haystack.length();
		int nlen = needle.length();
		
		for (int i = 0; i <= hlen - nlen; i++) {
			int k = i;
			int j = 0;
			while (haystack[k] == needle[j]) { 
				k++, j++;
				if (j == nlen) return i;
			}
			//if (j == nlen) return i;
		} 
		return -1;
	}
}

namespace p29 {
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN) {
			if (divisor == -1) return INT_MAX; //overflow
			else if (divisor == 1) return INT_MIN;
		}
		// convert the data formats
		long long divd = (long long)dividend;
		long long divi = (long long)divisor;
		int sign = 1;
		if (divd < 0) {
			divd = -divd;
			sign = -sign;
		}
		if (divi < 0) {
			divi = -divi;
			sign = -sign;
		}
	
		int res = 0;
		while (divd >= divi) {
			// bit shifting method
			long long int tmp = divi;
			int shift = 0;
			while (divd >= tmp) {
				shift++;
				tmp = (divi << shift);
			}
			shift--;
			divd = divd - (divi << shift);
			res += (1 << shift);
		}
		return sign*res;
	}
}



int main() {
	/* Problem 1
	vector<int> num{ 3,3, 7, 8 };
	int target = 6;
	vector <int> v;
	v = twoSum(num, target);
	for (auto i = v.begin(); i != v.end(); i++)
		cout << *i << ' ';
	cout << endl;
	*/

	/* Problem 2

	ListNode * L1{ nullptr };

	L1 = new ListNode{2};
	ListNode * L_t{ L1 };
	L_t->next = new ListNode{ 4 };
	//L_t = L_t->next;
	//L_t->next = new ListNode{ 3 };


	// print the numbers
	print_ptr(L1);

	ListNode * L2{ nullptr };
	L2 = new ListNode{ 5 };
	L_t = L2;
	L_t->next = new ListNode{ 6 };
	L_t = L_t->next;
	L_t->next = new ListNode{ 8 };

	// print the numbers
	print_ptr(L2);


	ListNode * ans = addTwoNumbers(L1, L2);
	co	ut << "Answer is " << endl;
	print_ptr(ans);
	*/

	/* Problem #3
	string s{ "tmmzuxt" };
	int len = lengthOfLongestSubstring(s);
	cout << len;
	*/

	/* Problem # 4:
	// Like a typical binary- search -ritural:
	vector <int> a {4,5};
	vector <int> b{ 1,2,3 };
	int x = findMedianSortedArrays(a, b);
	cout << x;
	*/

	/*Problem 5:
	string s { "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth" };
	//s = "cbbd";
	cout << s.length();
	cout << longestPalindrome_n(s) << endl;
	*/

	// Problem 6

	// P7  Reverse Integer
	//int result=  reverse(1534236469); // maximum

	//int result = reverse(-2147483648); // minimum
	//int result = reverse(0); // minimum
	//cout << result;

	//P6 Zigzag
	//string s = p6::convert("ABC",  2);


	// int s = p8::myAtoi("42");
	//s = p8::myAtoi("   -42");
	//s = p8::myAtoi("4193 with words");
	//s = p8::myAtoi("words and 987");
	int s = p8::myAtoi("91283472332"); // handle exceptions
	//s = p8::myAtoi("+42");
	//int s = p8::myAtoi("+2147483649");
	//cout << s;
	//P8 atoi

	/*
	cout << p9::isPalindrome(108901);
	char in;
	cin >> in;
	*/
	vector<int> vec{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	//vector<int> vec{ 1, 1 };
	//cout << p11::maxArea(vec);

	//cout << p12::intToRoman(1994) << endl;

	//cout << p13::romanToInt("MCMXCIV");
	//string s1 = "flower";
	//string s2 = "flow";
	//string s3 = "flight";
	//vector<string> input{s1, s2, s3};
	//cout << p14::longestcommonprefix(input);

	//p15
	/*
	vector<int> input{ -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> out = p15::threeSum(input);
	for (int i = 0; i < out.size(); i++) {
		for (int j = 0; j < out[i].size(); j++) {
			cout << out[i][j] << " ";
		}
		cout << endl;
	}
	*/

	//p10
	/*
	string t{ "aab" };
	string p{ "c*a*b" };
	p = "ab*a*c*a";
	t = "aaa";
	//t = "";
	//p = ".*";
	bool ret = p10::isMatch(t, p);
	cout << ret << endl;
	//cout << p.empty() << endl;
	*/

	//p17
	/*
	vector<string> ans = p17::letterCombinations("");
	for (vector<string>::iterator i = ans.begin(); i != ans.end(); i++) {
	cout << *i << endl;
	}
*/
/*
vector<int> input{ -1, 0, -5, -2, -2, -4, 0, 1, -2 };
int target = -9;
vector<vector<int>> out = p18::fourSum(input, target);
for (vector<vector<int>>::iterator i = out.begin(); i != out.end(); i++) {
	for (auto e : *i) {
		cout << e << " ";
	}
	cout << endl;
}
*/

//p19:
/*
p19::ListNode n0{ 1 };
p19::ListNode n1{ 2 };
p19::ListNode n2{ 3 };
p19::ListNode n3{ 4 };
p19::ListNode n4{ 5 };
p19::ListNode n5{ 6 };
n0.next = &n1;
n1.next = &n2;
n2.next = &n3;
n3.next = &n4;
n4.next = &n5;
n5.next = NULL;
cout << "Beginning links" << endl;
p19::ListNode * ptr{ &n0 };
while (ptr!= NULL) {
cout << ptr->val << "->";
ptr = ptr->next;
}
cout << "Ending links" << endl;
p19::ListNode * ans = p19::removeNthFromEnd(&n0, 6);
while (ans!= NULL) {
cout << ans->val << "->";
ans = ans->next;
}
cout << endl;

cout << p20::isValid("{[]}") << endl;
*/
/*p21:

p21::ListNode n0{ 1 };
p21::ListNode n1{ 2 };
p21::ListNode n2{ 4 };
n0.next = &n1;
n1.next = &n2;
p21::ListNode n3{ 1 };
p21::ListNode n4{ 3 };
p21::ListNode n5{ 4 };
n3.next = &n4;
n4.next = &n5;


cout << "Ending links" << endl;
p21::ListNode * ans = p21::mergeTwoLists(&n0, &n3);
while (ans != NULL) {
	cout << ans->val << "->";
	ans = ans->next;
}
cout << endl;

vector<string> ans1 = p22::generateParenthesis(3);

for (vector<string>::iterator i = ans1.begin(); i != ans1.end(); i++) {
	cout << *i << endl;
}
*/
/*p23
p23::ListNode n0{ 1 };
p23::ListNode n1{ 4 };
p23::ListNode n2{ 5 };
n0.next = &n1;
n1.next = &n2;
p23::ListNode n3{ 1 };
p23::ListNode n4{ 3 };
p23::ListNode n5{ 4 };
n3.next = &n4;
n4.next = &n5;
p23::ListNode n6{ 2 };
p23::ListNode n7{ 6 };
n6.next = &n7;

vector<p23::ListNode*>* ans3 = new vector<p23::ListNode*>{&n0, &n3, &n6};

p23::ListNode * ans = p23::mergeKLists(*ans3);

while (ans != NULL) {
cout << ans->val << " -> ";
ans = ans->next;
}
cout << endl;
*/

/*p24
p24::ListNode n0{ 1 };
p24::ListNode n1{ 2 };
p24::ListNode n2{ 3 };
p24::ListNode n3{ 4 };
n0.next = &n1;
n1.next = &n2;
n2.next = &n3;
p24::ListNode* node = p24::swapPairs(&n0);
while (node != NULL) {
	cout << node->val << " -> ";
	node = node->next;
}
cout << endl;
*/

/*
	vector<int> inp = { 0,0,1,1,1,2,2,3,3,4,4};
	cout << p26::removeDuplicates(inp) << endl;

	vector<int> inp2 = { 3,2,2,3 };
	cout << p27::removeElement(inp2, 3) << endl;
	string string1 = "a";
	string string2 = "a";
	cout << p28::strStr(string1, string2);

	cout << p29::divide(2147483647, 1) << endl;
	*/

	/*p30

	Solutions::p30 p30;
	vector<string> inp3 = { "word", "good", "best", "good" };
	string str = "wordgoodgoodgoodbestword";

	vector<int> outp3 = p30.findSubstring(str, inp3);

	for (vector<int>::iterator i = outp3.begin(); i != outp3.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	*/

	/* p31:
	*/
	vector<int> input{ 1, 2 };
	Solutions::p31 p31;
	p31.nextPermutation(input);
	for (vector<int>::iterator i = input.begin(); i != input.end(); i++) {
		cout << *i << " " << endl;
	}

	/* p32:
	*/
	string input32 = "(()())"; //"()(())"; "(()())"
	Solutions::p32 p32;

	cout << p32.longestValidParentheses(input32);

	cout << " ******************** " << endl;
	p33 * problem33 = new p33;
	vector<int> vect{ 4,5,6,7,0,1,2 };
	cout << problem33->search(vect, 3);
	delete problem33;

	p34 * problem34 = new p34;
	vector<int> nums{ 5, 7, 7, 8, 8 ,10 };
	vector<int> ans = problem34->searchRange(nums, 6);
	for (vector<int>::iterator i = ans.begin(); i != ans.end(); i++) {
		cout << *i << " ";
	}

	p35 * problem35 = new p35;
	vector<int> nums1{ 1,3,5,6 };
	cout <<problem35->searchInsert(nums1, 0) << endl;

	p36 * problem36 = new p36;
	vector<vector<char>> inp36 = { { '7','.','.','.','4','.','.','.','.' },{ '.','.','.','8','6','5','.','.','.' },{ '.','1','.','2','.','.','.','.','.' },{ '.','.','.','.','.','9','.','.','.' },{ '.','.','.','.','5','.','5','.','.' },{ '.','.','.','.','.','.','.','.','.' },{ '.','.','.','.','.','.','2','.','.' },{ '.','.','.','.','.','.','.','.','.' },{ '.','.','.','.','.','.','.','.','.' } };

	/*
	vector<vector<char>> inp36 = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' },{ '6','.','.','1','9','5','.','.','.' },{ '.','9','8','.','.','.','.','6','.' },
	{ '8','.','.','.','6','.','.','.','3' },{ '4','.','.','8','.','3','.','.','1' },{ '7','.','.','.','2','.','.','.','6' },{ '.','6','.','.','.','.','2','8','.' },
	{ '.','.','.','4','1','9','.','.','5' },{ '.','.','.','.','8','.','.','7','9' } };
	*/

	/*
	p37 * problem37 = new p37;
	vector<vector<char>> inp37 = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' },{ '6','.','.','1','9','5','.','.','.' },{ '.','9','8','.','.','.','.','6','.' },
	{ '8','.','.','.','6','.','.','.','3' },{ '4','.','.','8','.','3','.','.','1' },{ '7','.','.','.','2','.','.','.','6' },{ '.','6','.','.','.','.','2','8','.' },
	{ '.','.','.','4','1','9','.','.','5' },{ '.','.','.','.','8','.','.','7','9' } };
	problem37->solveSudoku(inp37);
	for (int i = 0; i < 9; i++) {
		cout << " [ ";
		for (int j = 0; j < 9; j++)
			cout << inp37[i][j] << " ";
		cout << " ] " << endl;;
	}
	*/

	/*
	p38 * problem38 = new p38;
	cout << problem38->countAndSay(10) << endl;
	cout << endl;
	*/

	p39 * problem39 = new p39;
	vector<int> inp39{ 2, 3, 5 };
	int target = 8;
	vector<vector<int>> ans39 = problem39->combinationSum(inp39, target);
	for (vector<vector<int>>::iterator i = ans39.begin(); i != ans39.end(); i++) {
		cout << "[ ";
		for (auto & e : *i) {
			cout << e << " ";
		}
		cout << " ] " << endl;
	}

	p40 * problem40 = new p40;
	vector<int> inp40{ 10,1,2,7,6,1,5 };
	target = 8;
	vector<vector<int>> ans40 = problem40->combinationSum2(inp40, target);
	for (vector<vector<int>>::iterator i = ans40.begin(); i != ans40.end(); i++) {
		cout << "[ ";
		for (auto & e : *i) {
			cout << e << " ";
		}
		cout << " ] " << endl;
	}

	


	p70 * problem = new p70;
	problem->test();
	delete problem;

	
	/*
	p46 * problem46 = new p46;
	problem46->test();
	delete problem46;
	*/
	



	system("pause");
}