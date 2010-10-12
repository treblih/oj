/*
 * =====================================================================================
 *
 *       Filename:  750.c
 *
 *    Description:  8 Queens Chess Problem
 *    		    backtrack
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
#include <stdlib.h>
#include <string.h>

#define	N	9

static int row, col, cnt;
static char used[N];
/* solutions holds every col's row number */
static char solutions[N];

void process_solutions()
{
	int i;
	printf("%2d     ", cnt++);
	for (i = 1; i < N; ++i) {
		printf(" %d", solutions[i]);
	}
	putchar('\n');
}

void construct_solutions(int dms, int candidates[], int *n)
{
	int legal, i, j;
	for (i = 1, *n = 0; i < N; ++i) {
		if (used[i]) continue;
		legal = 1;
		/* for the given (row,col) */
		if (abs(dms - col) == abs(i - row)) legal = 0;
		/* check every ancestor */
		for (j = 1; j < dms; ++j) {
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
	if (dms == N) process_solutions();
	else if (dms == col) backtrack(dms + 1);
	else {
		construct_solutions(dms, candidates, &ncandidate);
		for (i = 0; i < ncandidate; ++i) {
			row = candidates[i];
			solutions[dms] = row;
			used[row] = 1;
			backtrack(dms + 1);
			used[row] = 0;
		}
	}
}

int main(int argc, const char *argv[])
{
	int cases;
	scanf("%d", &cases);
	while (cases--) {
		puts("SOLN       COLUMN");
		puts(" #      1 2 3 4 5 6 7 8\n");
		scanf("%d%d", &row, &col);
		used[row] = 1;
		solutions[col] = row;
		cnt = 1;
		/* 1-8, not 0-7 */
		backtrack(1);
		memset(used, 0, N);
		if (cases) putchar('\n');
	}
	return 0;
}
