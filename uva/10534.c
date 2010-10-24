/*
 * =====================================================================================
 *
 *       Filename:  10534.c
 *
 *    Description:  Wavio Sequence 
 *    		    dp & lis & bsearch
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
#define	SIZE	10010
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
enum {
	FW,
	BW
};
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#undef	stdin
	#define stdin			fp
#endif
static FILE *fp;
static int input[SIZE];
static int lis[SIZE];
static int fw[SIZE];
static int bw[SIZE];

int bsearch(int wanted, int high)
{
	int low = 1;
	int mid;
	while (low <= high) {
		mid = (low + high) >> 1;
		if (lis[mid] > wanted) high = mid - 1;
		else if (lis[mid] < wanted) low = mid + 1;
		else return mid;
	}
	return low;
}

void lisf(int st, int ed)
{
	int i, wanted, lis_idx = 1, p;
	FORI(i, st, i <= ed) {
		wanted = input[i];
		if (lis[lis_idx] < wanted) {
			lis[++lis_idx] = wanted;
			fw[i] = lis_idx;
		} else {
			p = bsearch(wanted, lis_idx);
			lis[p] = wanted;
			fw[i] = p;
		}
	}
}

void lisb(int st, int ed)
{
	int i, wanted, lis_idx = 1, p;
	FORD(i, st, i >= ed) {
		wanted = input[i];
		if (lis[lis_idx] < wanted) {
			lis[++lis_idx] = wanted;
			bw[i] = lis_idx;
		} else {
			p = bsearch(wanted, lis_idx);
			lis[p] = wanted;
			bw[i] = p;
		}
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int n, i, max;
	while (scanf("%d", &n) != EOF) {
		FORI(i, 1, i <= n) scanf("%d", &input[i]);
		fw[1] = bw[1] = 1;
		lis[1]= input[1];
		lisf(1, n);
		lis[1]= input[n];
		lisb(n, 1);
		max = 0;
		FORI(i, 1, i <= n) max = MAX(max, MIN(fw[i], bw[i]));
		printf("%d\n", (max << 1) - 1);
	}
	return 0;
}
