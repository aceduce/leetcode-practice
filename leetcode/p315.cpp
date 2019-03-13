#include"Solutions.h"

// Solution inspired by 493. Reverse Pairs

vector<int> p315::countSmaller(vector<int>& nums) {
	return countSmaller_BIT(nums);
}


// Use BST
	// Another method use prefix sum BIT
// https://www.youtube.com/watch?v=2SVLYsq5W8M


	// TLE
vector<int> p315::countSmaller_BST(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) return {};
	vector<int> ans(n, 0);
	multiset<int> bst; // BST
	for (int i = n - 1; i >= 0; i--) {
		auto find = lower_bound(bst.begin(), bst.end(), nums[i]);
		if (find != bst.end()) { // found one
			int tmp = distance(bst.begin(), find); // find the distance
			ans[i] = tmp;
		}
		else { // no element >= value, every element <
			ans[i] = bst.size();
		}
		bst.insert(nums[i]);
	}
	return ans;
}

// a prefix fashion BIT:
void p315::update(vector<int> &BIT, int index, int val) {
	while (index < BIT.size()) { // traditionaly way, going backward
		BIT[index] += val;
		index += index & (-index);
	}
}

int p315::query(vector<int> & BIT, int index) {
	int sum = 0;
	while (index > 0) {
		sum += BIT[index];
		index -= index & (-index);
	}
	return sum;
}

// An even faster one:
// Author: Huahua
// Runnning time: 32 ms
// Time complexity: O(nlogn)
// Space complexity: O(k), k is the number unique elements
class FenwickTree {
public:
	FenwickTree(int n) : sums_(n + 1, 0) {}

	void update(int i, int delta) {
		while (i < sums_.size()) {
			sums_[i] += delta;
			i += lowbit(i);
		}
	}

	int query(int i) const {
		int sum = 0;
		while (i > 0) {
			sum += sums_[i];
			i -= lowbit(i);
		}
		return sum;
	}
private:
	static inline int lowbit(int x) { return x & (-x); }
	vector<int> sums_;
};

class p315::Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		// Sort the unique numbers
		set<int> sorted(nums.begin(), nums.end());
		// Map the number to its rank
		unordered_map<int, int> ranks;
		int rank = 0;
		for (const int num : sorted)
			ranks[num] = ++rank;

		vector<int> ans;
		FenwickTree tree(ranks.size());
		// Scan the numbers in reversed order
		for (int i = nums.size() - 1; i >= 0; --i) {
			// Chechk how many numbers are smaller than the current number.
			ans.push_back(tree.query(ranks[nums[i]] - 1));
			// Increse the count of the rank of current number.
			tree.update(ranks[nums[i]], 1);
		}

		std::reverse(ans.begin(), ans.end());
		return ans;
	}
};

vector<int> p315::countSmaller_BIT(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) return {};
	vector<int> nums_copy{ nums.begin(), nums.end() };
	sort(nums_copy.begin(), nums_copy.end());
	vector<int> ans(n, 0);
	vector<int> BITS(n, 0);
	for (int i = n - 1; i >= 0; i--) {
		ans[i] += query(BITS,
			lower_bound(nums_copy.begin(), nums_copy.end(), nums[i]) - nums_copy.begin());  // ignoare +1 since this postiion needs to back by 1

		update(BITS,
			lower_bound(nums_copy.begin(), nums_copy.end(), nums[i]) - nums_copy.begin() + 1, // need to have + 1 in bit tree
			1);
	}
	return ans;
}

// Self-defined BST
class p315::BSTNode {
public:
	int val;
	int count;
	BSTNode * left;
	BSTNode * right;
	int left_count; // how many elements are less than current value
	BSTNode(int val) :val(val), count(1), left_count(0), left(NULL), right(NULL) {}
	~BSTNode() {
		delete left, right;
	}
	int less_or_equal() const { return left_count + count; }
};

class p315::Solution_BST {
private:
	// Returns the number of elements smaller than (input) int val from root->val
	int insert(BSTNode* root, int val) {
		//if (root == NULL) root = new BSTNode(val);
		if (val == root->val) {
			root->count++;
			return root->left_count;
		}
		else if (val > root->val) {
			if (root->right == NULL) {
				root->right = new BSTNode(val);
				return root->less_or_equal();
			}
			else
				return root->less_or_equal() + insert(root->right, val);
		}
		else { // val < root->val
			root->left_count++; // inset into left
			if (root->left == NULL) {
				root->left = new BSTNode(val);
				return 0;
			}
			return insert(root->left, val);
		}

	}
public:
	vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return {};
		vector<int> ans(n, 0);
		unique_ptr<BSTNode> root(new BSTNode(nums[n - 1]));
		ans[n - 1] = 0;
		for (int i = n - 2; i >= 0; i--) {
			ans[i] = insert(root.get(), nums[i]);
		}
		return ans;
	}
};
