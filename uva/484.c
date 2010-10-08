/*
 * =====================================================================================
 *
 *       Filename:  484.c
 *
 *    Description:  The Department of Redundancy Department
 *    		    bst(array achievement)
 *
 *        Created:  08.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#if 0
#include <stdio.h>
#include <stdlib.h>

#define	SIZE		1001000

/* max used of the bst */
static int max;
/* index of appearance */
static int cnt = 1;
static struct node {
	int val;
	int frq;
	int idx;
} node[SIZE];

int cmpr(const void *a, const void *b)
{
	return ((struct node *)a)->idx - 
	       ((struct node *)b)->idx;
}
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
	int num, i, val, idx, frq;

	while (scanf("%d", &num) != EOF) {
		i = 1;
		while ((idx = node[i].idx) && (val = node[i].val) != num) {
			if (num < val) i <<= 1;
			else i = (i << 1) + 1;
		}
		/* no exists, insert into */
		if (!idx) {
			node[i].val = num;
			node[i].frq = 1;
			node[i].idx = cnt++;
		/* found */
		} else  node[i].frq++;
		if (i > max) max = i;
	}
	/* for the first dummy node */
	max += 1;
	/* sort by idx */
	qsort(node + 1, max, sizeof(struct node), cmpr);
	for (i = 1; i <= max; i++) {
		if (frq = node[i].frq) 
			printf("%d %d\n", node[i].val, frq);
	}
	return 0;
}
#endif

#include <stdio.h>
#include <stdlib.h>

#define	SIZE		10000

static int cnt;
static struct node {
	int val;
	int frq;
} node[SIZE];

int main(int argc, const char *argv[])
{
	int num, i;
next:
	while (scanf("%d", &num) != EOF) {
		for (i = 0; i < cnt; i++) {
			if (num == node[i].val) {
				node[i].frq++;
				goto next;
			}
		}
		node[i].val = num;
		node[i].frq = 1;
		cnt++;
	}
	for (i = 0; i < cnt; i++) 
		printf("%d %d\n", node[i].val, node[i].frq);
	return 0;
}
