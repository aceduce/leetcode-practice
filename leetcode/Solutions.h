#pragma once
# include<vector>
# include<map>
# include<iostream>
# include<queue>
# include<list>
# include <array>
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
#include <numeric>
#include <cstddef>
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
	int helper(TreeNode * root, int & ans);
	int maxPathSum(TreeNode * root);
	void test();
};

class p125 : public Solutions
{
public:
	p125() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	bool isPalindrome(string s);
};

class p126 : public Solutions
{
public:
	p126() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	//void buildback(const string & beginWord, const string & EndWord, const unordered_map<string, vector<string>>& parents, const string parent, vector<string>& curr, vector<vector<string>>& ans);
	void build_forward(const string & begin, const string & end, vector<string>& tmp, const string cur, const unordered_map<string, vector<string>>& childtree, vector<vector<string>>& ans);
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);
	void buildback_BFSDFS(const string & beginWord, const string & EndWord, const unordered_map<string, vector<string>>& parents, const string parent, vector<string>& curr, vector<vector<string>>& ans);
	vector<vector<string>> findLadders_BFSDFS(string beginWord, string endWord, vector<string>& wordList);
	vector<vector<string>> findLadders_BFSDFS_sets(string beginWord, string endWord, vector<string>& wordList);
	void test();
};

class p127 : public Solutions
{
public:
	p127() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int ladderLength(string beginWord, string endWord, vector<string>& wordList);
	int ladderLength_hashset_BFS(string beginWord, string endWord, vector<string>& wordList);
	int ladderLength_queue_BFS(string beginWord, string endWord, vector<string>& wordList);
	int ladderLength_worse(string beginWord, string endWord, vector<string>& wordList);
	void test();
};

class p128 : public Solutions
{
public:
	p128() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	
	int longestConsecutive_concise(vector<int>& nums);

	void test();
	int longestConsecutive_my(vector<int>& nums); // much more verbose, and not able to use iterator!
	int longestConsecutive(vector<int>& nums);
};

class p129 : public Solutions
{
public:
	p129() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void DFS(TreeNode * r, int & tmp, int & ans);
	int sumNumbers(TreeNode * root);
	void test();
};



class p130 : public Solutions
{
public:
	p130() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void solve(vector<vector<char>>& board);
	void test();
};


class p131 : public Solutions
{
public:
	p131() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	//bool isPen(string s);
	bool isPen(string & s);
	void helper(string s, int index, vector<vector<string>>& ans, vector<string>& tmp);
	void helper_DP(vector<vector<bool>>& DP, const string s, int index, vector<vector<string>>& ans, vector<string>& tmp);
	vector<vector<string>> partition(string s);
	vector<vector<string>> partition_backtrackings(string s);
	void test();
};

class p132 : public Solutions
{
public:
	p132() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	bool isPan(string s, int st, int end);
	int minCut_lessopt(string s);
	void test();
	int minCut(string s);
};

class p133 : public Solutions
{
//using Node = NodeP133;
public:
	p133() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	//Node * cloneGraph(Node * node);
	NodeP133 * cloneGraph(NodeP133 * node);
	//Node * cloneGraph(Node * node);
};

class p134 : public Solutions
{
public:
	p134() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
	int canCompleteCircuit_vect(vector<int>& gas, vector<int>& cost);
	void test();
};

class p135 : public Solutions
{
public:
	p135() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	int candy(vector<int>& ratings);
};

class p136 : public Solutions
{
public:
	p136() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	int singleNumber(vector<int>& nums);
};

class p137 : public Solutions
{
public:
	p137() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int singleNumber(vector<int>& nums);
	int singleNumber_mode(vector<int>& nums);
	void test();

};

class p138 : public Solutions
{
public:
	p138() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	NodeP138 * copyRandomList_my(NodeP138 * head);
	NodeP138 * copyRandomList_Hashmap(NodeP138 * head);
	void test();
	//Node * copyRandomList(Node * head);
	NodeP138 * copyRandomList(NodeP138 * head);
};

class p139 : public Solutions
{
public:
	p139() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	bool wordBreak(string s, vector<string>& wordDict);
};

