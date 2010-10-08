/*
 * =====================================================================================
 *
 *       Filename:  10004.c
 *
 *    Description:  Bicoloring
 *    		    graph & dfs
 *
 *        Created:  06.10.10
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

#define	SIZE	256
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif

enum {
	FAIL = 1,
	NO_PROBLEM = 0,
	BLACK = -1, 
	WHITE = 1,
};

static FILE *fp;
static int flag, cnt, vertices;
static char color[SIZE];
static char queue[SIZE];
static char graph[SIZE][SIZE];

int dfs(int v)
{
	int i;
	/* i must have my color */
	for (i = 0; i < SIZE; i++) {
		if (!graph[v][i]) continue;
		if (!color[i]) {
			color[i] = 0 - color[v];
			if (dfs(i)) return FAIL;
		}
		else if (color[v] == color[i]) return FAIL;
		/* now v has already been opposite to i */
	}
	return NO_PROBLEM;
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int edges;
	int v1, v2, fst, i;
	while (scanf("%d", &vertices) != EOF && vertices) {
		scanf("%d", &edges);
		if (!edges) {
			scanf("%d", &v1);
			puts("BICOLORABLE.");
			continue;
		}
		/* load all */
		while (edges--) {
			scanf("%d%d", &v1, &v2);
			graph[v1][v2] = graph[v2][v1] = 1;
			if (!flag) {
				fst = v1;
				flag = 1;
			}
		}
		color[fst] = WHITE;
		/* graph[i][i] are always 0 */
		for (i = 0; i < SIZE; i++) {
			if (graph[fst][i]) {
				color[i] = BLACK;
				queue[cnt++] = i;
			}
		}
		for (i = 0; i < cnt; i++) {
			if (dfs(queue[i])) {
				puts("NOT BICOLORABLE.");
				goto end;
			}
		}
		puts("BICOLORABLE.");
end:
		memset(color, 0, SIZE);
		memset(graph, 0, SIZE * SIZE);
		cnt = flag = 0;
	}
	return 0;
}
