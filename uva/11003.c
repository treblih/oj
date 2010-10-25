/*
 * =====================================================================================
 *
 *       Filename:  11003.c
 *
 *    Description:  Boxes
 *    		    matrix dp & lis
 *    		    cpct[i]=min{cpct[i-1]-wght[i], cpct[i]}
 *
 *        Created:  23.10.10
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
#define	SIZE	1024
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
static int wght[SIZE];
static int cpct[SIZE];
static int dp[SIZE][3010];

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, j, cnt, tmp, max, max_cp, level, left_capacity;
	while (scanf("%d", &cnt), cnt) {
		max_cp = 0;
		FORIZ(i, i < cnt) {
			scanf("%d%d", &wght[i], &tmp);
			cpct[i] = tmp;
			dp[i][tmp] = 1;		/* at least can stack itself */
			max_cp = MAX(max_cp, tmp);
		}
		FORI(i, 1, i < cnt) FORI(j, 1, j <= max_cp) {
			/* on a box */
			if ((level = dp[i-1][j]) && j >= wght[i]) {
				left_capacity = MIN(cpct[i], j - wght[i]);
				dp[i][left_capacity] = MAX(dp[i][left_capacity], level + 1);
			}
			/* every time only cmpr with i-1, so inherit */
			dp[i][j] = MAX(dp[i][j], dp[i-1][j]);
		}
		max = 0;
		FORIZ(j, j <= max_cp) max = MAX(max, dp[cnt-1][j]);
		printf("%d\n", max);
		memset(dp, 0, (cnt * 3010) << 2);
	}
	return 0;
}
