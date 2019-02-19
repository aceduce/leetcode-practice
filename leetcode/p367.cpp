#include"Solutions.h"
//http://www.cnblogs.com/grandyang/p/5619296.html
// Newton's method
bool p367::isPerfectSquare(int num) {
	long x = num;
	while (x * x > num) {
		x = (x + num / x) / 2;
	}
	return x * x == num;
}

