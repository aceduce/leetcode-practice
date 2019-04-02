#include"Solutions.h"
class p240::Solution {
public:
	bool subSearchM(vector<vector<int>> & matrix, int start, const int & target, bool vertical) {
		// find the row with binary search
		// find the column in that row
		int n = matrix.size();
		int m = matrix[0].size();
		int low = start, high = vertical ? n - 1 : m - 1;
		while (low < high - 1) {
			int mid = low + (high - low) / 2;
			if (vertical) {
				if (matrix[mid][start] == target) return true;
				else if (matrix[mid][start] < target) {
					low = mid;
				}
				else if (matrix[mid][start] > target) {
					high = mid;
				}
			}
			else {
				if (matrix[start][mid] == target) return true;
				else if (matrix[start][mid] < target) {
					low = mid;
				}
				else if (matrix[start][mid] > target) {
					high = mid;
				}
			}
		}
		if (vertical && (matrix[low][start] == target || matrix[high][start] == target)) {
			return true;
		}
		else if (!vertical && (matrix[start][low] == target || matrix[start][high] == target)) {
			return true;
		}
		else {
			return false;
		}
	}

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		// loop over the diagonal direction
		int n = matrix.size();
		if (n == 0) return false;
		int m = matrix[0].size();
		if (m == 0) return false;
		int iter = min(m, n);
		for (int i = 0; i < iter; i++) {
			bool row = subSearchM(matrix, i, target, true);
			bool col = subSearchM(matrix, i, target, false);
			if (row || col)
				return true;
		}
		return false;
	}
};

// Divide and Conquer Method
// some how, TLE...
class p240::Solution_DivideConquer {
	// could potentially binary search the 'mid point'
public:
	bool subsearch(int left, int up, int right, int down) {
		if (left > right || up > down) {
			return false;
		}
		else if (target < matrix[up][left] || target > matrix[down][right]) {
			return false;
		}
		int mid = left + (right - left) / 2;
		// unlike binary search, left and right never changes
		int row = up;
		// the final [row][mid] will be > target
		while (row <= down && matrix[row][mid] <= target) {
			if (matrix[row][mid] == target)
				return true;
			row++;
		}
		// important to knwo the row -1 and row/mid - 1; mid
		// matrix[row-1][mid] < target < matrix[row][mid]
		// truly divided into 4 pieces
		return subsearch(left, row, mid - 1, down) || subsearch(mid + 1, up, right, row - 1);
	}

	bool searchMatrix(vector<vector<int>>& ma, int targ) {
		matrix = ma;
		target = targ;
		if (matrix.size() == 0) return false;
		if (matrix[0].size() == 0) return false;
		return subsearch(0, 0, matrix[0].size() - 1, matrix.size() - 1);
	}
private:
	vector<vector<int>> matrix;
	int target;
};

/* much easier version of divide and conquer
class Solution {
public:

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		return searchRect(matrix,target,0,0,matrix.size()-1,matrix[0].size()-1);
	}

	bool searchRect(vector<vector<int>>& matrix, int target,
							   int top, int left, int bottom, int right) {
		//search if the target is inside the rectangular matrix[top:bottom][left:right]
		//each time we discard 1/4 of all elements
		//time complexity O( log(mn)/log(4/3) ) = O(logm + logn)

		if(top>bottom || left>right)
			return false;

		int x = (top+bottom)/2;
		int y = (left+right)/2;
		int center = matrix[x][y];

		if(center > target){
			return
				searchRect(matrix,target,top,left,x-1,right) ||
				searchRect(matrix,target,x,left,bottom,y-1);
		}
		else if(center < target){
			return
				searchRect(matrix,target,x+1,left,bottom,right) ||
				searchRect(matrix,target,top,y+1,x,right);
		}
		else
			return true;
	}
};
*/

// quickest path
class Solution {
public: bool searchMatrix(vector<vector<int>> & matrix, int target) {
		// start our "pointer" in the bottom-left
		int row = matrix.size() - 1;
		int col = 0;

		while (row >= 0 && col < matrix[0].size()) {
			if (matrix[row][col] > target) {
				row--;
			}
			else if (matrix[row][col] < target) {
				col++;
			}
			else { // found it
				return true;
			}
		}

		return false;
	}
};