class p140 : public Solutions
{
public:
	p140() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	//void subwordBreak(string & s, vector<string>& wordDict, int index, vector<string>& ans, string & tmp);
	void subwordBreak(string & s, unordered_set<string>& set, int index, vector<string>& ans, string & tmp);
	void subwordBreak_w_Opt(string & s, unordered_set<string>& set, int index, vector<string>& ans, string & tmp, unordered_map<string, string> used);
	vector<string> subwordBreak_w_Opt(string & s, unordered_set<string>& set, int index, vector<string>& ans, string & tmp, unordered_map<string, vector<string>>& used);
	//vector<string> subwordBreak_w_Opt(string s, unordered_set<string>& set, vector<string>& ans, unordered_map<string, vector<string>>& used);
	vector<string> subwordBreak_w_Opt(string s, unordered_set<string>& set, unordered_map<string, vector<string>>& used);
	vector<string> wordBreak(string s, vector<string>& wordDict);
	void test();
};

class p141 : public Solutions
{
public:
	p141() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	bool hasCycle(ListNode * head);
	bool hasCycle_hashset(ListNode * head);
	void test();
};

class p142 : public Solutions
{
public:
	p142() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	ListNode * detectCycle(ListNode * head);
	void test();
};

class p143 : public Solutions
{
public:
	p143() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	ListNode * findMid(ListNode * h);
	ListNode * reverse(ListNode * h);
	void reorderList(ListNode * head);
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

class p146 : public Solutions
{
public:
	p146() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class LRUCache;
	void test();
};

class p147 : public Solutions
{
public:
	p147() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	ListNode * insertionSortList(ListNode * head);
};

class p148 : public Solutions
{
public:
	p148() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	pair<ListNode*, ListNode*> merge_2(ListNode * l1, ListNode * l2);
	ListNode * sortList(ListNode * head);
	ListNode * split(ListNode * head, int n);
	//ListNode * merge(ListNode * h);
	ListNode * merge(ListNode * h1, ListNode * h2);
	ListNode * sortList_merge(ListNode * head);
	void test();
};

class p149 : public Solutions
{
public:
	p149() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int gcd(int m, int n);
	pair<int, int> Slope(const Point & p1, const Point & p2);
	int maxPoints(vector<Point>& points);
	void test();
};

class p150 : public Solutions
{
public:
	p150() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int evalRPN(vector<string>& tokens);
	void test();
};


class p151 : public Solutions
{
public:
	p151() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	string reverseWords_inplace(string s);
	string reverseWords(string s);
	void test();
};

class p152 : public Solutions
{
public:
	p152() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	int maxProduct(vector<int>& nums);
};

class p153 : public Solutions
{
public:
	p153() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	int findMin(vector<int>& nums);
};


class p154 : public Solutions
{
public:
	p154() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int findMin(vector<int>& nums);
	void test();
};


class p155 : public Solutions
{
public:
	class MinStack;
	p155() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
};

class p160 : public Solutions
{
public:
	p160() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	ListNode * getIntersectionNode(ListNode * headA, ListNode * headB);
	void test();
};


class p162 : public Solutions
{
public:
	p162() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int subfind(vector<int>& nums);
	int subfind(vector<int>& nums, int l, int r);
	int findPeakElement(vector<int>& nums);
	int findPeakElement_linear_scan(vector<int>& nums);
	//ListNode * getIntersectionNode(ListNode * headA, ListNode * headB);
	void test();
};

class p164 : public Solutions
{
public:
	p164() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	//ListNode * getIntersectionNode(ListNode * headA, ListNode * headB);
	int maximumGap(vector<int>& nums);
	int maximumGap_bucket(vector<int>& nums);
	void test();
};

class p165 : public Solutions
{
public:
	p165() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	
	int compareVersion(string version1, string version2);

	void test();
};

class p166 : public Solutions
{
public:
	p166() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	string fractionToDecimal(int numerator, int denominator);
	string fractionToDecimal(long numerator, long denominator);
	string fractionToDecimal(long long numerator, long long denominator);
	void test();
};

class p167 : public Solutions
{
public:
	p167() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	vector<int> twoSum(vector<int>& numbers, int target);

	void test();
};

class p168 : public Solutions
{
public:
	p168() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	string convertToTitle(int n);

	void test();
};

class p169 : public Solutions
{
public:
	p169() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	void test();
	int majorityElement(vector<int>& nums);
};

class p171 : public Solutions
{
public:
	p171() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	int titleToNumber(string s);

