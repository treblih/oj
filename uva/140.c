/*
 * =====================================================================================
 *
 *       Filename:  140.c
 *
 *    Description:  Bandwidth
 *    		    backtrack & graph
 *
 *        Created:  09.10.10
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
#include <stdbool.h>
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

#define	SIZE	26
#define	LEN	256

static bool finished;
static int cnt, min;
/* 0 - unused; 1 - shown in str; 2 - used in backtrack */
static char used[SIZE];		/* 26 chars */
/* only use cnt elems */
static char list[SIZE];		/* all used saved here, no search anymore */
static char solution[SIZE];	/* solution permutations */
static char wanted[SIZE];	/* wanted solution */
static char str[LEN];
static bool graph[SIZE][SIZE];

/* dms - dimension */
void process_solution()
{
	int max, i, j;
	for (max = 0, i = 0; i < cnt; ++i) {
		for (j = cnt - 1; j != i; --j) {
			if (graph[solution[i]][solution[j]]) {
				/* pruning */
				if (max < j - i) max = j - i;
				if (max >= cnt - 1 - i) goto out;
			}
		}
	}
out:
	if (min > max) {
		min = max;
		for (i = 0; i < cnt; ++i) wanted[i] = solution[i];
		/* 2 is ideal smallest bandwidth */
		if (min == 2) finished = true;
	}
}

void construct_candidates(int dms, int candidates[], int *n)
{
	int i, j;
	*n = cnt - dms;
	for (i = 0, j = 0; i < cnt; ++i) {
		/* pruning */
		if (used[list[i]] == 1) candidates[j++] = list[i];
	}
}

void backtrack(int dms)
{
	int candidates[SIZE];
	int ncandidate, i;
	if (dms == cnt) process_solution();
	else {
		construct_candidates(dms, candidates, &ncandidate);
		for (i = 0; i < ncandidate; ++i) {
			solution[dms] = candidates[i];
			used[candidates[i]] = 2;	/* set */
			backtrack(dms + 1);
			if (finished) return ;
			used[candidates[i]] = 1;	/* unset */
		}
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int ch1, ch2, i;
	char *token;
#ifdef DB
	while (fgets(str, LEN, fp)) {
#else
	while (fgets(str, LEN, stdin)) {
#endif
		if (str[0] == '#') break;
		/* scan the string */
		for (token = str; (ch1 = *token); ++token) {
			if (token[1] == ':') {
				used[ch1 -= 0x41] = 1;
				for (token += 2; (ch2 = *token) != ';' && ch2 != '\n'; 
				     ++token) {
					used[ch2 -= 0x41] = 1;
					/* ch1 & ch2 are 0-25 now */
					graph[ch1][ch2] = graph[ch2][ch1] = true;
				}
			}
		}
		for (cnt = 0, i = 0; i < SIZE; ++i) if (used[i]) list[cnt++] = i;
		min = cnt;
		backtrack(0);
		for (i = 0; i < cnt; ++i) {
			printf("%c ", wanted[i] + 0x41);
		}
		printf("-> %d\n", min);
		memset(used, 0, SIZE);
		memset(graph, false, SIZE * SIZE);
		finished = false;
	}
	return 0;
}
