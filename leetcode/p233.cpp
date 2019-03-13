﻿#include"Solutions.h"

/**
   * Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
   For example:
   Given n = 13,
   Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
   10 : 1    个位
   100 : 10  十位
   1000: 100 百位
   例子:
   以算百位上1为例子:   假设百位上是0, 1, 和 >=2 三种情况:
   case 1: n=3141092, a= 31410, b=92. 计算百位上1的个数应该为 3141 *100 次.
   case 2: n=3141192, a= 31411, b=92. 计算百位上1的个数应该为 3141 *100 + (92+1) 次.
   case 3: n=3141592, a= 31415, b=92. 计算百位上1的个数应该为 (3141+1) *100 次.
   http://blog.csdn.net/xudli/article/details/46798619
   time : < O(n)
   space : O(1)
*/
int p233::countDigitOne(int n) {
	return 0;
}