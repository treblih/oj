/*
 * =====================================================================================
 *
 *       Filename:  10285.c
 *
 *    Description:  Longest Run on a Snowboard
 *    		    dp & recursion
 *
 *        Created:  19.10.10
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

#define	SIZE	128

static int row, col;
/* adjacent direction */
static char dy[4] = {-1, 0, 1, 0};
static char dx[4] = {0, 1, 0, -1};
/* matrix of hights */
static int hight[100][SIZE];
/* matrix of states */
static int dp[100][SIZE];
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

int run(int y, int x)
{
	int acc, i;
	int ys, xs;
	int tmp = dp[y][x];
	if (tmp) return tmp;
	/* now tmp & dp[y][x] must be 0 */
	/* find the largest of the adjacent, 
	 * record in tmp */
	for (i = 0; i < 4; ++i) {
		ys = y + dy[i]; xs = x + dx[i];
		if (hight[y][x] >= hight[ys][xs] || ys < 0 || ys >= row 
				                 || xs < 0 || xs >= col) continue;
		else {
			acc = run(ys, xs);
			if (tmp < acc) tmp = acc;
		}
	}
	/* at least dp[y][x] would be 1, for the peak */
	return dp[y][x] = ++tmp;
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int cases, i, j, max, acc;
	char name[32];
	scanf("%d", &cases);
	while (cases--) {
		scanf("%s%d%d", name, &row, &col);
		for (i = 0; i < row; ++i) {
			for (j = 0; j < col; ++j) {
				scanf("%d", &hight[i][j]);
			}
		}
		/* load done */
		for (i = 0, max = 0; i < row; ++i) {
			for (j = 0; j < col; ++j) {
				acc = run(i, j);
				if (max < acc) max = acc;
			}
		}
		printf("%s: %d\n", name, max);
		if (cases) memset(dp, 0, (row * SIZE) << 2);
	}
	return 0;
}
