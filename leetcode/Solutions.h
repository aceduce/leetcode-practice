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
#include <sstream>
//#include "Helper.h"
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
	bool isMatch(string s, string p);
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

class p52 : public Solutions
{
public:
	p52() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int totalNQueens(int n);
	bool isValid(vector<int> &q, int value, int pos);
	void subNQ(vector<int> &q, int &ans, int n, int pos);
	void test();
};


class p53 : public Solutions
{
public:
	p53() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int subMaxSub(int left, int right, vector<int>& num);
	int maxSubArray(vector<int>& nums);
	int maxSubArray_DP(vector<int>& nums);
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

class p56 : public Solutions
{
public:
	p56() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<Interval> merge(vector<Interval>& intervals);
	vector<Interval> merge_my(vector<Interval>& intervals);
	void test();
};

class p57 : public Solutions
{
public:
	p57() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval);
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


class p60 : public Solutions
{
public:
	p60() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void subgetPerm(int n, int k, string & sub, string & ans, int & count);
	string getPermutation_my(int n, int k);
	string getPermutation(int n, int k);
	void test();
};

class p61 : public Solutions
{
public:
	p61() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	void test();
	ListNode * rotateRight(ListNode * head, int k);
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

class p64 : public Solutions
{
public:
	p64() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int minPathSum(vector<vector<int>>& grid);
	void test();
};

class p65 : public Solutions
{
public:
	p65() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	
	bool isNumber(string s);

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

class p68 : public Solutions
{
public:
	p68() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	
	void test();
	vector<string> fullJustify(vector<string>& words, int maxWidth);
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

class p71 : public Solutions
{
public:
	p71() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	string simplifyPath(string path);
	void test();
};

class p72 : public Solutions
{
public:
	p72() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	int minDistance(string word1, string word2);
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

class p74 : public Solutions
{
public:
	p74() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	bool searchMatrix(vector<vector<int>>& matrix, int target);
};

class p75 : public Solutions
{
public:
	p75() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void sortColors(vector<int>& nums);
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

class p101 : public Solutions
{
public:
	p101() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	
	bool isMirror(TreeNode * l, TreeNode * r);

	bool isSymmetric_recur(TreeNode * root);

	bool isSymmetric(TreeNode * root);

	void test();
};

class p102 : public Solutions
{
public:
	p102() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	vector<vector<int>> levelOrder(TreeNode* root);
	void test();
};

class p103 : public Solutions
{
public:
	p103() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	
	vector<vector<int>> zigzagLevelOrder_DFS(TreeNode * root);

	void test();
	vector<vector<int>> zigzagLevelOrder(TreeNode * root);
};

class p104 : public Solutions
{
public:
	p104() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int maxDepth(TreeNode * root);
	void test();

};

class p105 : public Solutions
{
public:
	p105() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	//TreeNode * subbuilder();
	TreeNode * subbuilder(vector<int>& preorder, vector<int>& inorder, int in_start, int in_end, int pre_start);
	TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder);
	void test();

};

class p106 : public Solutions
{
public:
	p106() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	TreeNode * subbuilder(vector<int>& inorder, vector<int>& postorder, int in_start, int in_end, int post_st);
	TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder);
	void test();

};

class p107 : public Solutions
{
public:
	p107() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<vector<int>> levelOrderBottom(TreeNode * root);
	void test();

};

class p108: public Solutions
{
public:
	p108() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	TreeNode * helper(vector<int>& num, int left, int right);
	TreeNode * sortedArrayToBST(vector<int>& nums);
	void test();

};

class p109 : public Solutions
{
public:
	p109() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	ListNode * findMiddle(ListNode * h);
	TreeNode * sortedListToBST(ListNode * head);
	void test();

};

class p110 : public Solutions
{
public:
	p110() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int helper(TreeNode * r);
	bool isBalanced(TreeNode * root);
	void test();

};

class p111 : public Solutions
{
public:
	p111() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	int minDepth(TreeNode * root);

