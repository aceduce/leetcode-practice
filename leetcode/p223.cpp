#include"Solutions.h"
// Deduct the overlap
class p223::Solution_my {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int length = 0; // from x aixs
		int height = 0; // from y axis
		// [A, C] [E, G]
		vector<int> ord{ A, C, E, G };
		sort(ord.begin(), ord.end());
		if ((ord[1] == G && ord[2] == A) || (ord[1] == C && ord[2] == E)) {
			length = 0;
		}
		else length = ord[2] - ord[1];
		// [B, D] [F, H]
		ord = { B, D, F, H };
		sort(ord.begin(), ord.end());
		if ((ord[1] == D && ord[2] == F) || (ord[1] == H && ord[2] == B)) {
			height = 0;
		}
		else height = ord[2] - ord[1];
		// avoid overflow with subtraction first
		return (D - B) * (C - A) - height * length + (H - F) * (G - E);
	}
};

// this method: the key is shift the first rectangular into the first corner
class p223::Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		//先计算两个矩形的面积，后面再算重合部分的面积减去就可以啦
		int s1 = (C - A)*(D - B);
		int s2 = (G - E)*(H - F);

		// 为了便于理解，我们把坐标中心移动到第一个矩形的左下，所有坐标做平移，此时保证第一个矩形在第一象限
		C -= A;
		D -= B;
		E -= A;
		F -= B;
		G -= A;
		H -= B;
		A = 0;
		B = 0;
		// 在第234象限的部分可以直接不计算了，因为矩阵一只在第一象限
		if (E < 0)E = 0;
		if (F < 0)F = 0;
		if (G < 0)G = 0;
		if (H < 0)H = 0;

		//如果矩2左下角没有落在矩1中则直接无重合
		if (E >= C || F >= D)
			return s1 + s2;

		//左下落在矩1中，则重合部分的左下角就是矩2的左下角
		//右上角是min(g,c) min(d,h)可以画图自己看一下，很容易理解
		return s1 + s2 - (min(G, C) - E)*(min(D, H) - F);
	}
};