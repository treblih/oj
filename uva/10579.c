/*
 * =====================================================================================
 *
 *       Filename:  10579.c
 *
 *    Description:  Fibonacci Numbers
 *    		    bignum
 *
 *        Created:  17.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

typedef struct bignum {
	char arr[1050];
} bignum;

static bignum fibo[5001];

int bignum_add(int idx, int cnt)
{
	int i, digits;
	int cf = 0, total = 0;
	for (i = 0, digits = 0; i < cnt || cf; ++i) {
		total = fibo[idx-1].arr[i] + fibo[idx-2].arr[i] + cf;
		if (total > 9) {cf = 1; total -= 10;}
		else cf = 0;
		fibo[idx].arr[i] = total;
		++digits;
	}
	return digits;
}

void bignum_print(int idx)
{
	char *p;
	p = fibo[idx].arr + 1047;
	while (!*--p) continue;
	while (p >= fibo[idx].arr)
		putchar(*p-- + 0x30);
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, idx;
	int digits = 1;
	fibo[1].arr[0] = 1;
	for (i = 2; i <= 5000; ++i) {
		digits = bignum_add(i, digits);
	}
	while (scanf("%d", &idx) != EOF) {
		if (!idx) {puts("0"); continue;}
		bignum_print(idx);
		putchar('\n');
	}
	return 0;
}
