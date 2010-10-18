/*
 * =====================================================================================
 *
 *       Filename:  10684.c
 *
 *    Description:  The Jackpot
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
/* 12,-4,-8,-2 */

#include <stdio.h>	
#include <stdint.h>
#define	SIZE	10000
static int dp[SIZE];
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, j, n, max, tmp;
	while (scanf("%d", &n), n) {
		max = -INT32_MAX;
		for (i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			if (max < tmp) max = tmp;
			dp[i] = tmp;
			for (j = i - 1; j >= 0; --j) {
				if (max < (dp[j] += tmp)) max = dp[j];
			}
		}
		max > 0 ? printf("The maximum winning streak is %d.\n", max)
			: puts("Losing streak.");
	}
	return 0;
}
