#include"Solutions.h"

// one dimension array solutions
int p135::candy(vector<int>& ratings) {
	int n = ratings.size();
	vector<int> candies(n, 1);
	for (int i = 0; i < n - 1; i++) {
		if (ratings[i] < ratings[i + 1])
			candies[i + 1] = candies[i] + 1;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (ratings[i] > ratings[i + 1]) {
			candies[i] = max(candies[i], candies[i + 1] + 1);
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += candies[i];
	}
	return sum;
}