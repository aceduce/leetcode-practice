#include"Solutions.h"
uint32_t p190::reverseBits_naive(uint32_t n) {
	int res = 0;
	for (int i = 0; i < 32; i++, n>>1) {
		res = res << 1 | (n & 1);
	}
	return res;
}

// two order reversion: reverse by Byte and reverse by bits
// with chunking-like method
uint32_t p190::reverseBits(uint32_t n) {
	// put 4 bits together 
	char tb[16] = { 0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15 };
	int ret = 0;
	int mask = 0xF;
	int cur = 0;
	for (int i = 0; i < 8; i++) {
		ret = ret << 4;
		cur = tb[n & mask];
		ret = ret | cur; // set the last four digits
		n = n >> 4;
	}
	return ret;
}

void p190::test() {
	cout << reverseBits_naive(1) << endl;
}