#include"Solutions.h"
// sliding window and then compare the new element gap
// an abstraction for big data 
 bool p220::containsNearbyAlmostDuplicate_wrong(vector<int>& nums, int k, int t) {
	 int n = nums.size();
	 for (int i = 0; i <= n - k; i++) {
		 // index [i, i + k - 1]
		 int gap = 0;
		 if (i == 0) {// sort the first k elment and traverse
			 sort(nums.begin(), nums.begin() + k); // last element not inclusive
			 for (int l = 0; l < k - 1; l++) {
				 if (nums[l + 1] = nums[l] <= t)
					 return true;
			 }
		 }
		 else {
			 for (int l = i; l <= i + k - 2; l++) {
				 if (abs(nums[l] - nums[i + k - 1]) <= t)
					 return true;
			 }
		 }
		 return false;
	}
}

 // Method 1: brutal force
 // Method 2: Maitain BST Java:TreeSet O(NlogK) k length of a binary tree, space O(k)
 //https://www.youtube.com/watch?v=yc4hCFzNNQc
 // Method 3: bucket sort
	 //brutal force O(n^2)
 bool p220::containsNearbyAlmostDuplicate_Bru(vector<int>& nums, int k, int t) {
	 int size = nums.size();
	 if (k <= 0 || t < 0 || size == 0) return false;
	 vector<long long> lnums{ nums.begin(), nums.end() };
	 // large loop
	 for (int i = 0; i < size; i++) {
		 for (int j = i + 1; j < size && j - i <= k; j++) {
			 if (abs(lnums[j] - lnums[i]) <= t)
				 return true;
		 }
	 }
	 return false;
 }

 // You can use lower_bound and then go one back i.e. ==> effective the largest with less than ...
 bool p220::containsNearbyAlmostDuplicate_BFS(vector<int>& nums, int k, int t) {
	 //BFS from multi-set
		int size = nums.size();
		if (k <= 0 || t < 0 || size == 0) return false;
		vector<long long> lnums{ nums.begin(), nums.end() };
		multiset<long long> ms; // this is essentially a BST
		for (int i = 0; i < size; i++) {
			//auto index_l = ms.lower_bound(lnums[i]);
			// has to do this
			auto index_l = ms.lower_bound(lnums[i] - t);
			// auto index_u = ms.upper_bound(lnums[i]); ==> java has ceil and floor
			if ((index_l != ms.end() && abs(*index_l - lnums[i]) <= t))
				//(index_u != ms.end() && abs(*index_u - lnums[i]) <= t))
				return true;
			ms.insert(lnums[i]);
			// eliminate the element not in the window
			// make sure the size of the TreeSet is K+ 1
			if (i >= k) ms.erase(lnums[i - k]);
			// intuitive 
			// for i element, effecitve window is [i - k, i], so when consider i, consider [i - k,....i -1] & [i]
			// after inserting, just eliminate [i - k]
		}
		return false;
	}

 // bucket sort

 bool p220::containsNearbyAlmostDuplicate_BucketSort(vector<int>& nums, int k, int t) {
	 int size = nums.size();
	 long tt = t;
	 if (k <= 0 || t < 0 || size == 0) return false;
	 // range: min, max
	 const auto range = minmax_element(nums.begin(), nums.end());
	 // put bucket: index = (val - min) /(t+ 1) : t+ 1 to avoid zero t
	 long long index;
	 unordered_map<long long, long> bucket; // index--> value
	 for (int i = 0; i < size; i++) {
		 // put int different bucket
		 index = ((long long)nums[i] - *range.first) / (tt + 1);
		 //bucket[index] = nums[i];
		 // NOT immediately add

	 // check left bucket : this is each bucket has just one element
		 if (bucket.count(index - 1)) {
			 if (abs(bucket[index - 1] - nums[i]) <= t)
				 return true;
		 }
		 // check right bucket
		 if (bucket.count(index + 1)) {
			 if (abs(bucket[index + 1] - nums[i]) <= t)
				 return true;
		 }
		 // check inside the bucket
		 if (bucket.count(index)) {
			 // if (abs(bucket[index] - nums[i]) <= t)
			 return true;
		 }
		 // finally add
		 bucket[index] = nums[i];
		 // remove the space so that complexity
		 if (i >= k)
			 bucket.erase(((long long)nums[i - k] - *range.first) / (tt + 1));
		 //index = ((long long)nums[i] - *range.first) / (tt + 1);
	 }
	 return false;
 }

 void p220::test() {

 }