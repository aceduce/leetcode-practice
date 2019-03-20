#include"Solutions.h"
// build one's own heap

// Quick-Select very important!

	/**
	 *   3,2,1,5,6,4  k = 3
	 *   0 1 2 3 4 5

	 pivot : 3  [3, 2, 1, 5, 6, 4]
	 left = 0, right = 5
	 [3, 4, 6, 5, 1, 2]   3

	 pivot : 5  [5, 4, 6, 3, 1, 2]
	 left = 0, right =  2
	 [5, 6, 4, 3, 1, 2]   1

	 pivot : 4  [6, 5, 4, 3, 1, 2]
	 left = 2, right =  2
	 [6, 5, 4, 3, 1, 2]   2
	 */

// very tricky indexing piece
// quick-sort has one more step of {left, pos - 1}; {pos + 1, right}

int p215::partition(vector<int> & nums, int left, int right) {
	int pivot = nums[left];
	int l = left + 1, r = right;
	while (l <= r) {
		if(nums[l] < pivot && nums[r] > pivot) {
			swap(nums, l++, r--);
		}
		// values stay the same...
		if (nums[l] >= pivot) l++;
		if (nums[r] <= pivot) r--;
	}
	// the pivot value ranks the r + 1 th largest (considering zero index@begining)
	swap(nums, r, left);
	return r;
}

void p215::swap(vector<int> & nums, int i, int j) {
	int tmp = nums[i];
	nums[i] = nums[j];
	nums[j] = tmp;
}


int p215::findKthLargest(vector<int>& nums, int k) {
	int left = 0, right = nums.size() - 1;
	while (1) {
		int pos = partition(nums, left, right);
		if (pos + 1 == k) {
			return nums[pos];
		} 
		else if (pos + 1 > k) { // the piivot value is too small
			right = pos - 1;
		}
		else if (pos + 1 < k) {
			left = pos + 1;
		}
	}
	return 0;
}

// prioirty queue is very intuitive
// move into the queue (min) and pop
// maintain the queue size to be k
// final pop

int p215::findKthLargest_pp(vector<int>& nums, int k) {
	// default is min-heap
	priority_queue <int, vector<int>, greater<int> > pq;
	// insert one by one and keep the pqueue size in check
	for (auto const & num : nums) {
		pq.push(num);
		if (pq.size() > k) { // constrain the size of the priority queue to be k
			pq.pop();
		}
	}
	return pq.top();
}
