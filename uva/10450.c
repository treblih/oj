/*
 * =====================================================================================
 *
 *       Filename:  10450.c
 *
 *    Description:  World Cup noise
 *    		    fibonacci & dp
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

int main(int argc, const char *argv[])
{
	int i, cases, n;
	long long fibo[64];
	fibo[0] = 1;
	/* 0 / 1 */
	fibo[1] = 2;
	for (i = 2; i <= 60; ++i) fibo[i] = fibo[i - 1] + fibo[i - 2];
	scanf("%d", &cases);
	for (i = 1; i <= cases; ++i) {
		scanf("%d", &n);
		printf("Scenario #%d:\n%lld\n", i, fibo[n]);
		/* if (i != cases) putchar('\n'); */
		putchar('\n');
	}
	return 0;
}
