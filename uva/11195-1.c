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

#define	N	16

static int row, col, cnt, size = 11;
static char used[N];
/* solutions holds every col's row number */
static char solutions[N];

void construct_solutions(int dms, int candidates[], int *n)
{
	int legal, i, j;
	for (i = 0, *n = 0; i < size; ++i) {
		if (used[i]) continue;
		legal = 1;
		/* for the given (row,col) */
		if (abs(dms - col) == abs(i - row)) legal = 0;
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
	if (dms == size) ++cnt;
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
	int range = 11;
#if 0
	for ( ; size != 15; ++size) {
		range = size & 0x1 ? (size >> 1) + 1 : size >> 1;
#endif
		for (row = 0; row < range; ++row) {
			for (col = 0; col < range; ++col) {
				used[row] = 1;
				solutions[col] = row;
				cnt = 0;
				backtrack(0);
				printf("%3d ", cnt);
				memset(used, 0, size);
			}
			putchar('\n');
		}
	/* } */
	return 0;
}
