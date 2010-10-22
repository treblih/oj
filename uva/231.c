/*
 * =====================================================================================
 *
 *       Filename:  231.c
 *
 *    Description:  Testing the CATCHER
 *    		    dp & lds
 *
 *        Created:  21.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#define	SIZE	4096
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

static int height[SIZE];
static int dp[SIZE];

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int tmp, idx, i, j, max, cases = 0;
	dp[0] = 1;
	while (scanf("%d", &tmp), tmp != -1) {
		if (cases) putchar('\n');
		height[idx = 0] = tmp;
		max = 1;
		++cases;
		while (scanf("%d", &tmp), tmp != -1) height[++idx] = tmp;
		for (i = 1; i <= idx; ++i) {
			for (j = 0, tmp = 0; j < i; ++j) {
				if (height[j] >= height[i] && dp[j] > tmp)
					tmp = dp[j];
			}
			++tmp;
			dp[i] = tmp;
			if (max < tmp) max = tmp;
		}
		printf("Test #%d:\n"
  		       "  maximum possible interceptions: %d\n", cases, max);
	}
	return 0;
}
