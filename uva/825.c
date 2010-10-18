/*
 * =====================================================================================
 *
 *       Filename:  825.c
 *
 *    Description:  Walking on the Safe Side
 *    		    dp
 *
 *        Created:  17.10.10
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
#include <stdlib.h>
#include <ctype.h>

#define	SIZE	128

/* larger than */
static unsigned dp[SIZE][SIZE];

void dp_init(int y, int x)
{
	int i, j;
	/* init, default 1 */
	for (i = 1; i <= y; ++i)
		for (j = 1; j <= x; ++j) dp[i][j] = 1;
}

void precalculate(int y, int x)
{
	int i, j;
	for (i = 1; i <= y; ++i) {
		for (j = 1; j <= x; ++j) {
			/* dp[1][0] & dp[0][1] are 0
			 * so make dp[1][1] default */
			if (i == 1 && j == 1) continue;
			if (dp[i][j]) dp[i][j] =  dp[i-1][j] + dp[i][j-1];
		}
	}
}

int main(int argc, const char *argv[])
{
	bool eol, impossible = false;
	int cases, y, x, ys, xs, ch, idx, i;
	char digits[4] = {0};
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d%d", &y, &x);
		dp_init(y, x);
		/* dealing with the inputs */
		for (i = 0; i < y; ++i) {
			eol = false;
			idx = 0;
			scanf("%d", &ys);
			while (ch = getchar()) {
				if (ch == '\n') {
					/* 32'\n', the last number in a line */
					if (idx) {
						eol = true;
						goto process;
					} else break;
				}
				if (isdigit(ch)) digits[idx++] = ch;
				/* namely, at least 1 digit */
				else if (idx) {
				process:
					xs = atoi(digits);
					if (ys == 1 && xs == 1) impossible = true;
					/* remember this */
					memset(digits, 0, 4);
					/* obstacle */
					dp[ys][xs] = 0;
					idx = 0;
					if (eol) break;
				}
			}
		}
		/* although we don't need the special judge for dp[1][1]
		 * but it makes the processing time from 0.012 to 0.008 */
		if (impossible) {
			y = x = 0;
			impossible = false;
			goto end;	/* no need to precalculate */
		}
		precalculate(y, x);
		end:
		printf("%u\n", dp[y][x]);
		if (cases) putchar('\n');
	}
	return 0;
}
