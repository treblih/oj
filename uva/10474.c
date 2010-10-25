/*
 * =====================================================================================
 *
 *       Filename:  10474.c
 *
 *    Description:  Where is the Marble
 *    		    qsort & hash
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
#include <stdlib.h>
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
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#undef	stdin
	#define stdin			fp
#endif
static FILE *fp;
static int input[SIZE], hash[SIZE];

int cmpr(const void *a, const void *b) {return *(int *)a - *(int *)b;}
int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, n, q, wanted, cases = 0, max, tmp;
	while (scanf("%d%d", &n, &q), n) {
		printf("CASE# %d:\n", ++cases);
		max = -1;
		FORIZ(i, i < n) {
			scanf("%d", &tmp);
			input[i] = tmp;
			max = MAX(tmp, max);
		}
		qsort(input, n, sizeof(int), cmpr);
		FORIZ(i, i < n) {
			/* i:0~n-1, output:1~n */
			if (!hash[input[i]]) hash[input[i]] = i + 1;
		}
		FORIZ(i, i < q) {
			scanf("%d", &wanted);
			hash[wanted] ? 
				printf("%d found at %d\n", wanted, hash[wanted]) :
				printf("%d not found\n", wanted);
		}
		/* memset(hash, 0, (max + 1) << 2); */
		memset(hash, 0, sizeof(hash));
	}
	return 0;
}
