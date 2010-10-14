/*
 * =====================================================================================
 *
 *       Filename:  11085.c
 *
 *    Description:  Back to the 8-Queens
 *    		    backtrack & pruning
 *
 *        Created:  13.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	N	8

static char used[N];
/* solutions holds every col's row number */
static int solutions[N];
static int min, total;
static int arr[N];

void construct_solutions(int dms, int candidates[], int *n)
{
	int legal, i, j;
	for (i = 0, *n = 0; i < N; ++i) {
		if (used[i]) continue;
		legal = 1;
		/* check every ancestor */
		for (j = 0; j < dms; ++j) {
			/* current col - ever col == current row - ever row */
			if (abs(dms - j) == abs(i - solutions[j])) legal = 0;
		}
		if (legal) candidates[(*n)++] = i;
	}
}

void backtrack(int dms)
{
	int ncandidate, i, row;
	int candidates[N];
	if (dms == N && min > total) {
		min = total;
	}
	else {
		construct_solutions(dms, candidates, &ncandidate);
		for (i = 0; i < ncandidate; ++i) {
			row = candidates[i];
			/* pruning 
			 * 0-7 vs. 1-8 */
			if (row != arr[dms] - 1) ++total;
			if (total == min) {--total; continue;}
			solutions[dms] = row;
			used[row] = 1;
			backtrack(dms + 1);
			used[row] = 0;
			/* 0-7 vs. 1-8 */
			if (row != arr[dms] - 1) --total;
		}
	}
}

int main(int argc, const char *argv[])
{
	int cases = 0;
	while (scanf("%d%d%d%d%d%d%d%d", 
		     &arr[0], &arr[1], &arr[2], &arr[3], 
		     &arr[4], &arr[5], &arr[6], &arr[7]) != EOF) {
		/* 7 steps at most */
		min = 7;
		total = 0;
		backtrack(0);
		printf("Case %d: %d\n", ++cases, min);
		memset(used, 0, N);
	}
	return 0;
}
