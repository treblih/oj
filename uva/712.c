/*
 * =====================================================================================
 *
 *       Filename:  712.c
 *
 *    Description:  S-Trees
 *    		    qsort
 *
 *        Created:  03.10.10
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
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
#endif

#define	SIZE	8

/* 000 001 010 011 100 101 110 111, u know the trick
 * nothing about trees */
static char boolean[256];	/* leaves */
static char tmp[SIZE];
static struct vva {
	int idx;
	int val;
} vva[SIZE];
static FILE *fp;

/* sort by idx */
int cmpr(const void *a, const void *b)
{
	return ((struct vva *)a)->idx - 
	       ((struct vva *)b)->idx;
}

int bin2dec(int n)
{
	int i;
	int total = 0;
	for (i = 0; i < n; i++) {
		total += (vva[i].val << (n - i - 1));
	}
	return total;
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input.txt", "r");
#endif
	int n, m, i, j, ch;
	int cases = 0;
	while (scanf("%d", &n) != EOF && n) {
		for (i = 0; i < n; i++) {
			while ((ch = getchar()) != 'x') ;
			/* start from 0 */
			vva[getchar() - 0x30 - 1].idx = i;
		}
		scanf("%s", boolean);
		scanf("%d", &m);
		printf("S-Tree #%d:\n", ++cases);
		for (i = 0; i < m; i++) {
			/* read 010 */
			scanf("%s", tmp);
			for (j = 0; j < n; j++) {
				vva[j].val = tmp[j] - 0x30;
			}
			qsort(vva, n, sizeof(struct vva), cmpr);
			printf("%c", boolean[bin2dec(n)]);
		}
		printf("\n\n");
	}
	return 0;
}
