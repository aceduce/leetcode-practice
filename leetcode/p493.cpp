#include"Solutions.h"
// not sure why this one fail? ==> worst case
// in the distance??
int p493::reversePairs_mutliset(vector<int>& nums) {
	// TLE
	multiset<long> BST;
	int ans = 0;
	for (int i = 0; i < nums.size(); i++) {
		long search = 2 * (long)nums[i];
		auto index = BST.upper_bound(search);
		/*
		while (index != BST.end()) { // found one value
			index++; // real first element
			ans++;
		}
		*/
		if (index != BST.end())
			ans = ans + distance(index, BST.end());
		BST.insert((long)nums[i]);
	}
	return ans;
}


// BST method:TLE when in the worst case!

struct p493::BST_Node {
	long long val;
	int count; // count the subtree, # data >= node.val
	BST_Node * left;
	BST_Node * right;
	// Constructor
	BST_Node(long long val) {
		this->count = 0;
		this->left = NULL;
		this->right = NULL;
		this->val = val;
	}
};

p493::BST_Node * p493::insert(long long val, p493::BST_Node * root) {
	if (root == NULL) root = new BST_Node(val);
	else if (root->val == val) root->count++;
	else if (root->val < val) {
		root->count++;
		root->right = insert(val, root->right);
	}
	else {
		root->left =  insert(val, root->left);
	}
	return root; // always return the head
}

int p493::search(long long val, p493::BST_Node * root) {
	if (!root) return 0;
	if (root->val == val) return root->count;
	if (root->val < val) { // need to go to right
		return search(val, root->right);
	}
	else {
		return root->count + search(val, root->left);
	}
}


int p493::reversePairs_BST(vector<int> & nums) {
	int n = nums.size();
	if (n == 0 || n == 1) return 0;
	BST_Node root{ NULL };
	int count = 0;
	for (int i = 0; i < n; i++) {
		count += search((long long)2 * nums[i] + 1, &root);
		insert((long long)nums[i], &root);
	}
	return count;
}


// this version of the implementation 
	// reverse tradiational: sum of index to END
	// update from large to small
void p493::update(vector<int>& BIT, int index, int val)
{
	while (index > 0) {
		BIT[index] += val;
		index -= index & (-index);
	}
}

// like update, this is sum of index to END
int p493::query(vector<int>& BIT, int index)
{
	int sum = 0;
	while (index < BIT.size()) {
		sum += BIT[index];
		index += index & (-index);
	}
	return sum;
}
// Need to do NlogN for sorting.
int p493::reversePairs_BIT(vector<int>& nums)
{
	int n = nums.size();
	vector<int> nums_copy(nums);

	// why does it need to have sorted array? 
	// so index will follow and all numbers upward are OKay!
	sort(nums_copy.begin(), nums_copy.end());

	vector<int> BITS(n + 1, 0);
	int count = 0;
	for (int i = 0; i < n; i++) {
		// query: lower_bound gives the satisfying indexs (starting #)
		// BIT store all total sum:
		//			>= nums[i] 
					//lower_bound(nums_copy.begin(), nums_copy.end(), 2LL * nums[i] + 1) ==> query valid #
					// lower_bound(nums_copy.begin(), nums_copy.end(), nums[i]) - nums_copy.begin() + 1 ==> store num[i]
					// all sum in BITS has index < i in nums array!
		count += query(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), 2LL * nums[i] + 1) - nums_copy.begin() + 1);
		update(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), nums[i]) - nums_copy.begin() + 1, 1);
	}
	return count;
}

// Merge Sort Method: this solution is fantastic!!
	// Divide and conquer. 
void p493::merge(vector<int>& A, int start, int mid, int end)
{
	const int n1 = (mid - start + 1);
	const int n2 = (end - mid);
	vector<int> L(n1), R(n2);
	for (int i = 0; i < n1; i++)
		L[i] = A[start + i];
	for (int j = 0; j < n2; j++)
		R[j] = A[mid + 1 + j];
	int i = 0, j = 0;
	// true merge happens;
	for (int k = start; k <= end; k++) {
		if (j >= n2 || (i < n1 && L[i] <= R[j])) // deal with left array in L or normal assignment
			A[k] = L[i++];
		else
			A[k] = R[j++];
	}
}

// True solution
int p493::mergesort_and_count(vector<int>& A, int start, int end)
{
	if (start < end) {
		int mid = (start + end) / 2;
		// separtely count the number of satisfying cases
		int count = mergesort_and_count(A, start, mid) + mergesort_and_count(A, mid + 1, end);
		// count in between
		// at this point, A on the left and right are sorted well
		int j = mid + 1;
		for (int i = start; i <= mid; i++) { // all the L array index are GOOD
			while (j <= end && A[i] > A[j] * 2LL) // how many points are good for each i
				j++;
			count += j - (mid + 1); // previous ones are all OKay, so the loop is designed this way!!
		}
		// true merge sort!
		merge(A, start, mid, end);
		return count;
	}
	else
		return 0;
}

int p493::reversePairs(vector<int>& nums)
{
	return mergesort_and_count(nums, 0, nums.size() - 1);
}


void p493::test() {

}