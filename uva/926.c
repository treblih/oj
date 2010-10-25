/*
 * =====================================================================================
 *
 *       Filename:  926.c
 *
 *    Description:  Walking Around Wisely
 *    		    matrix dp & bitmask
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
#include <string.h>
#define	SIZE	32
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
enum {V = 1, H};
static FILE *fp;
static unsigned long long dp[SIZE][SIZE];
static char obstacle[SIZE][SIZE];

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, j, cases, dms, tmp;
	int xs, xe, xt, ys, ye, yt;
	char direct[2] = {0};
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d%d%d%d%d%d", &dms, &xs, &ys, &xe, &ye, &tmp);
		dp[ys][xs] = 1;
		while (tmp--) {
			scanf("%d%d%s", &xt, &yt, direct);
			switch (direct[0]) {
			case 'N': obstacle[yt][xt]   |= V; break;	/* self */
			case 'S': obstacle[yt-1][xt] |= V; break;	/* up */
			case 'W': obstacle[yt][xt-1] |= H; break;	/* left */
			case 'E': obstacle[yt][xt]   |= H; break;	/* self */
			}
		}
		/* load done */
		/* first row */
		FORI(i, xs + 1, i <= xe)
			dp[ys][i] = obstacle[ys][i-1] & H ? 0 : dp[ys][i-1];
		/* first col */
		FORI(i, ys + 1, i <= ye)
			dp[i][xs] = obstacle[i-1][xs] & V ? 0 : dp[i-1][xs];
		/* fill the table */
		FORI(i, ys + 1, i <= ye) FORI(j, xs + 1, j <= xe) {
			/* horizontal */
			if (!(obstacle[i][j-1] & H)) 
				dp[i][j] += dp[i][j-1];
			/* vertical */
			if (!(obstacle[i-1][j] & V)) 
				dp[i][j] += dp[i-1][j];
		}
		printf("%llu\n", dp[ye][xe]);
		memset(dp, 0, sizeof(dp));
		memset(obstacle, 0, sizeof(obstacle));
	}
	return 0;
}

#if 0
#define	V	0xc000000000000000 	/* 1100 0000 0000 0000 0000 0000 0000 0000 */
#define	H	0xa000000000000000	/* 1010 0000 0000 0000 0000 0000 0000 0000 */
#define V_MASK	0x4000000000000000	/* 0100 0000 0000 0000 0000 0000 0000 0000 */
#define H_MASK	0x2000000000000000	/* 0010 0000 0000 0000 0000 0000 0000 0000 */
#define	MASK	0x1fffffffffffffff	/* 0001 1111 1111 1111 1111 1111 1111 1111 */
static long long dp[SIZE][SIZE];

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, j, cases, dms, tmp;
	int xs, xe, xt, ys, ye, yt;
	char direct[2] = {0};
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d%d%d%d%d%d", &dms, &xs, &ys, &xe, &ye, &tmp);
		dp[ys][xs] = 1;
		while (tmp--) {
			scanf("%d%d%s", &xt, &yt, direct);
			switch (direct[0]) {
			case 'N':
				dp[yt][xt]   |= V; break;
			case 'S':
				dp[yt-1][xt] |= V; break;
			case 'W':
				dp[yt][xt-1] |= H; break;
			case 'E':
				dp[yt][xt]   |= H; break;
			}
		}
		/* load done */
		FORI(i, xs + 1, i <= xe)
			dp[ys][i] += dp[ys][i-1] & H_MASK ? 0 : dp[ys][i-1] & MASK;
		FORI(i, ys + 1, i <= ye)
			dp[i][xs] += dp[i-1][xs] & V_MASK ? 0 : dp[i-1][xs] & MASK;
		FORI(i, ys + 1, i <= ye) FORI(j, xs + 1, j <= xe) {
			if (!(dp[i][j-1] & H_MASK)) 
				dp[i][j] += dp[i][j-1] & MASK;
			if (!(dp[i-1][j] & V_MASK)) 
				dp[i][j] += dp[i-1][j] & MASK;
		}
		printf("%lld\n", dp[ye][xe]);
		/* memset(dp[ys], 0, ((ye - ys + 1) * SIZE) << 2); */
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}
#endif
