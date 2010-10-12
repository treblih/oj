/*
 * =====================================================================================
 *
 *       Filename:  167.c
 *
 *    Description:  The Sultan's Successors
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

#define	N	8

static int max;
static char used[N];
/* solutions holds every col's row number */
static char solutions[N];
static int graph[N][N];

void process_solutions()
{
	int i, total = 0;
	for (i = 0; i < N; ++i) {
		total += graph[solutions[i]][i];
	}
	if (total > max) max = total;
}

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
	if (dms == N) process_solutions();
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
	int cases, i;
	scanf("%d", &cases);
	while (cases--) {
		for (max = 0, i = 0; i < N; ++i) {
			scanf("%d%d%d%d%d%d%d%d", 
				&graph[i][0], &graph[i][1], 
				&graph[i][2], &graph[i][3], 
				&graph[i][4], &graph[i][5], 
				&graph[i][6], &graph[i][7]);
		}
		backtrack(0);
		memset(used, 0, N);
		printf("%5d\n", max);
	}
	return 0;
}
