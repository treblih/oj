/*
 * =====================================================================================
 *
 *       Filename:  11462.c
 *
 *    Description:  Age Sort 
 *    		    quick sort
 *
 *        Created:  28.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define	SIZE	2000010
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
static int list[SIZE];

int cmpr(const void *a, const void *b) {return *(int *)a - *(int *)b;}
int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, n;
	while (scanf("%d", &n), n) {
		FORIZ(i, i < n) scanf("%d", &list[i]);
		qsort(list, n, sizeof(int), cmpr);
		printf("%d", list[0]);
		FORI(i, 1, i < n) printf(" %d", list[i]);
		putchar('\n');
	}
	return 0;
}
