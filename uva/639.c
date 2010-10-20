/*
 * =====================================================================================
 *
 *       Filename:  639.c
 *
 *    Description:  Don't Get Rooked
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
#include <stdbool.h>

#define	SIZE	4
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

static bool used_y[SIZE];
static bool used_x[SIZE];
static char graph[SIZE][SIZE];
static int max;
static int len;

void construct_solutions(int y, int x, int candidates[], int *nc)
{
	*nc = 1;
	if (!used_y[y] && !used_x[x]) {
		candidates[0] = '*';
		candidates[1] = '.';
		*nc = 2;
	} else candidates[0] = '.';
}

void process_solutions()
{
	int i, j, cnt = 0;
	for (i = 0; i < len; ++i) {
		for (j = 0; j < len; ++j) {
			if (graph[i][j] == '*') cnt++;
		}
	}
	if (max < cnt) max = cnt;
}

void backtrack(int y, int x)
{
	int i, ncandidate, tmp;
	int candidates[2];
	/* (1, len), 1 unit exceed */
	if (y == len && !x) process_solutions();
	else if (graph[y][x] == 'X') {
		used_y[y] = false;
		used_x[x] = false;
		if (x == len - 1) backtrack(y + 1, 0);
		else backtrack(y, x + 1);
	} else {
		construct_solutions(y, x, candidates, &ncandidate);
		for (i = 0; i < ncandidate; ++i) {
			tmp = candidates[i];
			graph[y][x] = tmp;
			/* rook */
			if (tmp == '*') used_y[y] = used_x[x] = true;
			if (x == len - 1) backtrack(y + 1, 0);
			else backtrack(y, x + 1);
			if (tmp == '*') used_y[y] = used_x[x] = false;
		}
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i;
	while (scanf("%d", &len), len) {
		/* gcc -O2 bugs
		 * if don't use len before the next scanf()
		 * len will be changed to 0 in _IO_vfscanf() */
		len = len;
		for (i = 0; i < len; ++i) scanf("%s", graph[i]);
		backtrack(0, 0);
		printf("%d\n", max);
		max = 0;
		memset(used_y, false, SIZE);
		memset(used_x, false, SIZE);
	}
	return 0;
}
