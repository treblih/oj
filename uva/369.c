/*
 * =====================================================================================
 *
 *       Filename:  369.c
 *
 *    Description:  Combinations
 *    		    math
 *
 *        Created:  16.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#define	SIZE	100
/* namely, pascal triangle */
static long bc[SIZE][SIZE];

void binomial_coefficient()
{
	int i, j;
	for (i = 0; i <= SIZE; ++i) bc[i][0] = 1;
	for (j = 0; j <= SIZE; ++j) bc[j][j] = 1;
	for (i = 1; i <= SIZE; ++i) {
		for (j = 1; j < i; ++j) {
			bc[i][j] = bc[i - 1][j - 1] + bc[i - 1][j];
		}
	}
}

int main(int argc, const char *argv[])
{
	int n, m;
	binomial_coefficient();
	while (scanf("%d%d", &n, &m), n) {
		printf("%d things taken %d at a time is %ld exactly.\n",
			n, m, bc[n][m]);
	}
	return 0;
}
