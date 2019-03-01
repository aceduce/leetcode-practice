#include"Solutions.h"
// one shot -DFS
void p733::dfs(vector<vector<int>> & img, int sr, int sc, const int &old, const int &n_colr) {
	int n = img.size();
	if (n == 0) return;
	int m = img[0].size();
	if (sr < 0 || sr >= n || sc < 0 || sc >= m || img[sr][sc] != old) return;
	img[sr][sc] = n_colr;
	dfs(img, sr + 1, sc, old, n_colr);
	dfs(img, sr , sc + 1, old, n_colr);
	dfs(img, sr - 1, sc, old, n_colr);
	dfs(img, sr , sc - 1, old, n_colr);
}

vector<vector<int>> p733::floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	int n = image.size();
	if (n == 0) return { {} };
	int m = image[0].size();
	int o_color = image[sr][sc];	
	if (o_color == newColor) return image; 
	//If newColor is the same as color, after visiting a neighbour point of a starting point, 
	//The DFS function would visit the starting point again and this loop never stops.
	// then stack overflow
	dfs(image, sr, sc, o_color, newColor);
	return image;
}

void p733::test() {
	vector<vector<int>> input{ {0,0,0},{0,1,1} };
	vector<vector<int>> ans = floodFill(input, 1, 1, 2);
}