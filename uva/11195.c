/*
 * =====================================================================================
 *
 *       Filename:  11195.c
 *
 *    Description:  Another n-Queen Problem
 *    		    backtrack
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

#define	N	16

static int total, size;
static char used[N];
/* solutions holds every col's row number */
static char solutions[N];
static char graph[N][N];
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

void construct_solutions(int dms, int candidates[], int *n)
{
	int legal, i, j;
	/* i < size, not N */
	for (i = 0, *n = 0; i < size; ++i) {
		if (used[i]) 	      	  continue;
		if (graph[i][dms] == '*') continue;
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
	if (dms == size) ++total;
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
#ifdef DB
	fp = fopen("input", "r");
#endif
	int cases = 0, i;
	while (scanf("%d", &size) != EOF && size) {
		/* data load & obstacle record */
		for (i = 0; i < size; ++i) scanf("%s", graph[i]);
		backtrack(0);
		printf("Case %d: %d\n", ++cases, total);
		total = 0;
		memset(used, 0, size);
	}
	return 0;
}
