#include"Solutions.h"

// need to find the dimension of the matrix first
// use four paramters to 'PIN' the matrix
// only two caes there: left null or left with just one element
vector<vector<int>> p59::generateMatrix(int n) {
	vector <vector<int>> ans(n, vector<int>(n, 0));
	int top = 0, left = 0, right = n - 1, bottom = n - 1;
	int num = 0;
	while (top < bottom && left < right) { // left inclusive, right exclusive
		for (int i = left; i < right; i++) ans[top][i] = ++num;
		for (int i = top; i < bottom; i++) ans[i][right] = ++num;
		for (int i = right; i > left; i--) ans[bottom][i] = ++num;
		for (int i = bottom; i > top; i--) ans[i][left] = ++num;
		top++;
		bottom--;
		left++;
		right--;
	}
	if (n % 2 == 1) {
		ans[n / 2][n / 2] = ++num;
	}
	return ans;
}


void p59::test() {
	vector<vector<int>> ans = generateMatrix(3);
	//vector<vector<int>> matrix2;
	for (vector<vector<int>>::iterator i = ans.begin(); i != ans.end(); i++) {
		cout << " [ ";
		for (int j = 0; j < (*i).size(); j++) {
			cout << (*i)[j] << " ";
		}
		cout << " ] " << endl;
	}
		
	cout << endl;

}