/*
 * =====================================================================================
 *
 *       Filename:  1658.c
 *
 *    Description:  no algorithm
 *
 *        Created:  26.09.10
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
	int n, i;
	int a, b, c, d;
	int diff1, diff2;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		diff1 = b - a;
		diff2 = c - b;
		if (diff1 == diff2) {
			printf("%d %d %d %d %d\n", a, b, c, d, d + diff1);
		} else {
			printf("%d %d %d %d %d\n", a, b, c, d, d * b / a);
		}
	}
	return 0;
}
