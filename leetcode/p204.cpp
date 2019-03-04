#include"Solutions.h"

// use a unique method
// use space to reduce time!
// https://www.youtube.com/watch?v=Kwo2jkHOyPY
int p204::countPrimes(int n) {
	vector<unsigned char> f(n, 1);
	// 1 means it's prime number
	f[0] = f[1] = 0; // 0 and 1 are not prime
	for (long i = 3; i <= sqrt(n); i++) {
		if (!f[i]) continue; // non-prime, continue;
		// erase mutiple (from squre up )
		for (long j = i * i; j < n; j += i) {
			f[j] = 0;
		}
	}
	return accumulate(f.begin(), f.end(), 0);
}

void p204::test() {

}