	void test();

};

class p172 : public Solutions
{
public:
	p172() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int trailingZeroes(int n);
	void test();
};

class p173 : public Solutions
{
public:
	p173() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class BSTIterator;
};

class p174 : public Solutions
{
public:
	p174() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int calculateMinimumHP(vector<vector<int>>& dungeon);
	void test();
};

class p179 : public Solutions
{
public:
	p179() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	string largestNumber(vector<int>& nums);
	string helper(int input);
	struct comp;
	void test();
};

class p187 : public Solutions
{
public:
	p187() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int calc(char a);
	vector<string> findRepeatedDnaSequences(string s);
	vector<string> findRepeatedDnaSequences_bits_manipul(string s);
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


class p189 : public Solutions
{
public:
	p189() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void rotate(vector<int>& nums, int k);
	void rotate_1(vector<int>& nums, int k);
	void test();
};

class p190 : public Solutions
{
public:
	p190() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	
	uint32_t reverseBits(uint32_t n);
	uint32_t reverseBits_naive(uint32_t n);
	void test();
};

class p191 : public Solutions
{
public:
	p191() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int hammingWeight(uint32_t n);
	void test();
};

class p193 : public Solutions
{
public:
	p193() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
};

class p198 : public Solutions
{
public:
	p198() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int rob_TLE(vector<int>& nums);
	void test();
	int rob(vector<int>& nums);
};

class p199 : public Solutions
{
public:
	p199() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	vector<int> rightSideView(TreeNode * root);
};

class p200 : public Solutions
{
public:
	p200() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void DFS(vector<vector<char>>& grid, int x, int y);
	int numIslands(vector<vector<char>>& grid);
	void test();
};

class p201 : public Solutions
{
public:
	p201() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int rangeBitwiseAnd_TLE(int m, int n);
	int rangeBitwiseAnd(int m, int n);
	void test();

};

class p202 : public Solutions
{
public:
	p202() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	bool isHappy(int n);
};

class p203 : public Solutions
{
public:
	p203() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	ListNode * removeElements(ListNode * head, int val);
};
class p204 : public Solutions
{
public:
	p204() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	int countPrimes(int n);

	void test();

};

class p205 : public Solutions
{
public:
	p205() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	bool isIsomorphic_my(string s, string t);
	bool isIsomorphic(string s, string t);
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

class p207 : public Solutions
{
public:
	p207() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);
	void test();
	class Solution_top_search;
};

class p208 : public Solutions
{
public:
	p208() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Trie;
	void test();
};


class p209 : public Solutions
{
public:
	class Solution_BST;
	p209() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int minSubArrayLen(int s, vector<int>& nums);
	void test();
};

class p210 : public Solutions
{
public:
	p210() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites);
};

class p211 : public Solutions
{
public:
	class WordDictionary;
	p211() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
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

class p213 : public Solutions
{
public:
	p213() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	int rob(vector<int>& nums);

	void test();
};

class p214 : public Solutions
{
public:
	p214() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	string shortestPalindrome(string s);
	string shortestPalindrome_reverse(string s);
	string shortestPalindrome_superset(string s);
};

class p215 : public Solutions
{
public:
	p215() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	int partition(vector<int>& nums, int left, int right);
	void swap(vector<int>& nums, int i, int j);
	int findKthLargest(vector<int>& nums, int k);
	int findKthLargest_pp(vector<int>& nums, int k);
};

class p216 : public Solutions
{
public:
	p216() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution_backtracking;
};

class p217 : public Solutions
{
public:
	p217() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	bool containsDuplicate(vector<int>& nums);
};

class p218 : public Solutions
{
public:
	p218() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution_Heap;
	class Solution_BST;
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings);
};

class p219: public Solutions
{
public:
	p219() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	bool containsNearbyDuplicate(vector<int>& nums, int k);
	bool containsNearbyDuplicate_slow(vector<int>& nums, int k);
};

class p220 : public Solutions
{
public:
	p220() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	bool containsNearbyAlmostDuplicate_wrong(vector<int>& nums, int k, int t);
	bool containsNearbyAlmostDuplicate_BucketSort(vector<int>& nums, int k, int t);
	void test();
	bool containsNearbyAlmostDuplicate_Bru(vector<int>& nums, int k, int t);
	bool containsNearbyAlmostDuplicate_BFS(vector<int>& nums, int k, int t);
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t);
};

