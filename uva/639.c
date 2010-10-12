/*
 * =====================================================================================
 *
 *       Filename:  639.c
 *
 *    Description:  Don't Get Rooked
 *
 *        Created:  12.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#define	N	8

static int max;
static char graph[N][N];

int main(int argc, const char *argv[])
{
	int n;
	while (scanf("%d", &n) != EOF && n) {
		for (i = 0; i < n; ++i) {
			/* start from (1,1) */
			scanf("%s", graph[i][1]);
		}
		backtrack(0);
		max = 0;
		printf("%d\n", max);
	}
