/*
 * =====================================================================================
 *
 *       Filename:  507.c
 *
 *    Description:  Jill Rides Again
 *    		    linear dp & position record
 *		    sum[i]=max{sum[i-1]+a[i],a[i]}
 *
 *        Created:  22.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#define	SIZE	20010

static int part[SIZE];
static int start, end;
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

void max_1d(int cnt)
{
	/* len is for the path length, we need the longest */
	int i, sum = 0, max = 0, len = 0, start_tmp = 1;
	for (i = 1; i < cnt; ++i) {
		if (sum + part[i] < 0) {sum = 0; start_tmp = i + 1;}
		else {
			sum += part[i];
			/* sum > max, no problem
			 * when sum == max, need the longest path */
			if (sum > max || (sum == max && i - start_tmp + 1 > len)) {
				start = start_tmp;
				end = i;
				max = sum;
				len = i - start_tmp + 1;
			}
		}
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int cases, i, route = 0, stops;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d", &stops);
		/* get n-1 */
		for (i = 1; i < stops; ++i) scanf("%d", &part[i]);
		max_1d(stops);
		++route;
		if (!end) printf("Route %d has no nice parts\n", route);
		else printf("The nicest part of route %d is between stops %d and %d\n", 
			    route, start, end + 1);
		end = 0;
	}
	return 0;
}
