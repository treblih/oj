/*
 * =====================================================================================
 *
 *       Filename:  441.c
 *
 *    Description:  Lotto
 *    		    backtrack
 *
 *        Created:  20.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>

#define	SIZE	6
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

static int k;
static char used[64];
static int solutions[8];
static int set[16];

void construct_solutions(int dms, int candidates[], int *n)
{
	int tmp, i;
	for (i = 0, *n = 0; i <= k - SIZE; ++i) {
		tmp = set[dms + i];
		/* ascending */
		if (!used[tmp] && tmp > solutions[dms - 1]) candidates[(*n)++] = tmp;
	}
}

void backtrack(int dms)
{
	int i, ncandidate, tmp;
	/* 12, not SIZE */
	int candidates[12];
	if (dms == SIZE) {
		/* print out */
		printf("%d", solutions[0]);
		for (i = 1; i < SIZE; ++i) {
			printf(" %d", solutions[i]);
		}
		putchar('\n');
	}
	else {
		construct_solutions(dms, candidates, &ncandidate);
		for (i = 0; i < ncandidate; ++i) {
			tmp = candidates[i];
			solutions[dms] = tmp;
			used[tmp] = 1;
			backtrack(dms + 1);
			used[tmp] = 0;
		}
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, tmp, fst = 1;
	while (scanf("%d", &k), k) {
		if (fst) fst = 0;
		else putchar('\n');
		/* it's said that ascending */
		for (i = 0; i < k; ++i) scanf("%d", &set[i]);
		for (i = 0; i <= k - 6; ++i) {
			tmp = set[i];
			solutions[0] = tmp;
			used[tmp] = 1;
			backtrack(1);
			used[tmp] = 0;
		}
		memset(used, 0, sizeof(used));
	}
	return 0;
}
