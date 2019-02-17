#pragma once
# include<vector>
# include<map>
# include<iostream>
# include<queue>
# include<list>
# include<set>
# include<unordered_set>
# include<unordered_map>
# include <algorithm>
# include<string>
# include<cmath>
# include <regex> 
# include <ctype.h>
# include <stack>
# include "Struct.h"
# include "BST.h"


using namespace std;

// declare all the questions
class Solutions
{
public:

	Solutions();
	~Solutions();
	class p31 {
	public:
		void nextPermutation(vector<int>& nums);
	};
	class p30 {
	public:
		// considering print out the problem sereis through constructor
		// consider not using inline class/ use inheritance!
		vector<int> findSubstring(string s, vector<string>& words);
	};
	class p32 {
	public:
		int longestValidParentheses(string s);
	};
	
	
};


class p33 : public Solutions
{
public:
	p33() {
		cout << "Question # : "<<((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int search(vector<int>& nums, int target);
};


class p34 : public Solutions
{
public:
	p34() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<int> searchRange(vector<int>& nums, int target);
	void searchneighbor(const int & pos, vector<int> & nums, vector<int> &ans, const int & target);
};

class p35 : public Solutions
{
public:
	p35() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int searchInsert(vector<int>& nums, int target);
};


class p36 : public Solutions
{
public:
	p36() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	bool isValidSudoku(vector<vector<char>>& board);
};

class p37 : public Solutions
{
public:
	p37() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void solveSudoku(vector<vector<char>>& board);
};

class p38 : public Solutions
{
public:
	p38() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	string countAndSay(int n);
};

class p39 : public Solutions
{
public:
	p39() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);
};

class p40 : public Solutions
{
public:
	p40() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
};


class p41 : public Solutions
{
public:
	p41() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int firstMissingPositive(vector<int>& nums);
};

class p42 : public Solutions
{
public:
	p42() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int trap(vector<int>& height);
	void test();
};

class p43 : public Solutions
{
public:
	p43() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	string multiply(string num1, string num2);
	void test();
};


class p44 : public Solutions
{
public:
	p44() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	//vector<vector<int>> permuteUnique(vector<int>& nums);
	void test();
};


class p45 : public Solutions
{
public:
	p45() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int jump(vector<int>& nums);
	void test();
};


class p46 : public Solutions
{
public:
	p46() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<vector<int>> permute(vector<int>& nums);
	void test();
};


class p47 : public Solutions
{
public:
	p47() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<vector<int>> permuteUnique(vector<int>& nums);
	void test();
};

class p48 : public Solutions
{
public:
	p48() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void rotate(vector<vector<int>>& matrix);
	void test();
};

class p49 : public Solutions
{
public:
	p49() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<vector<string>> groupAnagrams(vector<string>& strs);
	void test();
};

class p50 : public Solutions
{
public:
	p50() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	double myPow(double x, int n);
	void test();
};

class p51 : public Solutions
{
public:
	p51() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<vector<string>> solveNQueens(int n);
	void test();
};

class p54 : public Solutions
{
public:
	p54() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<int> spiralOrder(vector<vector<int>>& matrix);
	void test();
};

class p55 : public Solutions
{
public:
	p55() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	bool canJump(vector<int>& nums);
	void test();
};

class p58 : public Solutions
{
public:
	p58() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int lengthOfLastWord(string s);
	void test();
};

class p59 : public Solutions
{
public:
	p59() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<vector<int>> generateMatrix(int n);
	void test();
};

class p62 : public Solutions
{
public:
	p62() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int uniquePaths(int m, int n);
	void test();
};

class p63 : public Solutions
{
public:
	p63() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
	void test();
};

class p66 : public Solutions
{
public:
	p66() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<int> plusOne(vector<int>& digits);
	void test();
};

class p67 : public Solutions
{
public:
	p67() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	string addBinary(string a, string b);
	void test();
};

class p69 : public Solutions
{
public:
	p69() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int mySqrt(int x);
	void test();
};

class p70 : public Solutions
{
public:
	p70() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int climbStairs(int n);
	void test();
};


class p73 : public Solutions
{
public:
	p73() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void setZeroes(vector<vector<int>>& matrix);
	void test();
};

class p76 : public Solutions
{
public:
	p76() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	string minWindow(string s, string t);
	void test();
};


class p77 : public Solutions
{
public:
	p77() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<vector<int>> combine(int n, int k);
	void test();
};

class p78 : public Solutions
{
public:
	p78() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<vector<int>> subsets(vector<int>& nums);
	void test();
};

class p79 : public Solutions
{
public:
	p79() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	bool exist(vector<vector<char>>& board, string word);
	void test();
};

class p80 : public Solutions
{
public:
	p80() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int removeDuplicates(vector<int>& nums);
	void test();
};

class p81 : public Solutions
{
public:
	p81() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	bool search(vector<int>& nums, int target);
	void test();
};

class p82 : public Solutions
{
public:
	p82() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	ListNode* deleteDuplicates(ListNode* head);
	void test();
};


class p83 : public Solutions
{
public:
	p83() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	ListNode* deleteDuplicates(ListNode* head);
	void test();
};

class p84 : public Solutions
{
public:
	p84() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int largestRectangleArea(vector<int>& heights);
	void test();
};

class p85 : public Solutions
{
public:
	p85() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int maximalRectangle(vector<vector<char>>& matrix);
	void test();
};

class p86 : public Solutions
{
public:
	p86() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	ListNode* partition(ListNode* head, int x);
	void test();
};

class p87 : public Solutions
{
public:
	p87() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	bool isScramble(string s1, string s2);
	void test();
};

class p88: public Solutions
{
public:
	p88() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
	void test();
};

class p89 : public Solutions
{
public:
	p89() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<int> grayCode(int n);
	void test();
};

class p90 : public Solutions
{
public:
	p90() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums);
	void test();
};

class p91 : public Solutions
{
public:
	p91() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int numDecodings(string s);
	void test();
};


class p92 : public Solutions
{
public:
	p92() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	ListNode* reverseBetween(ListNode* head, int m, int n);
	void test();
};

class p93 : public Solutions
{
public:
	p93() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<string> restoreIpAddresses(string s);
	void test();
};


class p94 : public Solutions
{
public:
	p94() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<int> inorderTraversal(TreeNode* root);
	void test();
};

class p95 : public Solutions
{
public:
	p95() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<TreeNode*> generateTrees(int n);
	void test();
};

class p96 : public Solutions
{
public:
	p96() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int numTrees(int n);
	void test();
};

class p97 : public Solutions
{
public:
	p97() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	bool isInterleave(string s1, string s2, string s3);
	void test();
};

class p98 : public Solutions
{
public:
	p98() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	bool isValidBST(TreeNode* root);
	void test();
};

class p99 : public Solutions
{
public:
	p99() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void recoverTree(TreeNode* root);
	void test();
};

class p100 : public Solutions
{
public:
	p100() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	bool isSameTree(TreeNode* p, TreeNode* q);
	void test();
};

class p144 : public Solutions
{
public:
	p144() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<int> preorderTraversal(TreeNode* root);
	void test();
};

class p145 : public Solutions
{
public:
	p145() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<int> postorderTraversal(TreeNode* root);
	void test();
};

class p206 : public Solutions
{
public:
	p206() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	ListNode* reverseList(ListNode* head);
	void test();
};
