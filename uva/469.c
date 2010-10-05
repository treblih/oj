/*
 * =====================================================================================
 *
 *       Filename:  469.c
 *
 *    Description:  Wetlands of Florida
 *    		    flood fill
 *
 *        Created:  05.10.10
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
#include <stdint.h>

/* not <99, waste alot of my time. fuck... */
#define	SIZE		450
#define	ADJACENT	8

/* for the sake of memset(visit...) */
static int ymin, ymax, xmin, xmax;
static int ys, xs, cnt;
static int dy[ADJACENT] = {1, 0, -1, 0, 1, -1, -1, 1};
static int dx[ADJACENT] = {0, 1, 0, -1, 1, 1, -1, -1};
static char graph[SIZE][SIZE];
static char visit[SIZE][SIZE];

void dfs(int y, int x)
{
	/* no visited && 'W' */
	cnt++;
	visit[y][x] = 1;
	if (y < ymin) ymin = y;
	if (y > ymax) ymax = y;
	if (x < xmin) xmin = x;
	if (x > xmax) xmax = x;
	int i;
	for (i = 0; i < ADJACENT; i++) {
		int y_adj = y + dy[i], x_adj = x + dx[i];
		if (graph[y_adj][x_adj] != 'W' ||
		    visit[y_adj][x_adj]        ||
		    y_adj < 0 || x_adj < 0 ||
		    y_adj > ys - 1  || x_adj > xs - 1) {
			continue;
		}
		dfs(y_adj, x_adj);
	}
}

int main(int argc, const char *argv[])
{
	int cases, pairs;
	int y, x, i, j, k, ch;

	scanf("%d", &cases);
	/* the following newline of each set will be eaten by != '\n' */
	while (cases--) {
		while ((ch = getchar()) != 'L' && ch != 'W') ;
		ungetc(ch, stdin);
		/* while (fgets(graph[ys], SIZE, stdin), isdigit(*graph[ys++])) ; */
		while (1) {
			fgets(graph[ys], SIZE, stdin); 
			if (isdigit(*graph[ys++])) break;
		}
		/* now ys is the row of graph, the index of first digit pair */
		pairs = --ys;
		xs = strlen(graph[0]) - 1;	/* including '\n' */
		/* not EOF */
		while (fgets(graph[++pairs], SIZE, stdin) != NULL && 
		      *graph[pairs] != '\n') ;
		pairs -= ys;
		/* end of input, start processing */
		for (i = 0; i < pairs; i++) {
			sscanf(graph[ys + i], "%d%d", &y, &x);
			cnt = ymax = xmax = 0;
			ymin = xmin= INT32_MAX;
			dfs(y - 1, x - 1);
			printf("%d\n", cnt);
			/* memset(visit, 0, ys * SIZE); */
			for (j = ymin; j <= ymax; j++) {
				for (k = xmin; k <= xmax; k++) {
					visit[j][k] = 0;
				}
			}
		}
		ys = xs = 0;
		if (cases) printf("\n");
	}
	return 0;
}
