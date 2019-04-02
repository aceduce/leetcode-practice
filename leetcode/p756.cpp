#include"Solutions.h"


class p756::Solution {
public:
	// the pyramid:
	// N at bottom
	// then N layers (N , N -1, N -2. ... 1)
	bool pyramidTransition(string bottom, vector<string>& allowed) {
		T = vector<vector<int>>(1 << 7, vector<int>(1 << 7, 0)); // bottom at most 8 letters
		for (string a : allowed)
			T[a[0] - 'A'][a[1] - 'A'] |= 1 << (a[2] - 'A'); // in total 26 characters and int has 32 bits (except first bit for sign), 26 characters--> 2^5
		// for (int b = 0; b < 7; ++b) if (((w >> b) & 1) != 0) --> decoding

		unordered_set<int> seen;
		int N = bottom.size();
		// A first dim: layer
		vector<vector<int>> A = vector<vector<int>>(N, vector<int>(N, 0));
		int t = 0;
		for (char c : bottom)
			A[N - 1][t++] = c - 'A';
		return solve(A, 0, N - 1, 0);
	}

	//A[i] - the ith row of the pyramid
   //R - integer representing the current row of the pyramid
   //N - length of current row we are calculating
   //i - index of how far in the current row we are calculating
   //Returns true iff pyramid can be built
public:
	bool solve(vector<vector<int>> &A, long R, int N, int i) {
		// only one element left and we run to it already
		if (N == 1 && i == 1) { // If successfully placed entire pyramid
			return true;
		}
		else if (i == N) { // current row reaching the end !!
			if (seen.count(R)) return false; // If we've already tried this row, give up
			seen.insert(R); // Add row to cache
			// N - 1
			return solve(A, 0, N - 1, 0); // Calculate next row
		}
		else {
			// w's jth bit is true if block #j could be
			// a parent of A[N][i] and A[N][i+1]
			int w = T[A[N][i]]
				[A[N][i + 1]];
			// for each set bit in w... ==> this is the power of encoding...
			// b: how many elments are there in N - 1 layer
			for (int b = 0; b < 7; ++b) if (((w >> b) & 1) != 0) {
				// w include is the parent int (p - 'A')
				A[N - 1][i] = b; //set parent to be equal to block #b
				//If rest of pyramid can be built, return true
				//R represents current row, now with ith bit set to b+1
				// in base 8.
				if (solve(A, R * 8 + (b + 1), N, i + 1)) return true;
			}
			return false;
		}
	}

private:
	// we need to encode here
	vector <vector<int>> T; // store the states!
	set<long> seen;

};

/*
This answer makes better sense:
class Solution {
public:
	bool pyramidTransition(string bottom, vector<string>& allowed) {
		T = vector<vector<int>>(26, vector<int>(26, 0)); // bottom at most 8 letters
		for (string a : allowed)
			T[a[0] - 'A'][a[1] - 'A'] |= 1 << (a[2] - 'A'); // in total 26 characters and int has 32 bits (except first bit for sign)
		unordered_set<int> seen;
		int N = bottom.size();
		// A first dim: layer
		vector<vector<int>> A = vector<vector<int>>(N, vector<int>(N, 0));
		int t = 0;
		for (char c : bottom)
			A[N - 1][t++] = c - 'A';
		return solve(A, 0, N - 1, 0);
	}

	//A[i] - the ith row of the pyramid
   //R - integer representing the current row of the pyramid
   //N - length of current row we are calculating
   //i - index of how far in the current row we are calculating
   //Returns true iff pyramid can be built
public:
	bool solve(vector<vector<int>> &A, long R, int N, int i) {
		if (N == 1 && i == 1) { // If successfully placed entire pyramid
			return true;
		}
		else if (i == N) {
			if (seen.count(R)) return false; // If we've already tried this row, give up
			seen.insert(R); // Add row to cache
			return solve(A, 0, N - 1, 0); // Calculate next row
		}
		else {
			// w's jth bit is true iff block #j could be
			// a parent of A[N][i] and A[N][i+1]
			int w = T[A[N][i]][A[N][i + 1]];
			// for each set bit in w...
			for (int b = 0; b < 27; ++b) if (((w >> b) & 1) != 0) {
				A[N - 1][i] = b; //set parent to be equal to block #b
				//If rest of pyramid can be built, return true
				//R represents current row, now with ith bit set to b+1
				// in base 8.
				if (solve(A, R * 27 + (b + 1), N, i + 1)) return true;
			}
			return false;
		}
	}

private:
	// we need to encode here
	vector <vector<int>> T; // store the states!
	set<long> seen;

};
*/