/*
 * =====================================================================================
 *
 *       Filename:  11084.c
 *
 *    Description:  Anagram Division
 *    		    backtrack
 *
 *        Created:  13.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * from fh:
 * the first thing i did was next_permutation(), but TLE 
 * the second is using dp[mask][rem] with memo map<int,int>, but TLE 
 * the third is i changed the map<int,int> to int memo[1024*10000], but MLE 
 * the fourth is partial memoization (is that what we call it?) so i only memoized up to 1000000
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	LEN	16
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

static int divisor, cnt, cnt_unique, total;
static char solutions[LEN];
static char used[LEN];
static char list[LEN];

void process_solutions()
{
	solutions[cnt] = '\0';
	if (!(atoll(solutions) % divisor)) ++total;
}

void construct_solutions(int dms, int candidates[], int *n)
{
	int i;
	for (i = 0, *n = 0; i < cnt_unique; ++i) {
		if (used[list[i]]) candidates[(*n)++] = list[i];
	}
}

void backtrack(int dms)
{
	int i, ncandidate, tmp;
	int candidates[LEN];
	if (dms == cnt) process_solutions();
	else {
		construct_solutions(dms, candidates, &ncandidate);
		for (i = 0; i < ncandidate; ++i) {
			tmp = candidates[i];
			/* if (!dms && !tmp) continue; */
			/* num -> str */
			solutions[dms] = tmp + 0x30;
			--used[tmp];
			backtrack(dms + 1);
			++used[tmp];
		}
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int cases, i;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%s%d", solutions, &divisor);
		for (i = 0, cnt = 0; solutions[i]; ++i) {
			++used[solutions[i] - 0x30];
			++cnt;
		}
		for (i = 0, cnt_unique = 0; i < LEN; ++i) {
			if (used[i]) list[cnt_unique++] = i;
		}
		backtrack(0);
		printf("%d\n", total);
		total = 0;
		memset(used, 0, LEN);
	}
	return 0;
}
