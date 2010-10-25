/*
 * =====================================================================================
 *
 *       Filename:  11456.c
 *
 *    Description:  Trainsorting
 *    		    linear dp & lds & bsearch
 *
 *        Created:  24.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#define	SIZE	3000
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
static int input[SIZE];
static int lis[SIZE];
static int dp[2][SIZE];
static int n;

int bsearch(int wanted, int high, int direct)
{
	int mid, low = 0;
	while (low <= high) {
		mid = (low + high) >> 1;
		if (lis[mid] > wanted) {
			if (!direct) high = mid - 1;
			else low = mid + 1;
		} else if (wanted > lis[mid]) {
			if (!direct) low = mid + 1;
			else high = mid - 1;
		} else return mid;
	}
	return low;
}

#if 0
/* length of lds is what we want */
int lds_process(int n)
{
	int i, wanted, p;
	int left = n, right = n;
	lds[n] = input[0];
	FORI(i, 1, i < n) {
		wanted = input[i];
		if (lds[right] > wanted) lds[++right] = wanted;
		else if (wanted > lds[left]) lds[--left] = wanted;
		else {
			p = bsearch(wanted, left, right);
			lds[p] = wanted;
		}
	}
	return right - left + 1;
}
#endif

void process(int n, int direct)
{
	int i, idx = 0, wanted, p;
	lis[0] = input[0];
	dp[direct][0] = 1;
	FORI(i, 1, i < n) {
		wanted = input[i];
		if ((lis[idx] < wanted && !direct) || 
		    (lis[idx] > wanted && direct)) {
			lis[++idx] = wanted;
			dp[direct][i] = idx + 1;
		} else {
			p = bsearch(wanted, idx, direct);
			lis[p] = wanted;
			dp[direct][i] = p + 1;
		}
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, cases, max;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d", &n);
		FORD(i, n - 1, i >= 0) scanf("%d", &input[i]);
		process(n, 0);
		process(n, 1);
		max = 0;
		FORIZ(i, i < n) max = MAX(max, dp[0][i] + dp[1][i] - 1);
		printf("%d\n", max);
	}
	return 0;
}
