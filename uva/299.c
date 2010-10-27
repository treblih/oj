/*
 * =====================================================================================
 *
 *       Filename:  299.c
 *
 *    Description:  Train Swapping
 *    		    bubble sort
 *
 *        Created:  27.10.10
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
#define	SIZE	64
#define	FORI(i, val, cond)	for ((i) = (val); (cond); ++(i))	
#define	FORIZ(i, cond)		FORI((i), 0, (cond))
#define	FORD(i, val, cond)	for ((i) = (val); (cond); --(i))
#define	FORDZ(i, val)		FORD((i), (val), i >= 0)
#define	MAX(a, b) 	({__typeof__(a) ta=(a); __typeof__(b) tb=(b); ta>tb?ta:tb;})
#define	MIN(a, b)	({__typeof__(a) ta=(a); __typeof__(b) tb=(b); ta<tb?ta:tb;})
#define	SWAP(a, b)	({__typeof__(a) tmp; tmp=(a); (a)=(b); (b)=tmp;})
#define	ZERO(a)		memset((a), 0, sizeof(a))
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#undef	stdin
	#define stdin			fp
#endif
static FILE *fp;

int bubble_sort(int list[], int n)
{
	int i, j, noswap, cnt = 0;
	FORD(i, n - 1, i > 0) {
		noswap = 1;
		FORIZ(j, j < i) {
			if (list[j] > list[j+1]) {
				SWAP(list[j], list[j+1]);
				noswap = 0;
				++cnt;
			}
		}
		if (noswap) break;
	}
	return cnt;
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, cases, l;
	int train[SIZE];
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d", &l);
		FORIZ(i, i < l) scanf("%d", &train[i]);
		printf("Optimal train swapping takes %d swaps.\n",
			bubble_sort(train, l));
	}
	return 0;
}
