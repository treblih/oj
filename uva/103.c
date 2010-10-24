/*
 * =====================================================================================
 *
 *       Filename:  103.c
 *
 *    Description:  Stacking Boxes
 *    		    dp & lis & bsearch
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
static int boxes[32][10];
static int lis[32];
static int pos[SIZE];
static int n, dms;

int ok(int a[], int b[])
{
	int i;
	FORIZ(i, i < dms) if (a[i] >= b[i]) return 0;
	return 1;
}

int cmpr(const void *a, const void *b) {return *(int *)a - *(int *)b;}
int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, j;
	while (scanf("%d%d", &n, &dms) != EOF) {
		FORI(i, 1, i <= n) {
			FORIZ(j, j < dms) scanf("%d", &boxes[i][j]);
			qsort(boxes[i], dms, sizeof(int), cmpr);
		}
		/* load done */
		lis[1] = input[1], pos[1] = 1;
		FORI(i, 1, i <= idx) {
			/* add bebind */
			if (lis[lis_cnt] < input[i]) {
				lis[++lis_cnt] = input[i];
				pos[i] = lis_cnt;
			}
			/* no need to bsearch */
			else if (lis[lis_cnt] == input[i]) {
				pos[i] = lis_cnt;
			}
			/* find the right position to substitute */
			else {
				p = bsearch(input[i], lis_cnt);
				lis[p] = input[i];
				/* record every elem's position in the LIS list */
				pos[i] = p;
			}
		}
	}
	return 0;
}
