/*
 * =====================================================================================
 *
 *       Filename:  481.c
 *
 *    Description:  What Goes up 
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
/* 10000 is RE */
#define SIZE	100000
#define	FORI(i, val, cond)	for ((i) = (val); (cond); ++(i))	
#define	FORIZ(i, cond)		FORI((i), 0, (cond))
#define	FORD(i, val, cond)	for ((i) = (val); (cond); --(i))
#define	FORDZ(i, cond)		FORD((i), 0, (cond))
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

static int input[SIZE];
/* LIS is only for the total count */
static int lis[SIZE];
static int pos[SIZE];

int bsearch(int wanted, int high)
{
	int low = 1; 
	int mid;
	while(low <= high) {
		mid = (low + high) >> 1;
		if (lis[mid] < wanted) low = mid + 1;
		else if (lis[mid] > wanted) high = mid - 1;
		else return mid;
	}
	return low;
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, p, tmp;
	int idx = 0, lis_idx = 1;
	while (scanf("%d", &input[++idx]) != EOF) ;
	lis[1] = input[1], pos[1] = 1;
	FORI(i, 1, i <= idx) {
		/* add bebind */
		if (lis[lis_idx] < input[i]) {
			lis[++lis_idx] = input[i];
			pos[i] = lis_idx;
		}
		/* no need to bsearch */
		else if (lis[lis_idx] == input[i]) pos[i] = lis_idx;
		/* find the right position to substitute */
		else {
			p = bsearch(input[i], lis_idx);
			lis[p] = input[i];
			/* record every elem's position in the LIS list */
			pos[i] = p;
		}
	}
	/* count is LIS */
	printf("%d\n-\n", lis_idx);
	tmp = lis_idx;
	while (lis_idx--) {
		while (pos[i] != lis_idx) --i;
		/* indeed we need stack 
		 * but lis is useless, make it useful again */
		lis[lis_idx] = input[i];
	}
	FORI(i, 1, i <= tmp) printf("%d\n", lis[i]);
	return 0;
}
