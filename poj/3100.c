/*
 * =====================================================================================
 *
 *       Filename:  3100.c
 *
 *    Description:  Root of the Problem
 *
 *        Created:  30.09.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int powi(int root, int idx)
{
	int i;
	int res = 1;
	for (i = 0; i < idx; i++) {
		res *= root;
	}
	return  res;
}

int main(int argc, const char *argv[])
{
	int a, n, b;
	int i = 0;
	int ref, ref2;

	while (scanf("%d%d", &b, &n) != EOF) {
		if (b == 0 || n == 0) {
			break;
		}
		do {
			ref = abs(powi(i, n) - b);
			ref2 = abs(powi(i + 1, n) - b);
		} while (++i, ref > ref2);
		printf("%d\n", --i);
		i = 0;
	}
	return 0;
}
