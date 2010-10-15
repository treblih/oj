/*
 * =====================================================================================
 *
 *       Filename:  216.c
 *
 *    Description:  Getting in Line 
 *    		    graph & backtrack or TSP
 *
 *        Created:  12.10.10
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
#include <math.h>
#include <float.h>
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

#define	SIZE	8

static int npoint;
static double min, total;
static char used[SIZE];
static char solutions[SIZE];
static char wanted[SIZE];
static double graph[SIZE][SIZE];
static struct vertex {
	int x;
	int y;
} vertex[SIZE];

void process_solutions()
{
	int i;
	/* n vertices, n-1 edges */
	for (total = 0.0, i = 0; i < npoint - 1; ++i) {
		total += graph[solutions[i]][solutions[i + 1]];
		/* pruning */
		/* if (total - min < 1e-4) return ; */
		if (total >= min) return ;
	}
	if (min > total) {
		min = total;
		/* for (i = 0; i < npoint; ++i) wanted[i] = solutions[i]; */
		memcpy(wanted, solutions, npoint);
	}
}

void construct_solutions(int dms, int candidates[], int *n)
{
	int i;
	for (i = 0, *n = 0; i < npoint; ++i) {
		if (!used[i]) candidates[(*n)++] = i;
	}
}

void backtrack(int dms)
{
	int i, ncandidate, tmp;
	int candidates[SIZE];
	if (dms == npoint) process_solutions();
	else {
		construct_solutions(dms, candidates, &ncandidate);
		for (i = 0; i < ncandidate; ++i) {
			tmp = candidates[i];
			solutions[dms] = tmp;
			used[tmp] = 1;
			backtrack(dms + 1);
			used[tmp] = 0;
		}
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int i, j, xs, ys, xd, yd, cases = 0;
	int idx, next;
	while (scanf("%d", &npoint) != EOF && npoint) {
		/* load all points to vertex[] */
		for (i = 0; i < npoint; ++i) {
			scanf("%d%d", &vertex[i].x, &vertex[i].y);
		}
		/* put all distances to graph[][] */
		for (i = 0; i < npoint; ++i) {
			xs = vertex[i].x;
			ys = vertex[i].y;
			for (j = 0; j < npoint; ++j) {
				if (i == j) continue;
				xd = xs - vertex[j].x;
				yd = ys - vertex[j].y;
				graph[i][j] = graph[j][i] = sqrt(xd * xd + yd * yd) + 16;
			}
		}
		min = DBL_MAX;
		memset(used, 0, npoint);
		backtrack(0);
		puts("**********************************************************");
		printf("Network #%d\n", ++cases);
		for (i = 0; i < npoint - 1; ++i) {
			idx = wanted[i];
			next = wanted[i + 1];
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",
			       vertex[idx].x, vertex[idx].y, vertex[next].x, vertex[next].y,
			       graph[idx][next]);
		}
		printf("Number of feet of cable required is %.2f.\n", min);
	}
	return 0;
}

for (...; ...; )
	graph[solutions[i]][solutions[i++]];
