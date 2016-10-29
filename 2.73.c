/*
文件名:
描述:

作者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2016-10-13

环境:
*/


#include <limits.h>

/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y){
	int sum = x + y;

	// underscore indicating most significant bit
	int _ = 1 << ((sizeof(int) << 3) - 1);
	int _x = x & _;
	int _y = y & _;
	int _s = sum & _;

	// check for overflow
	int up = ~_x & ~_y & _s;
	int down = _x & _y & ~_s;

	// simulating if (is this legal?
	up && (sum = ~_);
	down && (sum = _);

	return sum;
}

#include <stdio.h>
#define TEST(a, b) test(a, b, #a, #b)
void test(int a, int b, char* str_a, char* str_b){
	if(a==b)
		printf("[ OK ] %s == %s: %d\n",  str_a, str_b, a);
	else
		printf("[FAIL] %s == %d, %s == %d\n", str_a, a, str_b, b);
}

int main(){
	TEST(saturating_add(0,0),0);
	TEST(saturating_add(20000,3333),23333);
	TEST(saturating_add(99999,-33333),66666);
	TEST(saturating_add(INT_MAX,1),INT_MAX);
	TEST(saturating_add(INT_MAX-233,234),INT_MAX);
	TEST(saturating_add(INT_MAX,INT_MAX),INT_MAX);
	TEST(saturating_add(INT_MIN,-1),INT_MIN);
	TEST(saturating_add(INT_MIN+233,-234),INT_MIN);
	TEST(saturating_add(INT_MIN,INT_MIN),INT_MIN);
	TEST(saturating_add(INT_MIN,INT_MIN),INT_MIN);
	return 0;
}
