/*
 * =====================================================================================
 *
 *       Filename:  297.c
 *
 *    Description:  Quadtrees
 *    		    recursion
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
#ifdef DB
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
#endif

#define	PIXELS		1024
#define	SIZE		2048

enum {
	S1,
	S2
};

static int sum;
static char quadtree1[SIZE], quadtree2[SIZE];
static char *s1, *s2;
static FILE *fp;

void traverse_single(int which, int level)
{
	int ch = which ? *s2++ : *s1++;
	if (ch == 'f') {
		sum += (PIXELS >> (level << 1));
	} else if (ch == 'p') {
		traverse_single(which, level + 1);
		traverse_single(which, level + 1);
		traverse_single(which, level + 1);
		traverse_single(which, level + 1);
	}
	/* ignore 'e' */
}

/* level from 0-5 
 * cases ff/fe/fp/ee/ep/pp */
void traverse(int level)
{
	int c1 = *s1++;
	int c2 = *s2++;
	/* ff/fe/fp */
	if (c1 == 'f' || c2 == 'f') {
		sum += (PIXELS >> (level << 1));
		/* fp, p need to skip to it's all children */
		if (c1 == 'p') s1 += 4;
		if (c2 == 'p') s2 += 4;
	/* ee */
	} else if (c1 == 'e' && c2 == 'e') {
	/* ep */
	} else if (c1 == 'e' || c2 == 'e') {
		if (c1 == 'e') {
			traverse_single(S2, level + 1); /* skip to 'p' */
			traverse_single(S2, level + 1);
			traverse_single(S2, level + 1);
			traverse_single(S2, level + 1);
		} else {
			traverse_single(S1, level + 1); /* skip to 'p' */
			traverse_single(S1, level + 1);
			traverse_single(S1, level + 1);
			traverse_single(S1, level + 1);
		}
	/* pp */
	} else {
		traverse(level + 1);
		traverse(level + 1);
		traverse(level + 1);
		traverse(level + 1);
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input.txt", "r");
#endif
	int cases;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%s", quadtree1);
		scanf("%s", quadtree2);
		s1 = quadtree1;
		s2 = quadtree2;
		/* 0 not 1, if the strings get started with f/e 
		 * if both not, the first time involve into traverse(), 
		 * ought to deal with the situation of pp */
		traverse(0);
		printf("There are %d black pixels.\n", sum);
		sum = 0;
	}
	return 0;
}