	void test();

};

class p112 : public Solutions
{
public:
	p112() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	//void DFS(TreeNode * r, const int sum, int accum_sum);
	//void DFS(TreeNode * r, const int & sum, int accum_sum, bool ans);
	void DFS(TreeNode * r, const int & sum, int accum_sum, bool & ans);
	bool hasPathSum(TreeNode * root, int sum);
	bool hasPathSum_DFS(TreeNode * root, int sum);
	void test();

};

class p113 : public Solutions
{
public:
	p113() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	//void DFS(TreeNode * r, int accum_sum, const int sum, vector<vector<int>>& ans, vector<int>& tmp);
	void DFS(TreeNode * r, int accum_sum, const int sum, vector<vector<int>>& ans, vector<int> tmp);
	vector<vector<int>> pathSum_my(TreeNode * root, int sum);
	void helper(TreeNode * r, int sum, vector<int>& tmp, vector<vector<int>>& ans);
	vector<vector<int>> pathSum(TreeNode * root, int sum);
	void test();

};

class p114 : public Solutions
{
public:
	p114() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void flatten(TreeNode * root);
	void test();
};

class p115 : public Solutions
{
public:
	p115() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int numDistinct(string s, string t);
	void test();
};

class p116 : public Solutions
{
public:
	p116() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	Node * connect(Node * root);
	Node * connect_queue(Node * root);
	Node * connect_recur(Node * root);
	//void connect_example(TreeLinkNode * root);
	void connect_example(Node * root);
	void test();
};

class p117 : public Solutions
{
public:
	p117() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	Node * connect(Node * root);
	Node * connect_wrong(Node * root);
	void test();
};

class p118 : public Solutions
{
public:
	p118() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<vector<int>> generate_simple(int numRows);
	vector<vector<int>> generate_clever(int numRows);
	void test();
	vector<vector<int>> generate(int numRows);
};
class p119 : public Solutions
{
public:
	p119() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<int> getRow(int rowIndex);
	void test();
};

class p120 : public Solutions
{
public:
	p120() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int minimumTotal(vector<vector<int>>& triangle);
	void test();
};

class p121 : public Solutions
{
public:
	p121() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int maxProfit(vector<int>& prices);
	int maxProfit_slow(vector<int>& prices);
	void test();
};

class p122 : public Solutions
{
public:
	p122() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	int maxProfit(vector<int>& prices);
};

class p123 : public Solutions
{
public:
	p123() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	//int maxProfit(vector<int>& prices);
	int maxProfit_twoloops(vector<int>& prices);
	void test();
};

class p124 : public Solutions
{
public:
	p124() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
};

class p125 : public Solutions
{
public:
	p125() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
};

class p126 : public Solutions
{
public:
	p126() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
};

class p127 : public Solutions
{
public:
	p127() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
};

class p128 : public Solutions
{
public:
	p128() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
};

class p129 : public Solutions
{
public:
	p129() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
};

class p130 : public Solutions
{
public:
	p130() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
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


class p188 : public Solutions
{
public:
	p188() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	int maxProfit(int k, vector<int>& prices);

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

class p212 : public Solutions
{
public:
	p212() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
	void test();
};

class p309 : public Solutions
{
public:
	p309() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int maxProfit(vector<int>& prices);
	void test();
};

class p367 : public Solutions
{
public:
	p367() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	
	void test();
	bool isPerfectSquare(int num);
};

class p437 : public Solutions
{
public:
	p437() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	//int helper(TreeNode * r, int sum);



	int helper_wrong(TreeNode * r, const int sum, int ps, int & ans);

	int true_helper(TreeNode * r, int sum);

	int pathSum(TreeNode * root, int sum);

	void test();
};

class p633 : public Solutions
{
public:
	p633() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	void test();
	bool judgeSquareSum(int c);
};


class p637 : public Solutions
{
public:
	p637() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	//void DFS(TreeNode * r, vector<double>& ans, int level);

	//void DFS(TreeNode * r, vector<double>& ans, int level, vector<vector<double>> tmp);

	void DFS(TreeNode * r, vector<double>& ans, int level, vector<vector<double>>& tmp);

	void DFS_save(TreeNode * r, vector<double>& ans, int level, vector<int>& size);

	vector<double> averageOfLevels(TreeNode * root);

	void test();
	
};


class p714 : public Solutions
{
public:
	p714() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	
	int maxProfit(vector<int>& prices, int fee);

	void test();
};

class p889 : public Solutions
{
public:
	p889() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	TreeNode * constructFromPrePost(vector<int>& pre, vector<int>& post);
	void test();
};