class p221 : public Solutions
{
public:
	p221() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	
	int maximalSquare(vector<vector<char>>& matrix);

	int maximalSquare_DP_Gen(vector<vector<char>>& matrix);

	void test();
	
};

class p222 : public Solutions
{
public:
	p222() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();

	int countNodes_recur(TreeNode * root);

	int countNodes_iterative(TreeNode * root);

};

class p223 : public Solutions
{
public:
	p223() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution_my;
	class Solution;
};

class p225 : public Solutions
{
public:
	p225() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class MyStack;
};

class p226 : public Solutions
{
public:
	p226() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	TreeNode * invertTree(TreeNode * root);
	TreeNode * invertTree_iter(TreeNode * root);
};

class p228 : public Solutions
{
public:
	p228() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	vector<string> summaryRanges(vector<int>& nums);
};

class p230 : public Solutions
{
public:
	p230() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution;
};

class p233 : public Solutions
{
public:
	p233() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();

	int countDigitOne(int n);

};
class p234 : public Solutions
{
public:
	p234() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	void test();
	void reverseLink(ListNode * h);
	//void reverse(ListNode * h);
	void reverse(ListNode *& h);
	bool isPalindrome(ListNode * head);
};


class p235 : public Solutions
{
public:
	p235() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution;
};

class p236 : public Solutions
{
public:
	p236() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution;
};

class p237 : public Solutions
{
public:
	p237() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	void test();
	void deleteNode(ListNode * node);
};

class p239 : public Solutions
{
public:
	class MonotonicQueue;
	p239() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	vector<int> maxSlidingWindow(vector<int>& nums, int k);
	vector<int> maxSlidingWindow_monotonic_queue(vector<int>& nums, int k);
	vector<int> maxSlidingWindow_brute_force(vector<int>& nums, int k);
	vector<int> maxSlidingWindow_multisetBFS(vector<int>& nums, int k);
	void test();
	
};

class p257 : public Solutions
{
public:
	p257() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	void test();
	void sub(TreeNode * r, string & tmp, vector<string>& ans);
	vector<string> binaryTreePaths(TreeNode * root);
};

class p258 : public Solutions
{
public:
	p258() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	int addDigits(int num);

	void test();
	
};

class p263 : public Solutions
{
public:
	p263() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	void test();
	
	bool isUgly(int num);

};

class p264 : public Solutions
{
public:
	p264() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int nthUglyNumber(int n);
	void test();
};

class p268 : public Solutions
{
public:
	p268() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int missingNumber(vector<int>& nums);
	//int nthUglyNumber(int n);
	void test();
};

class p279 : public Solutions
{
public:
	p279() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int numSquares(int n);
	void test();
};

class p282 : public Solutions
{
public:
	p282() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	void test();
};

class p283 : public Solutions
{
public:
	p283() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	void test();
};

class p290: public Solutions
{
public:
	p290() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	bool wordPattern(string pattern, string str);
};

class p297 : public Solutions
{
public:
	p297() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Codec_Binary;
	class Codec_String;
};



class p300 : public Solutions
{
public:
	p300() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution_iterative;
	class Solution_recursive;
};

class p301 : public Solutions
{
public:
	p301() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution;
};


class p307 : public Solutions
{
public:
	class NumArray;
	class FenwickTree;
	class SegmentTree;
	p307() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
};

class p315: public Solutions
{
public:
	p315() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	class BSTNode;
	class Solution_BST;
	void test();
	vector<int> countSmaller(vector<int>& nums);
	vector<int> countSmaller_BST(vector<int>& nums);
	void update(vector<int>& BIT, int index, int val);
	int query(vector<int>& BIT, int index);
	vector<int> countSmaller_BIT(vector<int>& nums);
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

class p310 : public Solutions
{
public:
	p310() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges);
	vector<int> findMinHeightTrees_my_peel(int n, vector<pair<int, int>>& edges);
	vector<int> findMinHeightTrees_simpler_peel(int n, vector<pair<int, int>>& edges);
	//int maxProfit(vector<int>& prices);
	void test();
};


class p312 : public Solutions
{
public:
	p312() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	void test();
};

class p324 : public Solutions
{
public:
	p324() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	void test();
};


