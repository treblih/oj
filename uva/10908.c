/*
 * =====================================================================================
 *
 *       Filename:  10908.c
 *
 *    Description:  Largest Square
 *    		    simulation (how to dp on bitmask?)
 *
 *        Created:  25.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#define	SIZE	128
#define	FORI(i, val, cond)	for ((i) = (val); (cond); ++(i))	
#define	FORIZ(i, cond)		FORI((i), 0, (cond))
#define	FORD(i, val, cond)	for ((i) = (val); (cond); --(i))
#define	FORDZ(i, cond)		FORD((i), 0, (cond))
#define	MAX(a, b)		({__typeof__ (a) ta = (a);\
			  	__typeof__ (b) tb = (b);\
			  	ta > tb ? ta : tb;})
#define	MIN(a, b)		({__typeof__ (a) ta = (a);\
			  	__typeof__ (b) tb = (b);\
			  	ta < tb ? ta : tb;})
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#undef	stdin
	#define stdin			fp
#endif
static FILE *fp;
static char map[SIZE][SIZE];

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, j, cases, center, row, col, pairs, x, y;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d%d%d", &row, &col, &pairs);
		printf("%d %d %d\n", row, col, pairs);
		FORIZ(i, i < row) scanf("%s", map[i]);
		while (pairs--) {
			scanf("%d%d", &y, &x);
			center = map[y][x];
			/* FORI(i, 1, x-i>=0 && x+i<=col && y-i>=0 && y+i<=row) { */
			/* 0~n-1 */
			FORI(i, 1, x-i>=0 && x+i<col && y-i>=0 && y+i<row) {
				/* check 2 cols 2 rows */
				FORI(j, x-i, j <= x+i) {
					if (map[y-i][j] != center) goto done;
					if (map[y+i][j] != center) goto done;
				}
				FORI(j, y-i+1, j <= y+i-1) {
					if (map[j][x-i] != center) goto done;
					if (map[j][x+i] != center) goto done;
				}
			}
			done:
			printf("%d\n", 1 + (--i << 1));	/* i is 1 larger */
		}
	}
	return 0;
}
