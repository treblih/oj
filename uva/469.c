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
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define stdin			fp
#endif

#define	SIZE		128
#define	ADJACENT	8

static FILE *fp;
static int ys, xs, cnt;
static int dy[ADJACENT] = {1, 0, -1, 0, 1, -1, -1, 1};
static int dx[ADJACENT] = {0, 1, 0, -1, 1, 1, -1, -1};
static char tmp[SIZE];
static char graph[SIZE][SIZE];
static char visit[SIZE][SIZE];

void dfs(int y, int x)
{
	/* no visited && 'W' */
	cnt++;
	visit[y][x] = 1;
	int i;
	for (i = 0; i < ADJACENT; i++) {
		int y_adj = y + dy[i], x_adj = x + dx[i];
		if (visit[y_adj][x_adj]        ||
		    graph[y_adj][x_adj] != 'W' ||
		    y_adj == -1 || x_adj == -1 ||
		    y_adj == ys  || x_adj == xs) {
			continue;
		}
		dfs(y_adj, x_adj);
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int cases, pairs;
	int y, x, i, ch;

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
			if (y - 1 > ys || x - 1 > xs) continue;
			if (graph[y - 1][x - 1] != 'W') puts("0");
			else { 
				cnt = 0;
				dfs(y - 1, x - 1);
				printf("%d\n", cnt);
				memset(visit, 0, ys * SIZE);
			}
		}
		ys = xs = 0;
		if (cases) {
			printf("\n");
			memset(graph, 0, ys * SIZE);
		}
	}
	return 0;
}