class p327 : public Solutions
{
public:
	p327() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int countRangeSum(vector<int>& nums, int lower, int upper);
	int countRangeSum_BST(vector<int>& nums, int lower, int upper);
	int MergeAndCount(vector<long>& sums, int start, int end, int lower, int upper);
	void test();
};

class p329 : public Solutions
{
public:
	p329() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int DFS_w_mem(const vector<vector<int>>& matrix, int x, int y);
	int longestIncreasingPath(vector<vector<int>>& matrix);
	int longestIncreasingPath_DFS_bottom(vector<vector<int>>& matrix);
	//int maxProfit(vector<int>& prices);
	void test();
private:
	vector<vector<int>> DP;
};


class p334 : public Solutions
{
public:
	p334() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution;
};

class p337 : public Solutions
{
public:
	p337() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	int rob(TreeNode * root);
};

class p338 : public Solutions
{
public:
	p338() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	
	vector<int> countBits(int num);

	vector<int> countBits_naive(int num);

};

class p344 : public Solutions
{
public:
	p344() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	void reverseString(vector<char>& s);
};

class p345 : public Solutions
{
public:
	p345() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution;
	string reverseVowels(string s);
};

class p354 : public Solutions
{
public:
	p354() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution_wBST;
	class Solution_BF_wDP;
};

class p363 : public Solutions
{
public:
	p363() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution_BF;
	class Solution_Opt;
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

class p404 : public Solutions
{
public:
	p404() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	void test();
	class Solution;
};

class p414 : public Solutions
{
public:
	p414() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	void test();
	int thirdMax(vector<int>& nums);
};

class p416 : public Solutions
{
public:
	p416() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	void test();
	bool canPartition(vector<int>& nums);
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



class p449 : public Solutions
{
public:
	p449() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Codec;
	class Codec_fast1;
	class Codec_fast2;
	void test();
};

class p450 : public Solutions
{
public:
	p450() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	void test();
};

class p463 : public Solutions
{
public:
	p463() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int DFS(vector<vector<int>>& grid, int x, int y);
	int islandPerimeter(vector<vector<int>>& grid);
	void test();
};

class p473 : public Solutions
{
public:
	p473() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	bool DFS(vector<int>& nums, int a, int b, int c, int d, const int & base, int index);
	bool makesquare(vector<int>& nums);
	void test();
};

class p488 : public Solutions
{
public:
	p488() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	void test();
};

class p491 : public Solutions
{
public:
	p491() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	
	void test();
	vector<vector<int>> findSubsequences(vector<int>& nums);
};
class p493 : public Solutions
{
public:
	struct BST_Node;
	p493() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	p493::BST_Node * insert(long long val, p493::BST_Node * root);
	int search(long long val, p493::BST_Node * root);
	int reversePairs_BST(vector<int>& nums);
	void update(vector<int>& BIT, int index, int val);
	int query(vector<int>& BIT, int index);
	int reversePairs_BIT(vector<int>& nums);
	int reversePairs(vector<int>& nums);
	int reversePairs_mutliset(vector<int>& nums);
	void merge(vector<int>& A, int start, int mid, int end);
	int mergesort_and_count(vector<int>& A, int start, int end);
	void test();
};

class p494 : public Solutions
{
public:
	p494() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	class Solution_BF;
	void test();
};

class p501 : public Solutions
{
public:
	p501() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	class Solution_BF;
	void test();
};

class p508 : public Solutions
{
public:
	p508() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	class Solution;
	void test();
};

class p513 : public Solutions
{
public:
	p513() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	class Solution;
	void test();
};

class p516 : public Solutions
{
public:
	p516() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	int longestPalindromeSubseq(string s);

	int longestPalindromeSubseq_2D_DP(string s);

