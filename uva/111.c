/*
 * =====================================================================================
 *
 *       Filename:  111.c
 *
 *    Description:  History Grading
 *    		    dp
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

static int rank[32];
static int ans[32];
/* if 54321 - 12345, it's 1 not 0 */
static int dp[32];
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
	int n, i, j, event, tmp, max;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf("%d", &event);
		/* sorted by rank but event */
		rank[i] = event;
	}
	while (scanf("%d", &event) != EOF) {
		ans[event] = rank[1];
		for (i = 2; i <= n; ++i) {
			scanf("%d", &event);
			ans[event] = rank[i];
		}
		/* load done */
		dp[1] = 1;
		for (i = 2, max = 0; i <= n; ++i) {
			for (j = 1, tmp = 0; j < i; ++j) {
				if (ans[j] < ans[i] && tmp < dp[j]) tmp = dp[j];
			}
			if (max < ++tmp) max = tmp;
			dp[i] = tmp;
		}
		memset(dp, 0, sizeof(dp));
		printf("%d\n", max);
	}
	return 0;
}
