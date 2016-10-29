/*
文件名:
描述:

作者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2016-10-13

环境:
*/

#include <stdio.h>

/* Return 1 when any odd bit of x equals 1; 0 otherwise.
Assume w=32. */
int any_odd_one(unsigned x){
	return (x & 0xAAAAAAAA) != 0;
}

#define TEST(a, b) test(a, b, #a, #b)
void test(int, int, char*, char*);

int main(){
	TEST(sizeof(int)<<3, 32);
	TEST(any_odd_one(0), 0);
	TEST(any_odd_one(1), 0);
	TEST(any_odd_one(2), 1);
	TEST(any_odd_one(0x1555), 0);
	TEST(any_odd_one(0x408), 1);
	return 0;
}

void test(int a, int b, char* str_a, char* str_b){
	if(a==b)
		printf("[ OK ] %s == %s: %d\n",  str_a, str_b, a);
	else
		printf("[FAIL] %s == %d, %s == %d\n", str_a, a, str_b, b);
}
