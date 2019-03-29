#include"Solutions.h"
class p546::Solution {
public:
	long dfs(const vector<int> & boxes, int l, int r, int k) {
		if (l > r) return 0;
		if (m_[l][r][k] > 0)
			return m_[l][r][k];
		m_[l][r][k] = dfs(boxes, l, r - 1, 0) + (k + 1)*(k + 1);
		for (int i = l; i < r; i++) {
			if (boxes[i] == boxes[r])
				m_[l][r][k] = max(m_[l][r][k],
					dfs(boxes, l, i, k + 1) + dfs(boxes, i + 1, r - 1, 0)
				);
		}
		return m_[l][r][k];
	}

	int removeBoxes(vector<int>& boxes) {
		const int n = boxes.size();
		m_ = vector<vector<vector<long>>>(n, vector<vector<long>>(n, vector<long>(n, 0)));
		return dfs(boxes, 0, n - 1, 0);
	}
private:
	vector<vector<vector<long>>> m_;
};


class p546::Solution_Opt2 {
public:
	long dfs(const vector<int> & boxes, int l, int r, int k) {
		if (l > r) return 0;
		if (m_[l][r][k] > 0)
			return m_[l][r][k];
		int rr = r;
		int kk = k;
		while (l < r && boxes[r - 1] == boxes[r]) {
			--r;
			++k;
		}
		m_[l][r][k] = dfs(boxes, l, r - 1, 0) + (k + 1)*(k + 1);
		for (int i = l; i < r; i++) {
			if (boxes[i] == boxes[r])
				m_[l][r][k] = max(m_[l][r][k],
					dfs(boxes, l, i, k + 1) + dfs(boxes, i + 1, r - 1, 0)
				);
		}
		for (int d = 1; d <= r - rr;++d) {
			m_[l][r - d][k + d] = m_[l][r][k];
		}

		return m_[l][r][k];
	}

	int removeBoxes(vector<int>& boxes) {
		const int n = boxes.size();
		m_ = vector<vector<vector<long>>>(n, vector<vector<long>>(n, vector<long>(n, 0)));
		return dfs(boxes, 0, n - 1, 0);
	}
private:
	vector<vector<vector<long>>> m_;
};


class p546::Solution_Opt2 {
public:
	int removeBoxes(vector<int>& boxes) {
		len_ = vector<int>(boxes.size());
		for (int i = 1; i < boxes.size(); ++i)
			if (boxes[i] == boxes[i - 1]) len_[i] = len_[i - 1] + 1;
		return dfs(boxes, 0, boxes.size() - 1, 0);
	}
private:
	unordered_map<int, int> m_;
	vector<int> len_;
	int dfs(const vector<int>& boxes, int l, int r, int k) {
		if (l > r) return 0;
		k += len_[r];
		r -= len_[r];
		int key = (l * 100 + r) * 100 + k;
		auto it = m_.find(key);
		if (it != m_.end()) return it->second;
		int& ans = m_[key];
		ans = dfs(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
		for (int i = l; i < r; ++i)
			if (boxes[i] == boxes[r])
				ans = max(ans, dfs(boxes, l, i, k + 1) + dfs(boxes, i + 1, r - 1, 0));
		return ans;
	}
};