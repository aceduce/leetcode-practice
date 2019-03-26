#include"Solutions.h"
// need to loop all the elements before this one!!!
// O(n^2), space: O(n)
int p646::findLongestChain(vector<vector<int>>& pairs) {
	// important we sort the pairs first
	// use lambda function
	sort(pairs.begin(), pairs.end(), [](vector<int> & a, vector<int> & b){
		return a[0] < b[0];
		});
	// sort by the first element
	int length = pairs.size();
	vector<int> DP(length + 1, 1);
	// this DP nees two loops!
	for (int i = 1; i < length; i++) {
		for(int j = 0; j < i; j++)
			if (pairs[i][0] > pairs[j][1]) {
				DP[i] = max(DP[j] + 1, DP[i]);
			}
	}
	return *max_element(DP.begin(), DP.end());
}

// the greedy method
// use sorting the second coordinates
// We can greedily add to our chain. Choosing the next addition to be the one 
// with the lowest second coordinate is at least better than a choice with a larger second coordinate.
int p646::findLongestChain_greedy(vector<vector<int>>& pairs) {
	// sorting is the key here
	sort(pairs.begin(), pairs.end(), [](vector<int> & a, vector<int> & b) {
		return a[1] < b[1];
	});
	int cur = INT_MIN;
	int ans = 0;
	// just loop over the array once!
	for (auto const & p : pairs) {
		if (cur < p[0]) {
			cur = p[1];
			ans++;
		}
	}
	return ans;
}