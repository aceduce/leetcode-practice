#include"Solutions.h"

// basically brutal force
// a bit tricky on getting the slope

// get slope:
int p149::gcd(int m, int n) {
	return n == 0 ? m : gcd(n, m%n);
}

pair<int, int> p149::Slope(const Point & p1, const Point & p2) {
	const int dx = p2.x - p1.x;
	const int dy = p2.y - p1.y;
	if (dy == 0) return { p1.y, 0 };
	if (dx == 0) return { 0, p1.x };

	const int d = gcd(dx, dy);
	return { dy / d, dx / d };
}



int p149::maxPoints(vector<Point>& points) {
	// used a map structure {x, y} : 
	int n = points.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		const Point & p1 = points[i];
		int dup = 1, sump = 0; //dup start with 1 not zero!!!
		map<pair<int, int>, int > count; // map store dx, dy & frequencies
		for (int j = i + 1; j < n; j++) {
			const Point &p2 = points[j];
			
			if (p1.x == p2.x && p1.y == p2.y) dup++;
			else
				sump = max(sump, ++count[Slope(p1, p2)]); // local maximum
		}
		ans = max(ans, dup + sump);
	}
	return ans;
}

void p149::test() {

}