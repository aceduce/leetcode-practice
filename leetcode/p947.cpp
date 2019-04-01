#include"Solutions.h"
class p947::Solution {
	// a typical graph questions: 
	// travese with DFS for each components
	// using stack interative method
public:
	int removeStones(vector<vector<int>>& stones) {
		int N = stones.size();
		vector<vector<int>> graph = vector<vector<int>>(N, vector<int> (N, 0));
		for(int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++) {
				// record the list of graph[i][1:]
				if (stones[i][0] == stones[j][0] ||
					stones[i][1] == stones[j][1]) {
					graph[i][++graph[i][0]] = j;
					graph[j][++graph[j][0]] = i;
				}					
			}
		int ans = 0;
		vector<bool> seen(N, false);
		// Real DFS: typical graph dfs code:
		for (int i = 0; i < N; i++) {
			if (!seen[i]) {
				stack<int> stack; // DFS
				stack.push(i);
				seen[i] = true;
				ans--; // make sure we keep one left!
				while (!stack.empty()) {
					int node = stack.top();
					stack.pop();
					ans++;
					for (int k = 1; k <= graph[node][0]; ++k) {
						int neighbor = graph[node][k];
						if (!seen[neighbor]) {
							stack.push(neighbor);
							seen[neighbor] = true;
						}	
					}

				}
			}
		}
		return ans;
	}
};