/*
 * =====================================================================================
 *
 *       Filename:  280.c
 *
 *    Description:  Vertex
 *    		    directional graph & dfs
 *
 *        Created:  15.10.10
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

#define	SIZE	128

static int cnt;
static char visit[SIZE];
static char inaccessible[SIZE];
static char graph[SIZE][SIZE];
#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
	#define	ungetc(c, stdin)	ungetc(c, fp)
#endif
static FILE *fp;

void dfs(int start)
{
	int i;
	for (i = 1; i <= cnt; ++i) {
		if (graph[start][i]) {
			if (visit[i] == 2) continue;
			else if (visit[i] == 1) visit[i] = 2;
			/* 2 -> 2 */
			if (start != i) dfs(i);
		}
	}
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input", "r");
#endif
	int n, m, start, end, i;
	while (scanf("%d", &cnt) != EOF && cnt) {
		while (scanf("%d", &start), start) {
			while (scanf("%d", &end), end) {
				graph[start][end] = 1;
			}
		}
		for (i = 1; i <= cnt; ++i) visit[i] = 1;
		scanf("%d", &n);
		while (n--) {
			scanf("%d", &start);
			dfs(start);
			/* reset & process simultaneously */
			for (i = 1, m = 0; i <= cnt; ++i) {
				if (visit[i] == 2) visit[i] = 1;
				else if (visit[i] == 1) inaccessible[m++] = i;
			}
			printf("%d", m);
			for (i = 0; i < m; ++i) printf(" %d", inaccessible[i]);
			putchar('\n');
		}
		memset(visit + 1, 0, cnt);
		memset(graph[1], 0,  cnt * SIZE);
	}
	return 0;
}