	void test();
};

class p538 :public Solutions
{
public:
	p538() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution;
	class Solution_ReverseStackDFS;
	class Solution_RightFirst;

};

class p543 : public Solutions
{
public:
	p543() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	int helper(TreeNode * r, int & ans);
	int diameterOfBinaryTree(TreeNode * root);
	void test();
};

class p546 : public Solutions
{
public:
	p546() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	class Solution_Opt1;
	class Solution_Opt2;
	void test();
};

class p559 : public Solutions
{
public:
	p559() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	class Node;
	void test();
};

class p563 : public Solutions
{
public:
	p563() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution;
};


class p572 : public Solutions
{
public:
	p572() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	class Solution;
	class Solution_string;
	class Solution_my; // not very effcient
	void test();
};

class p630 : public Solutions
{
public:
	p630() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	int scheduleCourse(vector<vector<int>>& courses);
	class p630_Solution;
	void test();
	//bool judgeSquareSum(int c);
};


class p623 : public Solutions
{
public:
	p623() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution_BFS_my;
	void test();
	//bool judgeSquareSum(int c);
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


class p640 : public Solutions
{
public:
	p640() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	string solveEquation(string equation);
	void test();
};

class p646 : public Solutions
{
public:
	p646() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	int findLongestChain(vector<vector<int>>& pairs);
	int findLongestChain_greedy(vector<vector<int>>& pairs);
};

class p652 : public Solutions
{
public:
	p652() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution1;
	class Solution2;
};

class p664 : public Solutions
{
public:
	p664() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution;
};

class p665 : public Solutions
{
public:
	p665() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	bool checkPossibility(vector<int>& nums);
};

class p671 : public Solutions
{
public:
	p671() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	void test();
};

class p673 : public Solutions
{
public:
	p673() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	class Solution_iter;
	void test();
};

class p674 : public Solutions
{
public:
	p674() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	void test();
};


class p687 : public Solutions
{
public:
	p687() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	int helper(TreeNode * r, int & ans);

	int longestUnivaluePath_my(TreeNode * root);

	int univaluePath(TreeNode * r, int & ans);

	int longestUnivaluePath(TreeNode * root);

	void test();

};


class p698 : public Solutions
{
public:
	p698() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	
	void test();
	class Solution;
	class Solution_DP_memo;
};

class p690 : public Solutions
{
public:
	p690() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	void test();

};

class p695 : public Solutions
{
public:
	p695() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	int DFS(vector<vector<int>>& grid, int x, int y, int & ans);

	int DFS(vector<vector<int>>& grid, int x, int y);

	int maxAreaOfIsland(vector<vector<int>>& grid);

	void test();

};

class p701 : public Solutions
{
public:
	p701() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	void test();
	TreeNode * insertIntoBST(TreeNode * root, int val);
};

class p700 : public Solutions
{
public:
	p700() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	void test();
	TreeNode * searchBST(TreeNode * root, int val);
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

class p718 : public Solutions
{
public:
	p718() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	class Solution_DP;
	void test();
};

class p733 : public Solutions
{
public:
	p733() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}

	void dfs(vector<vector<int>>& img, int sr, int sc, const int & old, const int & n_colr);

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor);

	void test();
};


class p746 : public Solutions
{
public:
	p746() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	void test();
};
class p790 : public Solutions
{
public:
	p790() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	int numTilings(int N);
};

class p836 : public Solutions
{
public:
	p836() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	void test();
};

class p863 : public Solutions
{
public:
	p863() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	void dfs_map(TreeNode * ch, TreeNode * pa, unordered_map<TreeNode*, TreeNode*>& m);
	vector<int> distanceK(TreeNode * root, TreeNode * target, int K);
	class Solution2;
};

class p872 : public Solutions
{
public:
	p872() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	void test();
};


class p886 : public Solutions
{
public:
	p886() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
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

class p897 : public Solutions
{
public:
	p897() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	void test();
};

class p947 : public Solutions
{
public:
	p947() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	class Solution;
	void test();
};

class p958 : public Solutions
{
public:
	p958() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution_my;
};

class p968 : public Solutions
{
public:
	p968() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Solution_DFS_Greedy;
};

class p988 : public Solutions
{
public:
	p988() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	void dfs(TreeNode * r, string & ans, string & tmp);
	void dfs_w_level(TreeNode * r, string & ans, string & tmp, int lv, int & lvm);
	//void dfs_w_level(TreeNode * r, string & ans, string & tmp, int & lv, int & lvm);
	string smallestFromLeaf(TreeNode * root);
};

class p993:public Solutions
{
public:
	p993() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	class Soution;
};

class p997 : public Solutions
{
public:
	p997() {
		cout << "Question # : " << ((string)typeid(this).name()).substr(7, 3) << endl;
	}
	void test();
	int findJudge_my(int N, vector<vector<int>>& trust);
	int findJudge(int N, vector<vector<int>>& trust);
};